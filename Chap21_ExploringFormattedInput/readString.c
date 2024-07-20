#include <stdio.h>

const int bufferSize = 90;


int main(void)
{

char stringBuffer[bufferSize];

    puts("Enger a string  ");
    gets(stringBuffer);
    puts("You entered: ");
    puts(stringBuffer);


    puts(" \n**********\ntake two with fgets()");
    fgets(stringBuffer, 10, stdin);
    puts("You entered: ");
    puts(stringBuffer);
}