#include <stdio.h>


void sort(char**, int);
int main()
{
    char* string_database[5] = { '\0' };
    string_database[0] = "Florida";
    string_database[1] = "Oregon";
    string_database[2] = "California";
    string_database[3] = "Georgia";

    sort(string_database, 4);
    return 0;
}

void sort(char** str, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        printf("The string is= %s\n", str[i]);
}