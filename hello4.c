#include <stdio.h>

void printComma() {
    printf(", ");
}

void printWord( char* word ){
    printf( "%s", word);
}

void printGreeting( char* greeting, char* addressee) {
    printWord( greeting );
    printComma();
    printWord( addressee );
    printf("!\n");
}

int main()
{
    printGreeting( "Hello", "world ");
    printGreeting( "Good day", "Your Royal Highness" );
    printGreeting( "Howdy", "John Q. and Jane P. Doe" );
    printGreeting( "Hey", "Moe, Larry and Shemp" );
    return 0;
}
/* eof */