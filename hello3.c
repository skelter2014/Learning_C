#include <stdio.h>

void printComma() {
    printf(", ");
    return;
}

void printWord( char* word ){
    printf( "%s", word);
}

int main()
{
    printWord( "Hello" );
    printComma();
    printWord( "world" );
    printf("!\n");
    return 0;
}
/* eof */