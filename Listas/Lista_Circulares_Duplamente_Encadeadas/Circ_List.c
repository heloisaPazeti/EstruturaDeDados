#include "Circ_List.h"
#include <stdbool.h>
#include <stdio.h>

////////////////////////////////////////// STRUCTS

typedef struct _circ_node
{
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;

} CircNode;

typedef struct _circ_list
{
    struct _circ_node *begin;
    struct _circ_node *end;
    int size;

} CircList;

////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

CircList *CircList_Create()
{
    CircList *L = (CircList *)calloc(1, sizeof(CircList ));

    L -> begin = NULL;
    L -> end = NULL;
    L -> size = 0;

    return L;
}

CircNode *CircNode_Create(int val)
{
    CircNode *node = (CircNode*)calloc(1, sizeof(CircNode));

    node -> val = val;
    node -> next = node;
    node -> prev = node;

    return node;
}

void CircNode_Destroy(CircNode **cnode_ref)
{
    CircNode *cNode = *cnode_ref;
    free(cNode);
    *cnode_ref = NULL;
}

void CircList_Destroy(CircList **L_ref)
{
    CircList *L = *L_ref;
    CircNode *p = L -> begin;
    CircNode *aux = NULL;

    for(int i = 0; i < L -> size; i++)
    {
        aux = p;
        p = p -> next;
        CircNode_Destroy(&aux);
    }

    free(L);
    *L_ref = NULL;
}

////////////////////////////////////////// ADDING AND REMOVING

void CircList_AddFirst(CircList *L, int val)
{
		CircNode *p = CircNode_Create(val);

		if(CircList_IsEmpty(L))
		{
				L -> end = p;
		}
		else
		{
				p -> next = L -> begin;
				L -> begin -> prev = p;
				p -> prev = L -> end;
				L -> end -> next = p;
		}

		L -> begin = p;
		L -> size++;
}

void CircList_AddLast(CircList *L, int val)
{
    CircNode *p = CircNode_Create(val);

    if(CircList_IsEmpty(L))
    {
        L -> begin = p;
    }
    else
    {
        L -> end -> next = p;
        p -> prev = L -> end;
        L -> begin -> prev = p;
        p -> next = L -> begin;
    }

    L -> end = p;
    L -> size++;
}

void CircList_Remove(CircList *L, int val)
{
    if(!CircList_IsEmpty(L))
    {
        CircNode *p = L -> begin;

        if(L -> begin -> val == val)
        {
            if(L -> begin == L -> end)
            {
                L -> begin = L -> end = NULL;
            }
            else
            {
                L -> begin = p -> next;
                L -> begin -> prev = L -> end;
                L -> end -> next = L -> begin;
            }

            CircNode_Destroy(&p);
            L -> size--;
        }
        else
        {
            p = p -> next;

            while(p != L -> begin)
            {
                if(p -> val == val)
                {
                    if(L -> end == p)
                    {
                        L -> end = p -> prev;
                    }

                    p -> prev -> next = p -> next;
                    p -> next -> prev = p -> prev;
                    CircNode_Destroy(&p);
                    L -> size--;
                    break;
                }
                else
                {
                    p = p -> next;
                }
            }
        }
    }
}

////////////////////////////////////////// HELPERS

bool CircList_IsEmpty(CircList *L)
{
    return L -> size == 0;
}

void CircList_Print(const CircList *L)
{
    CircNode *p = L -> begin;

    printf("\nL ->");

    for(int i = 0; i < L -> size; i++)
    {
        printf(" %d ->", p -> val);
        p = p -> next;
    }

    printf(" NULL");
    printf("\nBEGIN: %d", L -> begin -> val);
    printf("\nEND: %d", L -> end -> val);
    printf("\nSIZE: %d\n", L -> size);
}
