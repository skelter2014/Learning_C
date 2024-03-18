#include <stdio.h>

int main(void){
    char digit5 = '5';
    char digit8 = '8';

    int sumDigits = digit5 + digit8;
    printf("sum of digits = %d\n", sumDigits);

    char value5 = digit5 - '0';
    char value8 = digit8 - '0';

    sumDigits = value8 + value5;
    printf("sum of digits = %d\n", sumDigits);

}
