#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getX(char* arr);
int getO(char* arr);


int main(void)
{

    char output[100] = { 0 };
    char X[80] = { 0 };
    char O[80] = {0};
    getX(X);
    strcat(output, X);

    getO(O);
    strcat(output, O);
    puts(output);
}



/*
Function to return an X
*/
int getO(char* arr)
{
    char* X[] = {
    "   oo   \n",
    " oo  oo \n",
    "oo    oo\n",
    " oo  oo \n",
    "   oo   \n"
    "\0"
    };
    for (int i = 0; i < 5; i++) {
        strcat(arr, X[i]);

    }
    return 0;

}/*
Function to return an X
*/
int getX(char* arr)
{
    char* X[] = {
    "xx    xx\n",
    " xx  xx \n",
    "   xx   \n",
    " xx  xx \n",
    "xx    xx\n"
    "\0"
    };
    for (int i = 0; i < 5; i++) {
        strcat(arr, X[i]);

    }
    return 0;

}