#include <stdio.h>



void main(  void ){

    int N = 100;

    printf("The sum of 1..%d via Gaussian function = %d\n", N, gauss_function(N));
    printf("The sum of 1..%d via while loop  = %d\n", N, sumNviaWhile(N));
    printf("The sum of 1..%d via while loop2  = %d\n", N, sumNviaWhile2(N));
    printf("The sum of 1..%d via for loop  = %d\n", N, sumNviaFor(N));
    printf("The sum of 1..%d via for loop2  = %d\n", N, sumNviaFor2(N));
    printf("The sum of 1..%d via do while  = %d\n", N, sumViaDoWhile(N));
    printf("The sum of 1..%d via do while2  = %d\n", N, sumNviaDoWhile2(N));
    printf("The sum of 1..%d via goto  = %d\n", N, sumNviaGoto_Do(N));

}
//use a function. Not very computer algorithm friendly.
int gauss_function( int N){
    int sum = 0;
    sum = N * (N + 1) / 2;
    return sum;
}

// using a goto loop
int sumNviaGoto_Do(int N){
    int sum=0;
    int num=0;
    begin_loop:
        sum+= (num+1);
        num++;
        if (num < N) goto begin_loop;
        //else fall-through
    end_loop:
        return sum;
}
//do while count down
int sumNviaDoWhile2 (int N){
    int sum = 0;
    do {
        sum += N;
        N--;
    }while (N !=0); //0=false
    return sum;
}

//do while
int sumViaDoWhile (int N){
    int sum = 0, num = 0;
    do {
        sum += (num + 1);
        num++;
    } while ( num < N);

    return sum;
}
//use a for loop not off by 1
int sumNviaFor2 ( int N){
    int sum = 0;
    for (int i = N ; i > 0; i -- ){
        sum += i;
    }
    return sum;
}

//Use a for loop
int sumNviaFor( int N ){
    int sum = 0;
    for (int num=0; num < N; num++){
        sum += num + 1; // off-by-one. 0..99 --> 1..100
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
