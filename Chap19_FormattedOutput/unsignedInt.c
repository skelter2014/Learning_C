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
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", smallInt, smallInt, smallInt, smallInt);
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", largeInt, largeInt, largeInt, largeInt);
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", anUnsigned, anUnsigned, anUnsigned, anUnsigned);

    //negative numbers
    printf("Negative Numbers as Unsigned:\n");
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", -0, -0, -0, -0);
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", -1, -1, -1, -1);
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", -2, -2, -2, -2);
    printf("              [%#12o] [%12u] [%#12x] [%#12X]\n", -smallInt, -smallInt, -smallInt, -smallInt);

#if DEBUG
    printf("\nNegative Numbers as Unsigned 0 .. -17 :\n");

    for (int i = 0; i > -17; i--) {

        printf(" [%3d]           [%#12o] [%12u] [%#12x] [%#12X]\n", i, i, i, i, i);
    }

#endif

    //Power of 2
    printf("\nPowers of 2: 2^0, 2^2, 2^4, 2^6, 2^8, 2^10\n");
    int k = 1;

    for (int i = 0; i < 6; i++, k <<= 2) {
        printf("               [%#12o] [%12u] [%#12x] [%#12X]\n", k, k, k, k);
    }

    //Power of 9 ????
    printf("\nPowers of 9: 9^1, 9^2, 9^3, 9^4\n");
    printf("Specifier         %%#12o           %%#12u            %%#12x           %%#12X \n");
    k = 9;
    for (int i = 0; i < 5; i++, k *= 9) {
        printf("               [%#12o] [%12u] [%#12x] [%#12X]\n", k, k, k, k);
    }


    //Pointer Values

    printf("\nPointer Output\n");
    printf("             %%p   [%p] using pointer formatting\n", &smallInt);
    printf("             %%#lx [%#lx] using hex formatting \n\n", (unsigned long)&smallInt);

    

}