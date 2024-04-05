#include <stdio.h>
#include <stdbool.h>


bool isPrime(int num);


void main (void){
    printf("Is prime: %d %d", 5, isPrime(6));
}

//returns true if num is prime number (not divisible by another number)
bool isPrime (int num){
    if (num < 2) return false;
    if ( num == 2 ) return true;


    bool isPrime = true;
    for (int i=2; i < num; i++){
        if (num % i  == 0 ){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}