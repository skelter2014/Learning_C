#include <stdio.h>

int main(void)
{
    int anInteger = -1;
    double aDouble = -1.0;
    int numScanned = 0;

    printf("Enter an integer and a decimal number:");
    numScanned = scanf("%d%lf", &anInteger, &aDouble);
    printf("scafn() was able to assign %d value\n", numScanned);
    
    
    if (numScanned > 0) printf("1. integer: %d\n", anInteger);
    if (numScanned > 1) printf("2. double: %lf\n", aDouble);

}