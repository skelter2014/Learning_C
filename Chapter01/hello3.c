#include <stdio.h>

void printComma1() {
    printf(", ");
    return;
}

void printWord( char* word ){
    printf( "%s", word);
}

int hello3_main()
{
    printWord( "Hello" );
    printComma1();
    printWord( "world" );
    printf("!\n");
    return 0;
}
/* eof */