// Include standard input-output library
#include <stdio.h>

int main(void)
{
    // Declare an unsigned char variable 'a' and initialize it with hexadecimal value 0x64
    unsigned char a = 0x64;
    // Declare an integer variable 'b' and initialize it with hexadecimal value 0xfafa
    int b = 0xfafa;

    // Print the value of 'a' in uppercase and lowercase hexadecimal format
    printf("value of a: %X [%x]\n", a, a);
    // Print the value of 'b' in uppercase and lowercase hexadecimal format
    printf("value of b: %X [%x]\n", b, b);

    // Prompt the user to enter a new value for 'a'
    printf("Enter value of a: ");
    // Read the hexadecimal value entered by the user and store it in 'a'
    scanf("%x", &a);
    // Prompt the user to enter a new value for 'b'
    printf("Enter value of b: ");
    // Read the hexadecimal value entered by the user and store it in 'b'
    scanf("%x", &b);

    // Print the value of 'a' in both hexadecimal and decimal format
    printf("Value of a: Hex: %X, Decimal %d\n",a,a);
    // Print the value of 'b' in both hexadecimal and decimal format
    printf("Value of b: Hex: %X, Decimal: %d:\n",b,b);

    // Return 0 to indicate successful execution
    return 0;
}




