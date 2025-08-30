#include <stdio.h>

int hello1_main();
int hello2_main();
int hello3_main();
int hello_main();

int main() {
    printf("Calling hello1_main:\n");
    hello1_main();
    
    printf("\nCalling hello2_main:\n");
    hello2_main();
    
    printf("\nCalling hello3_main:\n");
    hello3_main();
    
    printf("\nCalling hello_main from hello.c:\n");
    hello_main();
    
    return 0;
}
