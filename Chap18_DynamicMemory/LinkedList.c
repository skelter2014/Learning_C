#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _Node ListNode;
typedef int ListData;
typedef enum eAction { eLook, eInsert, eDelete } eAction;
typedef enum eWhere { eFront, eBack } eWhere;
typedef struct _Node {
    ListNode* pNext;
    ListData* pData;
} ListNode;

typedef struct {
    ListNode* pFirstNode;
    int nodeCount;
} LinkedList;

LinkedList* CreateLinkedList();
ListData* CreateData(ListData d);

bool IsEmpty(LinkedList* pList);
int Size(LinkedList* pList);
void InsertNodeToBack(LinkedList* pList, ListNode* pNode);
void InsertNodeToFront(LinkedList* pList, ListNode* pNode);
ListNode* RemoveNodeFromFront(LinkedList* pList);
ListNode* RemoveNodeFromBack(LinkedList* pList);
ListNode* GetNode(LinkedList* pList, int pos);
ListNode* CreateNode(ListData* pData);
void DeleteNode(ListNode* pNode);
//Print prototypes;
void (*__printData)(ListData* pData);
void PrintList(LinkedList* pList, void (*__printData)(ListData* pData));
void PrintNode(ListNode* pNode, void (*__printData)(ListData* pData));
void PrintInt(ListData* pData);
void OutOfStorage(void);
int Size(LinkedList* pList);
//Test prototypes
void TestPrintOperation(LinkedList* pList, eAction action, ListData data, eWhere where);


int main(void)
{
    LinkedList* pList = CreateLinkedList();

    printf("\nUsing input {1 2 3 4}\t\t");

    PrintList(pList, PrintInt);

    int data1[] = { 1, 2, 3, 4 };
    for (int i = 0; i < 4; i++) {
        TestPrintOperation(pList, eInsert, data1[i], eFront);
    }
    TestPrintOperation(pList, eLook, 0, eFront);
    TestPrintOperation(pList, eLook, 0, eBack);
    TestPrintOperation(pList, eDelete, 0, eBack);

    printf("\nUsing input {5 6 7}\t\t");
    PrintList(pList, PrintInt);
    int data2[] = { 5, 6, 7 };
    for (int i = 0; i < 3; i++) {
        TestPrintOperation(pList, eInsert, data2[i], eFront);
    }
    TestPrintOperation(pList, eLook, 0, eBack);
    TestPrintOperation(pList, eLook, 0, eFront);

    int nodeCount = pList->nodeCount;
    for (int i = 0; i < nodeCount; i++) {
        TestPrintOperation(pList, eDelete, 0, (i % 2 == 0) ? eFront : eBack);
    }
    TestPrintOperation(pList, eLook, 0, eBack);
    TestPrintOperation(pList, eLook, 0, eFront);

}
ListData TestExamineNode(LinkedList* pList, eWhere where)
{
    if (pList->nodeCount == 0) {
        //return *CreateData(INT_MIN);
        return INT_MIN;
    }
    ListNode* pNode;
    switch (where) {
        case eFront: pNode = GetNode(pList, 0); break;
        case eBack: pNode = GetNode(pList, pList->nodeCount); break;
    }
    ListData data = *(pNode->pData); // derefernce the pData pointer to get the value.!!
    return data;
}
void TestCreateNodeAndInsert(LinkedList* pList, ListData data, eWhere where)
{
    ListData* pData = CreateData(data);
    ListNode* pNode = CreateNode(pData);

    switch (where)

    {
        case eFront: InsertNodeToFront(pList, pNode); break;
    }
}
ListData TestRemoveNodeAndFree(LinkedList* pList, eWhere where)
{
    ListNode* pNode;
    switch (where)
    {
        case eFront: pNode = RemoveNodeFromFront(pList); break;
        case eBack: pNode = RemoveNodeFromBack(pList); break;;
    }
    ListData data = *(pNode->pData);
    DeleteNode(pNode);

    return data;

}
void TestPrintOperation(LinkedList* pList, eAction action, ListData data, eWhere where)
{
    switch (action) {
        case eLook:
            data = TestExamineNode(pList, where);
            printf("Get %s node, see [%2d].\t", where == eFront ? "front" : "back", data);
            break;
        case eInsert:
            printf("Insert [%2d] to %s.\t\t", data, where == eFront ? "front" : "back");
            TestCreateNodeAndInsert(pList, data, where);
            break;
        case eDelete:
            data = TestRemoveNodeAndFree(pList, where);
            printf("Remove [%2d] from %s.\t\t", data, where == eFront ? "front" : "back");
            break;
    }
    PrintList(pList, PrintInt);

}

