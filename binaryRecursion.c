#include <stdio.h>


int binarySum(int data[], int low, int high, char* src);
void indent(int count, char c);
const char indentChar = ' ';


/*
This program uses binary recursion to add all of the numbers in an array. It splits the array in half
and calls the function recursively on each half until there is only one element in the array, at which
point the value can be derived.
*/

int main(void)
{

    int data[] = { 1,1,1,1,1,1,1,1,1,1 };
    printf("\nThe sum of all the digits in the array: %d\n\n", binarySum(data, 0, 9, "-") );
    printf("\n");


}

int binarySum(int* data, int low, int high, char* src)
{
    static int count = 0;
    indent(count,indentChar);
    printf("low: %d  high: %d   src: %s\n", low, high, src);

    if (low > high)
    {
        return 0;
    }

    else if (low == high) {
        indent(count,indentChar);
        printf("data[%d]=%d\n", low, data[low]);
        count--;
        return data[low];
    }
    else {
        count++;
        int mid = (low + high) / 2;
        return binarySum(data, low, mid, "left") + binarySum(data, mid + 1, high, "right");
    }
}

void indent(int count, char c){
  for (int i=0; i < count*4; i++) printf("%c",c);
}

