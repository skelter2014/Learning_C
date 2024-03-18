#include <stdio.h>

int main(void){
    char lowerChar = 'b';
    char upperChar = 'M';

    char anUpper = lowerChar - 32;
    char aLower = upperChar + 32;

    printf("lower case '%c' can be changed to upper case '%c' \n", lowerChar, anUpper);
    printf("upper case '%c' can be changed to lower case '%c'\n", upperChar, aLower);
}