/*********************************************************/
/*********************************************************/
void PrintNode(ListNode* pNode, void(*__printData)(ListData* pData))
{
    __printData(pNode->pData);
}
void PrintInt(int* i)
{
    printf("%2d ", *i); //*i dereferences the pointer to the integer
}
void DeleteNode(ListNode* pNode)
{
    free(pNode->pData);
    free(pNode);
}
void PrintList(LinkedList* pList, void (*__printData)(ListData* pData))
{
    printf("List has %2d entries: [ ", Size(pList));
    ListNode* pCurr = pList->pFirstNode;
    while (pCurr != NULL) {
        PrintNode(pCurr, __printData);
        pCurr = pCurr->pNext;
    }
    printf(" ]\n");
}
//this creates a pointer to the ListData provided... (which is an alias for an int)
ListData* CreateData(ListData d)
{
    ListData* pData = (ListData*)calloc(1, sizeof(ListData));
    if (pData == NULL) { OutOfStorage(); }

    *pData = d;
    return pData;
}
ListNode* GetNode(LinkedList* pList, int pos)
{
    ListNode* pCurr = pList->pFirstNode;
    if (pCurr == NULL) {
        return pList->pFirstNode; //This just return NULL
    }
    if (pos == 0) {
        return pList->pFirstNode;
    }
    else {
        int i = 0;
        while (pCurr->pNext != NULL) {
            if (i == pos) { return pCurr; }
            i++;
            pCurr = pCurr->pNext;
        }
        return pCurr;
    }
}
ListNode* RemoveNodeFromBack(LinkedList* pList)
{
    ListNode* pCurr = pList->pFirstNode;
    ListNode* pPrev = NULL;

    //Empty List
    if (IsEmpty(pList)) // list is empty
    {
        return NULL;
    }
    //Single Node is an exception case. Need to NULL out the pFirstNode
    else if (pList->nodeCount == 1) {
        ListNode* lastNode = pList->pFirstNode;
        pList->pFirstNode = NULL;
        pList->nodeCount--;
        return lastNode;
    }
    else {
        while (pCurr->pNext != NULL)
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
        pPrev->pNext = NULL;
        pList->nodeCount--;

        return pCurr;
    }
}
ListNode* RemoveNodeFromFront(LinkedList* pList)
{
    if (IsEmpty(pList)) { return NULL; }
    ListNode* pCurr = pList->pFirstNode;
    pList->pFirstNode = pList->pFirstNode->pNext;
    pList->nodeCount--;

    return pCurr;
}
ListNode* CreateNode(ListData* pData)
{
    ListNode* pNode = (ListNode*)calloc(1, sizeof(ListNode));
    pNode->pData = pData;

    return pNode;

}
void InsertNodeToBack(LinkedList* pList, ListNode* pNode)
{
    if (IsEmpty(pList)) {
        pList->pFirstNode = pNode;
    }
    else {
        ListNode* pCurr = pList->pFirstNode;
        while (pCurr->pNext != NULL) {
            pCurr = pCurr->pNext; //move the current pointer from front to back
        }
        pCurr->pNext = pNode;
    }
    pList->nodeCount++;
}
/* Exisint First Node becomes Next Node and incoming Node becomes FirstNode*/
void InsertNodeToFront(LinkedList* pList, ListNode* pNode)
{
    ListNode* pNext = pList->pFirstNode;
    pList->pFirstNode = pNode;
    pNode->pNext = pNext;
    pList->nodeCount++;
}
bool IsEmpty(LinkedList* pList)
{
    return (pList->nodeCount == 0);
}
/* Allocate storage for a linked list struct and return pointer.*/
LinkedList* CreateLinkedList()
{
    LinkedList* pList = (LinkedList*)calloc(1, sizeof(LinkedList));
    if (pList == NULL) { OutOfStorage(); }
    return pList;
}
int Size(LinkedList* pList)
{
    return pList->nodeCount;
}
/* print to screen and exit program when out of memory*/
void OutOfStorage(void)
{
    fprintf(stderr, "\n### FATAL RUNTIME ERROR ### No Memory Available\n\n");
    exit(EXIT_FAILURE);
}