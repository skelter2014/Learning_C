#include <stdio.h>

double inchesToFeet( double );


int main( void){
    double inches = 953;
    double feet = 0.0;
    feet = inchesToFeet( inches);
    printf("%12.3f inches is equal to %12.3f feet\n", inches, feet);
    return 0;

    
}

double inchesToFeet(double inches)
{
    return inches / 12.0;
}
