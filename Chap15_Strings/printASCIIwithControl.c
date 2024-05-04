
#include <stdio.h>

int main(void)
{
    char* ctrl[] = { "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    " BS", " HT", " LF", " VT", " FF", " CR", " SO", " SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", " EM","SUB", "ESC", " FS", " GS", " RS", " US" };
    char c1, c2, c3, c4;


    printf("|---------------");
    printf("|-----------------------------------------|\n");
    printf("| SYM Ch DecHex | Ch Dec Hex  | Ch Dec Hex | Ch DecHex |\n");
    printf("|---------------");
    printf("|------------|-----------------|-------------|\n");

    for (int i = 0; i < 32; i++) {
        c1 = i;
        c2 = i + 32;
        c3 = i + 64;
        c4 = i + 96;

        printf("| %s ^%c %3d, %#4x ", ctrl[i], c1 + 64, c1, c1);
        printf("|%c %3d %#x ", c2, c2, c2);
        printf("|%c %3d %#x ", c3, c3, c3);
        if (c4 != 127) {
            printf("| %c %3d %#x \n", c4, c4, c4);
        }
        else {
            printf("|%s %3d %#x |\n", "DEL", c4, c4);
        }
    }
    c1 = 0x7;
    printf("%c%c%c", c1, c1, c1);
}