#include <stdio.h>
#include <ctype.h>

int main(void){
    char greeting[] = "hello, world!";
    printf ("%s\n",greeting);

    int len = strlen(greeting);

    int i = 0;
    while ( greeting[i] != '\0'){
        greeting[i] = toupper( greeting[i] );
        i++;

    }
    printf ("%s\n",greeting);

}