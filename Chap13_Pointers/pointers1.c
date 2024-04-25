#include <stdio.h>
#include <limits.h>

int main(void)
{
    int height = 10;
    int width = 20;
    int length = 40;
    int* pDimension;

    printf("size of (int) = %3lu\n", sizeof(int));
    printf("size of (int*) = %3lu\n", sizeof(int*) );
    printf(" [height, width, length] = [%2d,%2d,%2d]\n\n", height, width, length);
    printf("address of pDimension = %#lx\n", (unsigned long)&pDimension);

    pDimension = &height;
    printf("address of height = %#lx, value at address = %2d\n", (unsigned long)pDimension, *pDimension);
    pDimension = &width;
    printf("address of width = %#lx, value at address = %2d\n", (unsigned long)pDimension, *pDimension);
    pDimension = &length;
    printf("address of length = %#lx, value at address = %2d\n", (unsigned long)pDimension, *pDimension);


}