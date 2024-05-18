#include <stdio.h>

int main(void)
{

    for (int i = 1; i <= 20; i++) {
        printf("The [%d] number in the series: %d \n", i, fib(i));
    }

}

int fib(int d)
{
    if (d == 1 || d == 2) {
        return d - 1;
    }
    else {
        return fib(d - 1) + fib(d - 2);
    }
}
