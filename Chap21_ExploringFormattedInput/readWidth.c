#include <stdio.h>

int main(void)
{
    int year, month, day;
    int numScanned;

    while (
        printf("Enter mmddyyyy (any other char to quit): "),
        numScanned = scanf("%2d%2d%4d", &month, &day, &year),
        numScanned > 0)
        printf("%d/%d/%d\n", month, day, year
        );
    printf("\nDone.\n");

}