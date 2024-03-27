#include <stdio.h>



void main(  void ){

    int N = 100;

    printf("The sum of 1..%d via Gaussian function = %d\n", N, gauss_function(N));
    printf("The sum of 1..%d via while loop  = %d\n", N, sumNviaWhile(N));
    printf("The sum of 1..%d via while loop2  = %d\n", N, sumNviaWhile2(N));
    printf("The sum of 1..%d via while for loop  = %d\n", N, sumNviaFor(N));

}
//use a function. Not very computer algorithm friendly.
int gauss_function( int N){
    int sum = 0;
    sum = N * (N + 1) / 2;
    return sum;
}
//Use a for loop
int sumNviaFor( int N ){
    int sum = 0;
    for (int num=0; num < N; num++){
        sum += num + 1;
    }
    return sum;
}

//Use a while Loop counting UP
int sumNviaWhile ( int N ){
    int sum = 0;
    int num = 0;
    while (num < N ) {
        sum += num + 1;
        num ++;

    }
    return sum;
}
//Use a while loop counting down from N. Test condition is N = 0;
int sumNviaWhile2 ( int N){
    int sum = 0;
    while (N) { // N=0 is false
    sum += N;
    N--;
    }
    return sum;
}
