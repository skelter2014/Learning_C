#include <stdio.h>

int main(void)
{
    double aDouble = 987654321.987654321;

    printf("Use of the %%f, %%e and %%E format.\n\n");

    printf("%%f      [%f], whatever\n", aDouble);
    printf("%%.3f    [%.3f] 3 decimal places\n", aDouble);
    printf("%%.8f    [%.8f] 8 decimal places\n", aDouble);
    printf("%%.0f    [%.0f] no decimal places\n", aDouble);
    printf("%%.0f    [%.0f] no decimal places\n", aDouble);
    printf("%%#.0f   [%#.0f] no decimal placesm but decimal point\n", aDouble);
    printf("%%15.3f  [%15.3f]3 decimals, 15 wide, right align\n", aDouble);
    printf("%%-15.3f [%-15.3f]3 decimals, 15 wide, left align\n", aDouble);


    printf(" %%e [%e] using exponential notation\n", aDouble);
    printf(" %%E [%E] using EXPONENTIAL notation\n", aDouble);
    printf(" %%.3e [%.3e] exponent with 3 decimal places\n", aDouble);
    printf(" %%15.3e [%15.3e] exponent with 3 decimal places. 15 wide\n", aDouble);
    printf(" %%015.3e [%015.3e] exponent with 3 decimal places, 15 wide\n", aDouble);
    printf(" %%15.3e [% 15.3e] space for sign\n", aDouble);
    printf(" %%+15.3e [%+15.3e] space for sign\n", aDouble);
    printf(" %%+015.3e [%+015.3e] space for sign\n", aDouble);
    printf(" %%.0e [%.0e] no decimals ?.\n", aDouble);
    printf(" %%15.0e [%15.0e] no decimals ?15 wide.\n", aDouble);

    printf(" %%a[%a] hex version of double, exponent=2^p\n", aDouble);
    printf(" %%A[%A] hex version of double, exponent=2^p\n", aDouble);

    printf("\n\n");

}