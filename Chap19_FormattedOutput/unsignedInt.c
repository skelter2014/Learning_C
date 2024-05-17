#include <stdio.h>
#define DEBUG 1



int main(void)
{
    int smallInt = 12;
    int largeInt = (1024 * 1024 * 3) + (1024 * 2) + 512 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    int negativeInt = -smallInt;
    unsigned anUnsigned = 130;

    printf(" Unsigned Printf \n\n");
    printf("Base              Base-8         Base-10         Base-16        BASE-16\n");
    printf("Specifier         %%12o           %%12u            %%12x           %%12X \n");
    printf("              [%12o] [%12u] [%12x] [%12X]\n", smallInt, smallInt, smallInt, smallInt);
    printf("              [%12o] [%12u] [%12x] [%12X]\n", largeInt, largeInt, largeInt, largeInt);
    printf("              [%12o] [%12u] [%12x] [%12X]\n", anUnsigned, anUnsigned, anUnsigned, anUnsigned);

    //The hash sign # is added to the specifer. it adds a leading zero. It is ignored for decimal format
    printf("Specifier         %%#12o           %%#12u            %%#12x           %%#12X \n");
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", smallInt, smallInt, smallInt, smallInt);
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", largeInt, largeInt, largeInt, largeInt);
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", anUnsigned, anUnsigned, anUnsigned, anUnsigned);

    //negative numbers
    printf("Negative Numbers as Unsigned:\n");
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", -0, -0, -0, -0);
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", -1, -1, -1, -1);
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", -2, -2, -2, -2);
    printf("              [%#12o] [%#12u] [%#12x] [%#12X]\n", -smallInt, -smallInt, -smallInt, -smallInt);

#if DEBUG
    printf("Negative Numbers as Unsigned 0 - -16 :\n");

    for (int i = 0; i > -16; i--) {

        printf(" [%3d]           [%#12o] [%#12u] [%#12x] [%#12X]\n", i, i, i, i, i);
    }

#endif
}