#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h> // For usleep() on Linux, equivalent to Sleep() on Windows

// A 16-byte array of data to send
const uint8_t data_to_send[] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10
};

// Start and End byte markers as used in the Arduino sketch
const char START_BYTE = 'S';
const char END_BYTE = 'E';

// Serial port settings (Baud rate is set by the OS)
#define BAUD_RATE 57600

#ifdef _WIN32
#include <windows.h>
#define SERIAL_PORT "COM3" // Change this to your COM port
#else
#define SERIAL_PORT "/dev/ttyUSB0" // Change this to your serial device
#endif

int main() {
    FILE *serial_port;

    // Open the serial port file
    serial_port = fopen(SERIAL_PORT, "wb");
    if (serial_port == NULL) {
        perror("Error opening serial port");
        return 1;
    }

    // Set a small delay to ensure the Arduino is ready
    #ifdef _WIN32
    Sleep(2000); // 2-second delay for Windows
    #else
    usleep(2000000); // 2-second delay for Linux
    #endif

    printf("Sending data to Arduino via serial port %s...\n", SERIAL_PORT);

    // Write the START byte
    fputc(START_BYTE, serial_port);
    fflush(serial_port); // Flush the buffer immediately

    // Write the 16 bytes of data from the array
    fwrite(data_to_send, sizeof(uint8_t), 16, serial_port);
    fflush(serial_port);

    // Write the END byte
    fputc(END_BYTE, serial_port);
    fflush(serial_port);

    printf("Data sent successfully. Closing port.\n");

    fclose(serial_port);
    return 0;
}
