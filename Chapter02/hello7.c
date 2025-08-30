#include <stdio.h>

// function prototypes - these allow you to call the functions in any order. Without this, 
// you need to declare the function above the usage.
void printGreeting ( char* aGreeting, char* aName );
void printAGreeting( char* greeting );
void printAnAddressee( char* aName) ;
void printAComma( void );
void printANewLine( void );

/**
 * Main Method 
 */ 
int main()
{
    printGreeting( "Hi", "Bob" );
    return 0;
}


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

/* eof */