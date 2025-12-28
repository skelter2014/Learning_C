#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE  10000
#define RANGE 10000

void bubble_sort(int *arr, int n);
void print_array(int *arr, int n);
void populate_array(int *arr, int n);

int main(){

    int data[SIZE];
    srand(time(NULL));

    populate_array(data, SIZE);
    printf("Unsorted Array - 1st 100 elements: \n");
    print_array(data, 100);
    printf("Sorting %d elements ... \n", SIZE);
    bubble_sort(data, SIZE);
    printf("Sort Complete. \n");

    print_array(data, 100);

}

void populate_array(int *arr, int n){
    int *end = arr + n; // points to the memory address AFTER the last element
    for (int *p = arr; p < end; p++){
        //dereference p to assign a random value between 1 and 999999
        *p = (rand() % (RANGE - 1)) + 1;
    }
}

void bubble_sort(int *arr, int n){
    int swapped;
    int *p;
    int *last_element = arr + n -1;

    for (int i = 0; i < n-1; i ++){
        swapped = 0;
        for (p = arr; p < last_element - i; p++){
            if (*p > *(p + 1)){
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

}

void print_array(int *arr, int n){
    int counter = 0;
    printf("Sample Output: ");
    int *end = arr + n; // point to mem address AFTER last element
    for (int *p = arr; p < end; p++){
        if (counter % 5 == 0) printf("\n");
        printf("%.6d ", *p);
        counter ++;
    }
    printf("\n");
}
