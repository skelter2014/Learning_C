#include <stdio.h>

int main(void){
    char aChar = 'C';
    char* pStr = "Learn to program with C";

    printf("String output\n");
    printf("Specifier Formatted Value\n");
    printf("%%s       \t[%s]            everything\n", pStr);
    printf("%%30s     \t[%30s]          everything right-aligned field=30\n", pStr);
    printf("%%.10s    \t[%.10s]                        truncated to first 10 char\n", pStr);
    printf("%%30.10s  \t[%30.10s]       10 char, right aligned. fld=30\n", pStr);
    printf("%%-30.10s \t[%-30.10s]      10 char, left aligned. fld=30\n", pStr);
    printf("%%*.*s    \t[%*.*s]         10 char, left aligned. fld=30\n\n", 30,10, pStr);

    //substring
    printf("sub-string output\n");
    printf("%%.7s [%.7s] 3rd word (using array offset)\n", &pStr[9]);
    printf("%%.12s [%.12s] 3rd and 4th words (using pointer offset)\n\n", pStr + 9);

    //character output
    printf("%%c [%c] character\n", aChar);
    printf("%%10c [%10c] character right-aligned fld=10\n",aChar);
    printf("%%-10c [%-10c], char left align fld=10\n",aChar);



}