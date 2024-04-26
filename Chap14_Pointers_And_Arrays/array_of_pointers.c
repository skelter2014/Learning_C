#include <stdio.h>

int main(void)
{

    int arrayStd[3][5] = {
        {11,12,13,14,15},
        {21,22,23,24,25},
        {31,32,33,34,35} };

    //Array of pointers
    int* arrayPtr[3] = { 0 };
    //Array sizes and pointer
    const int rows = 3;
    const int cols = 5;
    int* pInteger;

    int array1[5] = { 11,12,13,14,15 };
    int array2[5] = { 21,22,23,24,25 };
    int array3[5] = { 31,32,33,34,35 };

    arrayPtr[0] = array1;
    arrayPtr[1] = array2;
    arrayPtr[2] = array3;

    //Do traversals
    printf("print both arrays using array notation array[i][j]\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %2d", arrayStd[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %2d", arrayPtr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Print both arraysing using pointers, *pInteger++\n");
    pInteger = &arrayStd[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            printf(" %2d", *pInteger++);
        }
        printf("\n");
    }
    printf("\n");

    //Expermiment
    pInteger = arrayPtr[0];
    for (int i = 0; i < rows; i++) {
        pInteger = arrayPtr[i];
        for (int j = 0; j < cols; j++) {
            printf(" %2d", *pInteger++);
        }
        printf("\n");
    }
    printf("\n");






}