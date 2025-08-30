//**INCLUDE Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for getopt
#include <sys/errno.h> // for errno
#include <ctype.h>
#include "nameList.h"

//**CONST declarations
const int stringMax = 80;
//**struc and enums

#if TEST_CODE
    fprintf(stdout, "Test code");

#endif

//**function prototypes
void usage(char* cmd);
int getName(FILE* inFileDesc, char* pStr);
void putName(char* nameStr, FILE* outFileDesc);
int trimStr(char* pString);

//**main function
int main(int argc, char* argv[]) {
    int ch;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;

    // Parse command-line arguments
    while ((ch = getopt(argc, argv, "i:o:h")) != -1) {
        switch (ch) {
            case 'i':
                if (NULL == (inputFile = fopen(optarg, "r"))) {
                    fprintf(stderr, "input file \"%s\": %s\n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stderr, "Using \"%s\" for input.\n", optarg);
                break;
            case 'o':
                if (NULL == (outputFile = fopen(optarg, "w"))) {
                    fprintf(stderr, "output file \"%s\": %s\n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stdout, "Using \"%s\" for output.\n", optarg);
                break;
            case '?':
            case 'h':
            default:
                usage(argv[0]);
                break;
        }
    }

    // Default to stdin and stdout if no files are provided
    if (!inputFile) {
        inputFile = stdin;
        fprintf(stdout, "Using stdin for input.\n");
    }
    if (!outputFile) {
        outputFile = stdout;
        fprintf(stdout, "Using stdout for output.\n");
    }

    // Process names
    char nameBuffer[stringMax];
    NameList nameList = { 0 };
    while (getName(inputFile, nameBuffer)) {
        AddName(&nameList, nameBuffer);
    }
    PrintNames(outputFile, &nameList);
    DeleteNames(&nameList);

    // Close files
    fprintf(stdout, "Closing files.\n");
    fclose(inputFile);
    fflush(outputFile);
    fclose(outputFile);
}

//**function definitions

// Display usage information
void usage(char* cmd) {
    fprintf(stderr, "usage: %s [-i inputFName] [-o outputFName]\n", cmd);
    fprintf(stderr, " if -i inputFName is not given stdin is used.\n");
    fprintf(stderr, " if -o outputFName is not given stdout is used.\n\n");
    exit(EXIT_FAILURE);
}

// Trim leading and trailing whitespace from a string
int trimStr(char* pStr) {
    size_t first, last, lenIn, lenOut;
    first = last = lenIn = lenOut = 0;

    lenIn = strlen(pStr);
    char tmpStr[lenIn + 1]; // create a working copy
    strcpy(tmpStr, pStr);
    char* pTmp = tmpStr; // pTmp may change in left trim

    // Left Trim
    // Find 1st non-whitespace char. pStr will point to that
    while (isspace(pTmp[first])) { first++; }
    pTmp += first;
    lenOut = strlen(pTmp);

    if (lenOut) { // only trim right if len > 0
        // Right Trim
        // Find 1st non-whitespace char and set NUL char there
        last = lenOut - 1;
        while (isspace(pTmp[last])) { last--; }
        pTmp[last + 1] = '\0';

        lenOut = strlen(pTmp);
        if (lenIn != lenOut) { // did anything change?
            strcpy(pStr, pTmp); // yes. copy trimmed string back to pStr (passed in by ref)
        }
    }
    return lenOut;
}

// Get a name from the input file
int getName(FILE* inFileDesc, char* pStr) {
    static int numNames = 0;
    int len;

    memset(pStr, 0, stringMax);
    if (stdin == inFileDesc) {
        fprintf(stdout, "Name %d: ", numNames + 1);
    }
    fgets(pStr, stringMax, inFileDesc);
    len = trimStr(pStr);
    if (len) numNames++;
    return len;
}

// Write a name to the output file
void putName(char* pStr, FILE* outFileDesc) {
    fputs(pStr, outFileDesc);
    fputc('\n', outFileDesc);
}