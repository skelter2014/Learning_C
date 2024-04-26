#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const int arraySize = 5;
    int array[5] = { 1,2,3,4,5 };
    int* pArray1 = array;
    int* pArray2 = &(array[0]);

    int var1 = 5, var2 = 5;

    // 5 is displayed
    // Then, var1 is increased to 6.
    printf("%d\n", var1++);

    // var2 is increased to 6 
    // Then, it is displayed.
    printf("%d\n", ++var2);

    for (int i = 0; i < arraySize; ++i) {
        printf("i=%d\n", i);

    }
    printf("Pointer values (addresses) from initial assignments:\n\n");
    printf("address of array = %#lx, value at array = %d\n", (unsigned long long)array, *array);
    printf("address of &array[0] = %#lx, value at array[0] = %d\n", (unsigned long long) & array[0], array[0]);
    printf("address of pArray1 = %#lx value at pArray1 = %#lx\n", (unsigned long long) & pArray1, (unsigned long long)pArray1);
    printf("address of pArray2 = %#lx value at pArray2 = %#lx\n", &pArray2, (unsigned long long)pArray2);

    printf("\n(1) Using array notation. - array index is incremented\n\n");
    for (int i = 0; i < arraySize; i++) {
        printf("&array[%d] = %#lx, array[%d] = %d, i++\n", i, (unsigned long long) & array[i], i, array[i]);
    }

    printf("\n(2) Using a pointer addition - offset is incremented\n\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("pArray2+%1d = %#lx, *(pArray2+%1d) = %1d, i++\n", i, (pArray2 + i), i, *(pArray2 + i));
    }
    printf("\n(3) Using pointer referencing - pointer is incremented\n\n");
    for (int i = 0; i < arraySize; i++, pArray1++) {
        printf(" pArray1 = %#lx, *pArray1 = %1d, pArray++\n", pArray1, *pArray1);
    }

}