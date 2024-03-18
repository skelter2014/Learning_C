#include <stdio.h>

void doubleFunc(double dbl);
void longIntFunc(long int li);

int main(void)
{
    float f = 58.73;
    short int i = 13;

    longIntFunc(i);
    longIntFunc(f);

    doubleFunc(f);
    doubleFunc(i);

    return 0;
}

void doubleFunc(double dbl)
{
    printf("doubleFunct %.2f\n", dbl);
}

void longIntFunc(long int l)
{
    printf("longIntFunc %ld\n", l);
}
