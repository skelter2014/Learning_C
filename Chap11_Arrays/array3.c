#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int findMin(int size, int anArray[]);
int findMax(int size, int anArracy[]);

double findMean(int size, int anArracy[]);
double findStdDev(int size, int anArracy[]);

//iterate through the array to find min value
int findMin(int size, int a[])
{
    int min = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] < min) min = a[i];

    }
    return min;
}

//iterate through the array to find max value
int findMax(int size, int a[])
{
    int max = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] > max) max = a[i];

    }
    return max;
}
double findMean(int size, int a[])
{
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return (double)sum / size;
}

double findStdDev(int size, int a[])
{
    double mean = findMean(size, a);
    double sum = 0.0;
    double variance = 0.0;

    for (int i = 0; i < size; i++) {
        sum += pow((a[i] - mean), 2);
    }
    variance = sum / size;
    double stdDev = sqrt(variance);
    return stdDev;

}

int main(void)
{
    int a[] = { 3,4,6,8,  13,17,18,19 };
    int b[] = { 34, 88, 32, 12, 10 };

    int size = sizeof(a) / sizeof(int);
    printf("array a: range mean & std dev\n");
    printf("range = [%d .. %d]\n",
        findMin(size, a),
        findMax(size, a));

    printf(" mean = %g\n", findMean(size, a));
    printf("std dev = %g\n\n", findStdDev(size, a));


/**********************************************************/
/**********************************************************/
/**********************************************************/
    size = sizeof(b) / sizeof(int);
    printf("array a: range mean & std dev\n");
    printf("range = [%d .. %d]\n",
        findMin(size, b),
        findMax(size, b));

    printf(" mean = %g\n", findMean(size, b));
    printf("std dev = %g\n\n", findStdDev(size, b));

}