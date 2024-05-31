#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void printBits(unsigned);
unsigned createMask(unsigned a, unsigned b);
int main(void)
{

    printf(" +++++ UnSigned Integer +++++\n");
    printf(" + Shift One bit to the right 32 times +\n\n");

    unsigned int x = ~0;
    int count = 0;
    int temp = 0;
    while ( x!= 0) {

        count++;
        printBits(x);
        printf("   x = [%10u] %#010x\n", x,x);
        x >>= 1;



    }
    printf("count = %d\n\n", count);


    printf(" +++++ Signed Integer +++++\n\n");
    for (int i = -16; i < 17; i++) {
        printBits(i);
        printf("   i = [%3i] %#010x\n", i, i);
    }
    printf("\n\n");

}

//Prints the bit pattern of a 32 bit number. 
void printBits(unsigned x)
{
    char result[40] = { 0 };
    unsigned char r = createMask(0, 3);
    char* ar[] = { "0000 ","0001 ","0010 ","0011 ",
              "0100 ","0101 ","0110 ","0111 ",
              "1000 ","1001 ","1010 ","1011 ",
              "1100 ","1101 ","1110 ","1111 " };


    char temp = 0; // use an bit char for temp;
    for (int i = 7; i >= 0; i--) {

        temp = (x >> (i * 4)) & r;
        strcat(result, ar[temp]);
    }
    printf("%s", result);
}

//Create a mask starting with the a'th bit to the b'th bit of an interger ex: 0000 1111 1111 1000. This mask is ANDed with
//an int to determine if that bit is set.
unsigned createMask(unsigned a, unsigned b)
{
    unsigned r = 0;
    for (unsigned i = a; i <= b; i++)
        r |= 1 << i;

    return r;
}