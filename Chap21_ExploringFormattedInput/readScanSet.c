#include <stdio.h>

const int bufferSize = 80;
int main (void){
    char stringBuffer[bufferSize];
    printf("Enter only vowels: ");
    int numScanned = scanf("%[aeiouy]", stringBuffer);
    printf("processed string: [%s]\n\n", stringBuffer);
    
}