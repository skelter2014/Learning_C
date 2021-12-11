#include <stdio.h>

int main(void)
{
    unsigned char a = 0x64;
    int b = 0xfafa;

    printf("value of a: %X [%x]\n", a, a);
    printf("value of b: %X [%x]\n", b, b);

    
    printf("Enter value of a: ");
    scanf("%x", &a);
    printf("Enter value of b: ");
    scanf("%x", &b);

    printf("Value of a: Hex: %X, Decimal %d\n",a,a);
    printf("Value of b: Hex: %X, Decimal: %d:\n",b,b);

    return 0;
     
     
}




