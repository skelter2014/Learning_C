#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
This version uses straight char[] arrays instead of a typedef
*/

const int listMax = 5;
const int stringMax = 80;

void addName(char names[listMax][stringMax], char newOne[], int* listSize);
void printNames(char names[listMax][stringMax], int listSize);

void removeNewLine(char* s)
{
    int len = strlen(s);
    s[len - 1] = '\0';
}
int main(void)
{
    char newName[stringMax]; //declare array to hold newName
    char names[listMax][stringMax]; //Declare 2 dim array of chars
    int numNames = 0;
    while (printf("Name: %d :", numNames + 1), fgets(newName, stringMax, stdin),
        removeNewLine(newName), strlen(newName) > 0) {

        addName(names, newName, &numNames);
    }
    printNames(names, numNames);
}

void addName(char names[][stringMax], char* newName, int* pNumEntries)
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
void printNames(char names[][stringMax], int numEntries)
{
    printf("\nNumber of Entries: %d\n\n", numEntries);
    for (int i = 0; i < numEntries; i++) {
        fputs(names[i], stdout);
        fputc('\n', stdout);
    }
}


