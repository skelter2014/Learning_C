#include "nameList.h"

ListNode* CreateListNode(char* pNameToAdd){
    ListNode* pNewNode = (ListNode*)calloc(1, sizeof(ListNode));
    if (pNewNode == NULL) OutOfStorage();
    pNewNode -> pData = (char*)calloc(1, strlen(pNameToAdd) + 1);
    if (pNewNode->pData == NULL) OutOfStorage();
    strcpy(pNewNode->pData, pNameToAdd);

    return pNewNode;
}

void AddName(NameList* pNames, char* pNameToAdd){

    ListNode* pNewName = CreateListNode(pNameToAdd);

    if (IsEmpty(pNames)){
        pNames->pFirstNode = pNewName;
        pNames->nodeCount++;
        return;
    }

    pNames->nodeCount++;
    ListNode* curr;
    ListNode* prev;
    curr = prev = pNames->pFirstNode; //start at head of list
    while(curr){
        if(strcmp(pNewName->pData, curr->pData) < 0){
            //found insertion point before an existing name
            if(curr == pNames->pFirstNode){
                pNames->pFirstNode = pNewName;
                pNewName->pNext = curr;
            }else {
                prev->pNext = pNewName;
                pNewName->pNext = curr;
            }
            return;
        }
        prev = curr; //adjust pointers
        curr = prev->pNext;
    }
    prev->pNext = pNewName; //Insert at end
}

void OutOfStorage(){
    fprintf(stderr, "#### FATAL ERROR #### out of Storage");
    exit(EXIT_FAILURE);

}
bool IsEmpty(NameList* pNames){
    return pNames->nodeCount == 0;
}
void PrintNames(FILE* outputFileDesc, NameList* pNames){
    ListNode* curr = pNames->pFirstNode;
    while (curr){
        fputs(curr->pData, outputFileDesc);
        fputc('\n', outputFileDesc);
        curr = curr->pNext;
    }
}
void DeleteNames(NameList* pNames){
    while(pNames->pFirstNode){
        ListNode* temp = pNames->pFirstNode;
        pNames->pFirstNode = pNames->pFirstNode->pNext;
        free(temp->pData);
        free(temp);
    }
}