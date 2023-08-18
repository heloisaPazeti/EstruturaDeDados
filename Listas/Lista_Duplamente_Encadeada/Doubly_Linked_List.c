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

void List_Remove(List *L, int val)
{
    if(!List_IsEmpty(L))
    {
        Node *p = L -> begin;

        if(L -> begin -> val == val)    //IF IT'S FIRST ELEMENT
        {
            L -> begin = p -> next;

            if(L -> end == p)   //IF THERE'S ONLY ONE ELEMENT
            {
                L-> end = NULL;
            }
            else    // IF THERE'S MORE ELEMENTS
            {
                L -> begin -> prev = NULL;
            }

            free(p);
            L -> size--;
        }
        else //IF IT'S NOT THE FIRST ELEMENT
        {
            p = p -> next;

            while(p != NULL)
            {
                if(p -> val == val) //P IT'S THE ELEMENT TO REMOVE
                {
                    p -> prev -> next = p -> next;
                    if(L -> end == p) //IF IT'S AT THE END
                    {
                        L -> end = p -> prev;
                    }
                    else //IF IT'SS IN THE MIDDLE
                    {
                        p -> next -> prev = p -> prev;
                    }

                    free(p);
                    p = NULL; //TO BE SURE THAT WHILE WILL STOP
                    L -> size--;
                }
                else //P IT'S NOT THE RIGHT ELEMENT
                {
                    p = p -> next;
                }
            }
        }
    }
}

//////////////////////////////////////////// HELPERS

int List_GetSize(List *L)
{
    return L -> size;
}

void List_Print(List *L)
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
