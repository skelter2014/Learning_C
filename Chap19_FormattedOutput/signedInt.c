#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int smallInt = 12;
    int largeInt = 0x7fffffff; //int32 max
    int negativeInt = -smallInt;
    unsigned anUnsigned = 130;
    long long int reallyLargeInt = 0x07fffffffffffffff;


    printf(" Signed Printf\n");
    printf(" Name          r align         l align         zero           r min           l min        num\n");
    printf(" Specifier     %%10d            %%-10d          %%-.10d         %%10.3d         %%-10.3d        %%d\n");
    printf("             [%10d]   [%-10d]   [%-.10d]   [%10.3d]   [%-10.3d]      [%d]\n", smallInt, smallInt, smallInt, smallInt, smallInt, smallInt);
    printf("             [%10d]   [%-10d]   [%-.10d]   [%10.3d]   [%-10.3d]      [%d]\n", largeInt, largeInt, largeInt, largeInt, largeInt, largeInt);
    printf("             [%10d]   [%-10d]   [%-.10d]   [%10.3d]   [%-10.3d]      [%d]\n", anUnsigned, anUnsigned, anUnsigned, anUnsigned, anUnsigned, anUnsigned);
    printf("             [%10d]   [%-10d]   [%-.10d]  [%10.3d]   [%-10.3d]      [%d]\n", negativeInt, negativeInt, negativeInt, negativeInt, negativeInt, negativeInt);

    printf(" \nSpecifier           %%20lld                  %%-20lld                %%-.20lld\n");
    printf("             [%20lld]   [%-20lld]   [%-.20lld] \n", reallyLargeInt, reallyLargeInt, reallyLargeInt);
    printf("                     %%20.3lld                %%-20.3lld              %%lld\n");
    printf("             [%20.3lld]   [%-20.3lld]   [%lld] \n", reallyLargeInt, reallyLargeInt, reallyLargeInt);




  //Power of 2
    printf("\nPowers of 2: 2^0, 2^2, 2^4, 2^6, 2^8, 2^10\n");
    int k = 1;

    for (int i = 0; i < 6; i++, k <<= 2) {
        printf("               [%6d] [%-6d] [%-.6d] [%6.3d] [%-6.3d] [%d]\n", k, k, k, k,k,k);
    }

    //Power of 9 ????
    printf("\nPowers of 9:       9^1,    9^2,     9^3,     9^4,     9^5\n");
    k = 9;
    for (int i = 0; i < 5; i++, k *= 9) {
        printf("               [%6d] [%-6d] [%.6d] [%6.3d] [%-6.3d] [%d]\n", k, k, k, k,k,k);
    }
    printf("\n\n");



    return EXIT_SUCCESS;

}