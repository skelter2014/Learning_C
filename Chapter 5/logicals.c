#include <stdio.h>
#include <stdbool.h>



void printLogicalAND( bool z, bool o){
    bool zero_zero = z && z;
    bool zero_one = z && o;
    bool one_zero = o && z;
    bool one_one = o && o;

    printf(" AND | %1d | %1d\n",        z, o);
    printf("   %1d | %1d | %1d \n",   z, zero_zero, zero_one);
    printf("   %1d | %1d | %1d \n\n", o,  zero_one, one_one);

}

void printLogicalAND( bool z, bool o);

int main(void){
    bool tRue  = true;
    bool fAlse = false;

    printLogicalAND (fAlse, tRue);
    return 0;
}