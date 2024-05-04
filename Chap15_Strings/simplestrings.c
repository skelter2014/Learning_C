#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char string0[8] = { 0 };

    char string1[8] = { 'h', 'e','l','l','o','\0' };
    char string2[8] = "xxxx";
    char string3[2] = "yy";
    char* string4 = "zzzz";

    printf("A) 0: \"%1s\" 1: \"%s\" 2: \"%s\" 3: \"%s\" 4: \"%s\"\n\n", string0, string1, string2, string3, string4);

    string0[0] = 'H';
    string1[0] = 'H';
    string2[0] = toupper(string2[0]);
    string3[0] = toupper(string3[0]);
    //string4[0] = 'H'; //Can't do this because it is a pointer to a literal string Exception has occurred.
                    //Segmentation fault
    char* string5 = "Hello.."; //new pointer to new string
    printf("B) 0: \"%1s\" 1: \"%s\" 2: \"%s\" 3: \"%s\" 4: \"%s\"\n\n", string0, string1, string2, string3, string5);

    //string0 = "12345678"; //ERROR: assignment to expression with array type

    char string6[4] = "12345"; //results in "1234"  -- truncates last digit and does not include terminator

    char* stringArr[4] = { NULL };
    stringArr[0] = string1;
    stringArr[1] = string5;
    stringArr[2] = string6;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            printf(" %c", stringArr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /*
        H e l l o
        H e l l o . .
        1 2 3 4 Y y X x   //!!!!! without the null terminator, and counting, you are getting other data.
    */

}
