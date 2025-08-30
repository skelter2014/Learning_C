#include <stdio.h>


int binarySum(int data[], int low, int high, char* src);
void indent(int count, char c);
const char indentChar = ' ';


/*
This program uses binary recursion to add all of the numbers in an array. It splits the array in half
and calls the function recursively on each half until there is only one element in the array, at which
point the value can be derived.

static const char to_red[] = "\033...";
static const char to_black[] = "\033...";

printf("%s%s%s\n", to_red, "hello world", to_black)
*/

//Ansi color codes -> \033 is the escape sequence
static  char to_red[] = "\033[31m";
static const char to_blue[] = "\033[34m";
static  char to_yellow[] = "\033[33m";
static  char to_default[] = "\033[0m";


int main(void)
{



    int data[] = { 10,20,30,40,50,60,70,80,90,100 };
    printf("\nThe sum of all the digits in the array: %d\n\n", binarySum(data, 0, 9, "-"));
    printf("\n");


}

int binarySum(int* data, int low, int high, char* src)
{
     const char * color = to_blue;
    static int count = 0;
    if (src == "left") { color = to_yellow; }
    indent(count, indentChar);
    printf("low: %d  high: %d   src: %s%s%s\n", low, high, color, src, to_default);

    if (low > high)
    {
        return 0;
    }

    else if (low == high) {
        indent(count, indentChar);
        printf("%sdata[%d]=%d%s\n", to_red, low, data[low], to_default);
        count--;
        return data[low];
    }
    else {
        count++;
        int mid = (low + high) / 2;
        return binarySum(data, low, mid, "left") + binarySum(data, mid + 1, high, "right");
    }
}

void indent(int count, char c)
{
    for (int i = 0; i < count * 4; i++) printf("%c", c);
}

