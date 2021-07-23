#include <stdio.h>

void printAGreeting( char* greeting ){
    printf("%s", greeting);
}
void printAComma( void ) {
    printf(", ");
}
void printAnAddressee( char* aName) {
    printf( "%s", aName );
}
void printANewLIne(){
    printf( "\n" );
}

void printGreeting( char* aGreeting, char* aName ){
    printAGreeting (aGreeting );
    printAComma();
    printAnAddressee( aName );
    printANewLIne();
}

int main()
{
    printGreeting( "Hi", "Bob" );
    return 0;
}
/* eof */