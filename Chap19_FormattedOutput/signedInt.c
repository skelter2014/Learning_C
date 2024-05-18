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


    printf("\n\n");
    return EXIT_SUCCESS;

}