#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////// DEFININDO STRUCTS

typedef struct _snode
{
    int val;
    struct _snode *next;
} SNode;

typedef struct _linked_list
{
    SNode *begin;
    SNode *end;
} LinkedList;

///////////////////////////////////////// DEFININDO MÉTODOS PRIVADOS

bool LinkedList_IsEmpty(LinkedList *L)
{
    return (L -> begin == NULL && L -> end == NULL);
}

///////////////////////////////////////// DEFININDO MÉTODOS PÚBLICOS

////////////////////////////// MÉTODO(S) DE CRIAÇÃO

SNode *SNode_Create(int val)
{
    SNode *node = (SNode*)calloc(1, sizeof(SNode));
    node -> val = val;
    node -> next = NULL;

    return node;
}

LinkedList *LinkedList_Create()
{
    LinkedList *L = (LinkedList*)calloc(1, sizeof(LinkedList));
    L -> begin = L -> end = NULL;

    return L;
}

////////////////////////////// MÉTODO(S) DE INSERÇÃO

void LinkedList_AddFirst(LinkedList *L, int val)
{
    SNode *p = SNode_Create(val);
    p -> next = L  -> begin;

    if(LinkedList_IsEmpty(L))
        L -> end = p;

    L -> begin = p;
}

void LinkedList_AddLast(LinkedList *L, int val)
{
    SNode *p = SNode_Create(val);

    if(LinkedList_IsEmpty(L))
    {
        L -> begin = L -> end = p;
    }
    else
    {
        L -> end -> next = p;
        L -> end = p;
    }
}

////////////////////////////// MÉTODO(S) DE REMOÇÃO

void LinkedList_Remove(LinkedList *L, int val)
{
    if(!LinkedList_IsEmpty(L))
    {
        SNode *prev = NULL;
        SNode *pos = L -> begin;

        while(pos != NULL && pos->val != val)
        {
            prev = pos;
            pos = pos -> next;
        }

        if(pos != NULL)
        {
            if(pos == L -> end)
            {
                L -> end = prev;
            }
            if(pos == L -> begin)
            {
                L -> begin = pos -> next;
            }
            else
            {
                prev -> next = pos -> next;
            }

            free(pos);
        }

    }
}

void LinkedList_Destroy(LinkedList **L)
{
    LinkedList *L_ref = *L;


    SNode *aux = NULL;
    SNode *p = L_ref -> begin;

    while(p != NULL)
    {
        aux = p;
        p = p -> next;

        free(aux);
    }

    free(L_ref);
    *L = NULL;
}

////////////////////////////// OUTRO(S) MÉTODO(S)

void LinkedList_Print(LinkedList *L)
{
    SNode *p = L -> begin;
    printf("L -> ");

    while(p != NULL)
    {
        printf("%d -> ", p -> val);
        p = p -> next;
    }

    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->end = NULL\n");
    }
    else {
        printf("L->end = %d\n", L->end->val);
    }

     puts("");
}
