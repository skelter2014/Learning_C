#include <stdio.h>

int factorial(int n);

int main(void)
{

    int n[] = { 1, 3, 5, 0 };

    for (int i = 0; i < 4; i++) {
        int f = factorial(n[i]);
        printf("Factorial of [%d] is %d\n\n", n[i], f);

    }


}

/*
recursive function. ? how to remove last '*'
*/
int factorial(int n)
{
    //determine printing characters up front
    if (n != 0) {
        printf("%d", n);
        if (n > 1) {
            printf(" * ");
        }

    }

    //this is the main algorithm
    if (n == 0) {
        printf("\n ");
        return 1;
    }
    else {

        return n * factorial(n - 1);
    }
}