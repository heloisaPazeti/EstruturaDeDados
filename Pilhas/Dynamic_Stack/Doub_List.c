#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Doub_List.h"

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

//////////////////////////////////////////// MÉTODOS DE ALTERAÇÃO

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

void List_Destroy(List **L_ref)
{
    List *L = *L_ref;
    Node *p = L -> begin;
    Node *aux = NULL;

    while(p != NULL)
    {
            aux = p;
            p = p -> next;
            free(aux);
    }

    free(L);
    *L_ref = NULL;
}

void List_AddLast(List *L, int val)
{
    Node *p = Node_Create(val);
    p -> prev = L -> end;

    if(List_IsEmpty(L))
    {
        L -> begin = p;
    }
    else
    {
        L -> end -> next = p;
    }

    L -> end = p;
    L -> size++;
}

void List_RemoveLast(List *L)
{
    if(!List_IsEmpty(L))
    {
            Node *p = L -> end;

            if(L -> begin == L -> end)
            {
                    L -> begin = L -> end = NULL;
            }
            else
            {
                    L -> end = L -> end -> prev;
                    L -> end -> next = NULL;
            }

            free(p);
            L -> size--;
    }
}

//////////////////////////////////////////// HELPERS

bool List_IsEmpty(const List *L)
{
    return (L -> size <= 0);
}

size_t List_Size(const List *L)
{
    return L -> size;
}

int List_GetLastValue(const List *L)
{
    if(List_IsEmpty(L))
    {
            printf("A lista está vazia...");
            exit(EXIT_FAILURE);
    }

    return L -> end -> val;
}

int List_GetSize(const List *L)
{
    return L -> size;
}

void List_Print(const List *L)
{
    Node *p = L->begin;

    printf("\nL ->");
    while(p != NULL)
    {
        printf(" %d ->", p -> val);
        p = p -> next;
    }

    printf(" NULL");

    printf("\nBEGIN: %d", L -> begin -> val);
    printf("\nEND: %d", L -> end -> val);
    printf("\nSIZE: %d\n", List_GetSize(L));
}
