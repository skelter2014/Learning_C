#include <stdio.h>

int main(void)
{

    int anArray[10] = {0};
    int x,y,z;
     x = 11;
     y = 12;
     z = 13;

     anArray[11] = 7; //compiler error.
     anArray[x] = -1; // runtime error


}