#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <windows.h>

#define BUFFER_SIZE 16
#define SERIAL_PORT "\\\\.\\COM5" // Change this to your COM port

// Protocol constants
const char START_BYTE = 'S';
const char END_BYTE = 'E';
const char ESCAPE_BYTE = 'X';

// Data that might contain control characters
const uint8_t data_to_send[] = {
    0x01, 0x02, 0x03, 0x53, 0x05, 0x06, 0x07, 0x08,
    0x09, 0xaA, 0xab, 0xbC, 0xdD, 0x58, 0x45, 0x10
};

// Function to escape and send a buffer of data
void write_escaped_chunk(HANDLE hSerial, uint32_t address, const uint8_t* buffer, int len) {
    DWORD bytesWritten;
    
    // Send START byte
    WriteFile(hSerial, &START_BYTE, 1, &bytesWritten, NULL);
    Sleep(50);

    // Send address
    WriteFile(hSerial, &address, 4, &bytesWritten, NULL);
    Sleep(50);

    // Send data payload with escaping
    for (int i = 0; i < len; i++) {
        if (buffer[i] == START_BYTE || buffer[i] == END_BYTE || buffer[i] == ESCAPE_BYTE) {
            WriteFile(hSerial, &ESCAPE_BYTE, 1, &bytesWritten, NULL);
            WriteFile(hSerial, &buffer[i], 1, &bytesWritten, NULL);
        } else {
            WriteFile(hSerial, &buffer[i], 1, &bytesWritten, NULL);
        }
    }
    Sleep(50);
    // Send END byte
    WriteFile(hSerial, &END_BYTE, 1, &bytesWritten, NULL);
}

int main() {
    HANDLE hSerial;
    DWORD bytesRead;
    BOOL status;

    printf("Opening serial port %s...\n", SERIAL_PORT);

    // Open the serial port
    hSerial = CreateFile(
        SERIAL_PORT,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hSerial == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            fprintf(stderr, "Error: Serial port not found.\n");
        } else {
            fprintf(stderr, "Error opening serial port. Error code: %lu\n", GetLastError());
        }
        return 1;
    }

    // Set port parameters
    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error getting current serial port state.\n");
        CloseHandle(hSerial);
        return 1;
    }
    dcbSerialParams.BaudRate = 57600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.Parity = NOPARITY;
    dcbSerialParams.StopBits = ONESTOPBIT;
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error setting serial port state.\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Set timeouts
    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        fprintf(stderr, "Error setting serial port timeouts.\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Wait for the Arduino to be ready
    printf("Waiting for Arduino to become ready...\n");
    Sleep(3000); // Give extra time for reset and initial boot

    // Define the starting address
    uint32_t start_address = 0x0000110; // For example, address 16

    // Send the data
    printf("Sending data to Arduino at address 0x%08X (escaped protocol)...\n", start_address);
    write_escaped_chunk(hSerial, start_address, data_to_send, sizeof(data_to_send));
    
    printf("Data sent. Now listening for Arduino output...\n");

    // Read and print Arduino output
    char readBuffer[256];
    char fullMessage[1024]; // Larger buffer for complete message
    fullMessage[0] = '\0';
    
    while (strstr(fullMessage, "Write complete.") == NULL) {
        status = ReadFile(hSerial, readBuffer, sizeof(readBuffer) - 1, &bytesRead, NULL);
        if (status && bytesRead > 0) {
            readBuffer[bytesRead] = '\0';
            printf("%s", readBuffer);
            fflush(stdout); // Immediately print the output
            
            strncat(fullMessage, readBuffer, bytesRead);
            if (strlen(fullMessage) >= sizeof(fullMessage) - 1) {
                // Prevent buffer overflow by shifting content
                memmove(fullMessage, fullMessage + bytesRead, sizeof(fullMessage) - bytesRead);
                fullMessage[sizeof(fullMessage) - bytesRead - 1] = '\0';
            }
        } else if (GetLastError() != ERROR_SUCCESS && GetLastError() != ERROR_IO_PENDING) {
            fprintf(stderr, "\nError reading from serial port. Error code: %lu\n", GetLastError());
            break;
        }
        
        Sleep(10);
    }

    CloseHandle(hSerial);
    return 0;
}
