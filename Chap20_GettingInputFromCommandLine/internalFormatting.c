#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int bufferSize = 80;

int main(void)
{
    int anInteger = -1;
    double aDouble = -1.0;
    int numScanned = 0, numPrinted = 0;

    char sIn[] = "1234 567.890";
    char sOut[bufferSize];
    memset(sOut, '.', bufferSize); //sets the out buffer to all zeros

    printf("using sscanf() on sIn char array: [%s]\n", sIn);

    numScanned = sscanf(sIn, "%d%lf", &anInteger, &aDouble);
    printf("sscanf() was able to assign %d value\n", numScanned);


    if (numScanned > 0) printf("1. integer: %d\n", anInteger);
    if (numScanned > 1) printf("2. double: %lf\n\n", aDouble);

    puts("Using sprintf() for format values to string buffer:");
    numPrinted = sprintf(sOut, "integer=[%d] double=[%3.3lf]",
        anInteger, aDouble);
    printf("%d characters in output string \" %s \" \n", numPrinted, sOut);


    /* using atoi and atof ascii to integer and ascii to float functions*/

    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    char sInteger[] = "1234";
    char sDouble[] = "567.8910";
    printf("As strings: integer=\"%s\" double=\"%s\"\n",sInteger, sDouble );
    anInteger = atoi(sInteger);
    aDouble = atof(sDouble);

    printf("As values: integer=[%d] double=[%lf]\n",anInteger, aDouble );




}