#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *pNewNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    if(pNewNode == NULL)
        return NULL;
    else
    {
        pNewNode->next = NULL;
        return pNewNode;
    }
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj == NULL)
        return -1;
    MyLinkedList *pTail = obj;
    while(pTail != NULL)
    {
        if(index == 1)
            return pTail->val;
        index--;
        pTail = pTail->next;
    }
    
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj == NULL)
    {
        obj->val = val;
        obj->next = NULL;
        return;
    }
    MyLinkedList *pNewNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    pNewNode->val = val;
    pNewNode->next = obj;
    obj = pNewNode;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if(obj == NULL)
    {
        obj->val = val;
        obj->next = NULL;
        return;
    }
    MyLinkedList *pNewNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    MyLinkedList *pTail = obj;
    while(pTail->next != NULL)
    {
        pTail = pTail->next;
    }
    pNewNode->val = val;
    pNewNode->next = NULL;
    pTail->next = pNewNode;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(obj == NULL)
        return;
    MyLinkedList *pNewNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    MyLinkedList *pCur = obj;
    MyLinkedList *pPre = obj;
    while(pCur != NULL)
    {
        if(index == 1)
        {
            pNewNode->val = val;
            pNewNode->next = pCur;
            pPre->next = pNewNode;
            return;
        }
        index--;
        pPre = pCur;
        pCur = pCur->next;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *pCur = obj;
    MyLinkedList *pPre = obj;
    while(pCur != NULL)
    {
        if(index == 1)
        {
            pPre->next = pCur->next;
            free(pCur);
            return;
        }
        index--;
        pPre = pCur;
        pCur = pCur->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *pTail = obj;
    MyLinkedList *pTemp;
    while(pTail != NULL)
    {
        pTemp = pTail->next;
        free(pTail);
        pTail = pTemp;
    }
}

int main()
{
	struct MyLinkedList* obj = myLinkedListCreate();
	myLinkedListAddAtHead(obj, 1);
	myLinkedListAddAtTail(obj, 3);
	myLinkedListAddAtIndex(obj, 2, 2);
	printf("val = %d\n", myLinkedListGet(obj, 2));
	myLinkedListDeleteAtIndex(obj, 2);
	printf("val = %d\n", myLinkedListGet(obj, 2));
	myLinkedListFree(obj);
	return 0;
}