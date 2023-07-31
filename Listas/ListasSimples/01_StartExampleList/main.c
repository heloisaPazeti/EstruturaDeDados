#include <stdio.h>
#include <stdlib.h>

//////////////////////////////// STRUCT DOS NÓS

typedef struct _snode {
    int val;
    struct _snode *next;
} SNode;

//////////////////////////////// LISTA INICIAL

typedef struct _linked_list {
    SNode *begin;
} LinkedList;

//////////////////////////////// CREATE METHODS

LinkedList *LinkedListCreate()
{
    LinkedList *L = (LinkedList*)calloc(1, sizeof(LinkedList));
    L -> begin = NULL;

    return L;
}

SNode *SnodeCreate(int val)
{
    SNode *snode = (SNode*)calloc(1, sizeof(SNode));
    snode -> val = val;
    snode -> next = NULL;

    return snode;
}

////////////////////////////////

int main()
{
    printf("Hello world!\n");
    return 0;
}
