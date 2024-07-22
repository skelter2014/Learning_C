#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h> //for strerror()
#include <sys/errno.h> //for errno

int main(void){
    FILE* inputFile;
    FILE* outputFile;

    char inputFilename[] = "./input.data";
    char outputFilename[] = "./output.data";

    inputFile = fopen(inputFilename, "r");
    if (NULL  == inputFile){
        fprintf(stderr, "input file: %s: %s\n", inputFilename, strerror(errno));

        exit(1);
    }

    outputFile = fopen(outputFilename, "w");
    if (NULL  == outputFile){
        fprintf(stderr, "output file: %s: %s\n", inputFilename, strerror(errno));

        exit(1);
    }

    fprintf(stderr, "\"%s\" opened for reading. \n", inputFilename);
    fprintf(stderr, "\"%s\" opened for writing. \n", outputFilename);
    fprintf(stderr, "Do work here.\n");

    fprintf(stdout, "Closing files.\n");
    fclose(inputFile);
    fflush(outputFile);
    fclose(outputFile);
}