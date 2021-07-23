#include <stdio.h>

void printGreeting( char* greeting, char* addressee) {
    printf( "%s, %s!\n", greeting, addressee);
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