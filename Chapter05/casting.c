#include <stdio.h>

int main( void){
    int numerator = 33;
    int denominator = 5;
    double result = 0.0;

    result = numerator / denominator;
    printf("Truncation: %d / %d = %.2g\n", numerator, denominator, result);

    result = (double)  numerator / denominator;
    printf("No Truncation: %.2f / %d = %.2f\n", (double)numerator, denominator, result);

        result = numerator / (double)denominator;
    printf("             : %d / %.2f = %.2f\n", numerator, (double)denominator, result);

}