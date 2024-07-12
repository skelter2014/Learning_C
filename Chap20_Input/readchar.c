#include <stdio.h>

int main(void)
{
    char aChar;
    int anInt1, anInt2;
    int numScanned;

    printf("1st: Enter <integer><char><integer>");
    numScanned = scanf("%d%c%d", &anInt1, &aChar, &anInt2);
    printf(" values scanned = %d. Characters scanned: [%c]\n", numScanned, aChar);

    printf("2nd : Enter <integer> <char> <integer>");
    numScanned = scanf("%d %c%d", &anInt1, aChar, &anInt2);
    printf(" values scanned = %d. Characters scanned: [%c]\n", numScanned, aChar);


}