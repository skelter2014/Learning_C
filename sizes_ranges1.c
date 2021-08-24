#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

/**
 * If you are using MinGW, the problem is that by default, MinGW uses the I/O resp.
 * formatting functions from the Microsoft C runtime, which doesn't support 80 bit 
 * floating point numbers (long double == double in Microsoft land).
 * However, MinGW also comes with a set of alternative implementations that do 
 * properly support long doubles. To use them, prefix the function names 
 * with __mingw_ (e.g. __mingw_printf). Depending on the nature of your project, 
 * you might also want to globally #define printf __mingw_printf or use 
 * -D__USE_MINGW_ANSI_STDIO (which enables the MinGW versions of all the 
 * printf-family functions).
 * 
 * @ref https://stackoverflow.com/questions/4089174/printf-and-long-double/14988103#14988103?newreg=4c0479e9f2ce4587b51aa76702f5e361
*/
#define printf __mingw_printf

//function prototypes
void printSizes(void);
void printRanges(void);

int main(void)
{
    printSizes();
    printRanges();
}

//function to print the # of bytes for each of C11's data types
void printSizes(void)
{
    printf("Size of C data types \n\n");
    printf("Type             Bytes\n\n");
    printf("char               %lu\n", sizeof(char));
    printf("int8_t             %lu\n", sizeof(int8_t));
    printf("unsigned char      %lu\n", sizeof(unsigned char));
    printf("short              %lu\n", sizeof(short));
    printf("int16_t            %lu\n", sizeof(int16_t));
    printf("uint16_t           %lu\n", sizeof(uint16_t));
    printf("int                %lu\n", sizeof(int));
    printf("unsigned           %lu\n", sizeof(unsigned));
    printf("long               %lu\n", sizeof(long));
    printf("unsigned long      %lu\n", sizeof(unsigned long));
    printf("int32_t            %lu\n", sizeof(int32_t));
    printf("uint32_t           %lu\n", sizeof(uint32_t));
    printf("long long          %lu\n", sizeof(long long));
    printf("int64_t            %lu\n", sizeof(int64_t));
    printf("unsigned long long %lu\n", sizeof(unsigned long long));
    printf("unint64_t          %lu\n", sizeof(uint64_t));
    printf("\n");
    printf("float              %lu\n", sizeof(float));
    printf("double             %lu\n", sizeof(double));
    printf("long double        %lu\n", sizeof(long double));
    printf("\n");
    printf("bool               %lu\n", sizeof(bool));
    printf("\n");
}
void printRanges( void ){
    printf("Ranges for iteger data types in C\n\n");
    printf("int8_t   %20d %20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("int16_t  %20d %20d\n", SHRT_MIN, SHRT_MAX);
    printf("int32_t  %20d %20d\n", INT_MIN, INT_MAX);
    printf("int64_t  %20lld %20lld\n", LLONG_MIN, LLONG_MAX);
    printf("uint8_t  %20d %20d\n", 0, UCHAR_MAX);
    printf("uint16_t %20d %20d\n", 0, USHRT_MAX);
    printf("uint32_t %20d %20u\n", 0, UINT_MAX);
    printf("uint64_t %20d %20llu\n", 0, ULLONG_MAX);
    printf("\n");
    printf("ranges for real number data types i C\n");
    printf("float %14.7g %14.7g\n", FLT_MIN, FLT_MAX);
    printf("double %14.7g %14.7g\n", DBL_MIN, DBL_MAX);
    printf("long double %3.7Lg %4.7Lg\n",__LDBL_MIN__, __LDBL_MAX__);
    printf("\n");

 
}