#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for getopt
#include <getopt.h>
#include <sys/errno.h> //for errno

void usage(char* cmd)
{
    fprintf(stderr, "usage: %s [-i inputFName] [-o outputFName]\n", cmd);
    fprintf(stderr, " if -i inputFName is not given stdin is used.\n");
    fprintf(stderr, " if -o outputFname is not given stdout is used.\n\n");

    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
    int ch;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;

    while ((ch = getopt(argc, argv, "i:o:h")) != -1) {
        switch (ch) {
            case 'i':
                if (NULL == (inputFile = fopen(optarg, "r"))) {
                    fprintf(stderr, "input file\"%s\": %s\n", optarg, strerror(errno));
                    exit(EXIT_FAILURE);
                }
                fprintf(stderr, "Using \"%s\" for input. \n", optarg);
                break;
            case 'o':
                if (NULL == (outputFile = fopen(optarg, "a"))){
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
    if ( !inputFile ){
        inputFile = stdin;
        fprintf(stdout, "Using stdin for input.\n");
    }
    if (!outputFile ){
        outputFile = stdin;
        fprintf(stdout, "Using stdout for input.\n");
    }
    fprintf(stdout, "Do work here.\n");
    fprintf(stdout, "Closing files.\n");

    fclose(inputFile);
    fflush(outputFile);
    fclose(outputFile);
}