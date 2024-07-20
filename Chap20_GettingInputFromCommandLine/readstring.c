#include <stdio.h>

const int bufferSize = 80;
int main(void) {
    char strinBuffer[bufferSize];

    printf("Enter a string");
    scanf("%s", strinBuffer);
    printf("process string: [%s]\n", strinBuffer);

}