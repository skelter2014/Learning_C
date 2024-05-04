
#include <stdio.h>

int main(void)
{
    char c1, c2, c3, c4;

    printf("| Ch DecHex | Ch Dec Hex | Ch DecHex |\n");
    printf("|-----------|------------|-----------|\n");
        for (int i = 0; i < 32; i++) {
            c2 = i;
            c2 = i + 32;
            c3 = i + 64;
            c4 = i + 96;

            printf("| %c %3d %#x | %c %3d %#x | %c %3d %#x |\n", c2, c2, c2, c3, c3, c3, c4, c4, c4);
        }
}

