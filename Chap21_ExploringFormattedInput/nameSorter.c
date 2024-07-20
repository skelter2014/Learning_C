#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int listMax = 5;
//the const int does not work. 
// error: variably modified ‘string’ at file scope
const int stringMax = 80;
#define STRING_MAX 80

//this is really an array of char[80] but you can declare as string
//string* names is an alias to the actual char* names[stringMax] array
typedef char string[STRING_MAX];

void addName(string* names, string newOne, int* listSize);
void printNames(string* names, int listSize);

void removeNewLine(string s)
{
    int len = strlen(s);
    s[len - 1] = '\0';
}

int main(void)
{

    string newName;
    string nameList[listMax];
    int numNames = 0;
    while (printf("Name: %d :", numNames + 1), fgets(newName, stringMax, stdin),
        removeNewLine(newName), strlen(newName) > 0) {

        addName(nameList, newName, &numNames);
    }
    printNames(nameList, numNames);
}

void addName(string* names, string newName, int* pNumEntries)
{
    if (*pNumEntries >= listMax) { //list is full
        puts("list is full");
        return;
    }
    int k = 0;
    bool found = false;
    //compare each existing name to newName
    while (!found && k < *pNumEntries) {
        found = (strcmp(newName, names[k++]) < 0); //starts at left index and moves newName to right while it is LESS than next value
    }
    if (found) {
        k--; // newName goes BEFORE k so back off one
        for (int j = *pNumEntries; j > k; j--) {
            // char *strcpy(char *dest, const char *src)... j is initially set to pNumEntries which is ONE PAST the end.
            strcpy(names[j], names[j - 1]);
        }
    }
    strcpy(names[k], newName); //add the new name at k position
    *pNumEntries += 1;
    return; //Is this needed?
}
void printNames(string* names, int numEntries)
{
    printf("\nNumber of Entries: %d\n\n", numEntries);
    for (int i = 0; i < numEntries; i++) {
        fputs(names[i], stdout);
        fputc('\n', stdout);
    }
}


