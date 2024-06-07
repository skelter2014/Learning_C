#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("NO arguments on command line\n\n");
        printf("Usage %s <argument1> <argument2> ...<argumentN>\n", argv[0]);
        return 0;
    }


    printf("Arcument count = [%d]\n", argc);
    for(int i=0; i < argc; i++){
        printf("argument[%d] = [%s]\n",i, argv[i] );
    }

}