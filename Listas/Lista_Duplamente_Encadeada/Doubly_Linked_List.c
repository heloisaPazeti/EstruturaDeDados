#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Doubly_Linked_List.h"

//////////////////////////////////////////// STRUCTS

typedef struct _doubly_node
{
    int val;
    struct _doubly_node *prev;
    struct _doubly_node *next;

} Node;

typedef struct _doubly_List
{
    Node *begin;
    Node *end;
    int size;

} List;

//////////////////////////////////////////// MÉTODOS PRIVADOS

bool List_IsEmpty(List *L)
{
    return (L -> size <= 0);
}

//////////////////////////////////////////// MÉTODOS PÚBLICOS

Node *Node_Create(int val)
{
    Node *node = (Node*)calloc(1, sizeof(Node));

    node -> next = NULL;
    node -> prev = NULL;
    node -> val = val;

    return node;
}

List *List_Create()
{
    List *L = (List*)calloc(1, sizeof(List));

    L -> begin = NULL;
    L -> end = NULL;
    L -> size = 0;

    return L;
}

void List_AddFirst(List *L, int val)
{
    Node *p = Node_Create(val);
    p -> next = L -> begin;

    if(List_IsEmpty(L))
    {
        L -> end = p;
    }
    else
    {
        L -> begin -> prev = p;
    }

    L -> begin = p;
    L -> size++;
}

void List_Print(List *L)
{
    Node *p = L->begin;

    printf("L ->");
    while(p != NULL)
    {
        printf(" %d ->", p -> val);
        p = p -> next;
    }

    printf(" NULL");
}
