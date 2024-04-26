#include <stdio.h>
#include <limits.h>


void showInfo (int height, int width, int length){
    printf("size of (int) = %3lu\n", sizeof(int));
    printf("size of (int*) = %3lu\n", sizeof(int*) );
    printf(" [height, width, length] = [%2d,%2d,%2d]\n\n", height, width, length);
}
void showVariable(char* pId, int* pDim) {
    printf("address of %s = %#lx, value at address = %2d\n", pId, (long long) pDim, *pDim);
}

int main(void)
{
    int height = 10;
    int width = 20;
    int length = 40;
    int* pDimension = NULL; //this is no longer needed. We pass the address directly into the pointer function param.
    char* pIdentifier = NULL;


    printf("\nValues: \n\n");
    showInfo(height, width, length);

    printf("Using address of each named variables ....\n\n");

    showVariable("Height", &height);
    showVariable("Width", &width);
    showVariable("Length", &length);

    
}