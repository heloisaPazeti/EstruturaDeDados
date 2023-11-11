#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Doubly_Linked_List.h"

//////////////////////////////////////////// STRUCTS

typedef struct _doubly_node
{
    TypeData val;
    struct _doubly_node *prev;
    struct _doubly_node *next;

} Node;

typedef struct _doubly_List
{
    Node *begin;
    Node *end;
    Node *cursor;
    int size;

} List;

//////////////////////////////////////////// CONSTRUCTORS / DESTROY

Node *Node_Create(TypeData val)
{
    Node *node = (Node*)calloc(1, sizeof(Node));

    node -> next = NULL;
    node -> prev = NULL;

    strcpy(node -> val, val); ///ALTERAR AQUI CASO QUEIRA COLOCAR COMO INT OU OUTROS RSRSRS
                                ///node -> val = val;

    return node;
}

List *List_Create()
{
    List *L = (List*)calloc(1, sizeof(List));

    L -> begin = NULL;
    L -> end = NULL;
    L -> cursor = NULL;
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

//////////////////////////////////////////// ADD FIRST / LAST

void List_AddFirst(List *L, TypeData val)
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

    L -> begin = L -> cursor = p;
    L -> size++;
}

void List_AddLast(List *L, TypeData val)
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

    L -> end = L -> cursor = p;
    L -> size++;
}

void List_AddInOrder(List *L, TypeData val)
{
    if(L != NULL)
    {
        if(L -> cursor == NULL || List_IsEmpty(L))
        {
            List_AddFirst(L, val);
        }
        else
        {
            Node *current = L -> begin;

            while(current != NULL)
            {
                L -> cursor = current;

                if(strncmp(current -> val, val, maxSize) > 0)
                {
                    List_AddBefore_Cursor(L, val);
                    return;
                }
                else if(current == L -> end)
                {
                    List_AddAfter_Cursor(L, val);
                    return;
                }

                current = current -> next;
            }
        }
    }
    else
        printf("\n\n>> EMPTY LIST IN ADD IN ORDER <<\n\n");
}

//////////////////////////////////////////// ADD BEFORE /  AFTER CURSOR

void List_AddBefore_Cursor(List *L, TypeData val)
{
    if(L != NULL)
    {
        if(L -> cursor == NULL || List_IsEmpty(L) || L -> cursor == L -> begin)
        {
            List_AddFirst(L, val);
        }
        else
        {
            Node *p = Node_Create(val);

            p -> next = L -> cursor;
            p -> prev = L -> cursor -> prev;
            L -> cursor -> prev -> next = p;
            L -> cursor -> prev = p;
            L -> cursor = p;

            L -> size++;
        }
    }
    else
    {
        printf(">> ESSA LISTA ESTA NULA. CRIE UMA NOVA LISTA. <<\n");
    }

}

void List_AddAfter_Cursor(List *L, TypeData val)
{
    if(L != NULL)
    {
        if(L -> cursor == NULL || List_IsEmpty(L) || L -> cursor == L -> end)
        {
            List_AddLast(L, val);
        }
        else
        {
            Node *p = Node_Create(val);

            p -> next = L -> cursor -> next;
            p -> prev = L -> cursor;
            L -> cursor -> next -> prev = p;
            L -> cursor -> next = p;
            L -> cursor = p;

            L -> size++;
        }
    }
    else
    {
        printf(">> ESSA LISTA ESTA NULA. CRIE UMA NOVA LISTA. <<\n");
    }
}

//////////////////////////////////////////// ADD BEFORE /  AFTER POSITION

void List_Add_Position(List *L, TypeData val, int position, bool isBefore)
{
    if(position < L -> size)
    {
        Node *p = L -> begin;

        for(int i = 0; i < position; i++)
        {
            p = p -> next;
        }

        L -> cursor = p;

        if(isBefore)
            List_AddBefore_Cursor(L, val);
        else
            List_AddAfter_Cursor(L, val);
    }
    else
    {
        printf("ESSA POSICAO NAO EXISTE NA LISTA, TENTE NOVAMENTE.\n\n");
    }

}


//////////////////////////////////////////// REMOVE CURSOR / REMOVE VALUE

void List_Remove(List *L, TypeData val)
{
    if(!List_IsEmpty(L))
    {
        Node *p = L -> begin;


        /// if(L -> begin -> val == val) -- HERE NEEDS TO CHANGE IF TYPEDATA IS NOT CHAR
        if(strcmp(L -> begin -> val, val) == 0)
        {
            L -> begin = p -> next;

            if(L -> end == p)
            {
                L -> end = L -> cursor = NULL;
            }
            else
            {
                L -> begin -> prev = NULL;
                L -> cursor = L -> begin;
            }

            free(p);
            L -> size--;
        }
        else
        {
            p = p -> next;

            while(p != NULL)
            {
                /// if(p -> val == val) -- HERE NEEDS TO CHANGE IF TYPEDATA IS NOT CHAR
                if(strcmp(p ->val , val) == 0)
                {
                    p -> prev -> next = p -> next;
                    if(L -> end == p)
                    {
                        L -> end = p -> prev;
                    }
                    else
                    {
                        p -> next -> prev = p -> prev;
                    }

                    L -> cursor = p -> prev;
                    free(p);
                    p = NULL;
                    L -> size--;
                }
                else
                {
                    p = p -> next;
                }
            }
        }
    }
}

void List_RemoveCursor(List *L)
{
    if(!List_IsEmpty(L) && L -> cursor != NULL && L != NULL)
    {
        printf("\nCURSOR ATUAL: %s\n", L -> cursor -> val);
        Node *p = L -> cursor;

        if(L -> cursor == L -> begin)
        {
            if(L -> cursor == L -> end)
                L -> end = NULL;
            else
                L -> cursor -> next -> prev = NULL;

            L -> cursor = L -> begin = L -> cursor -> next;
        }
        else
        {
            if(L -> end == L -> cursor)
            {
                L -> end = L -> cursor -> prev;
            }
            else
            {
                L -> cursor -> next -> prev = L -> cursor -> prev;
            }

            L -> cursor -> prev -> next = L -> cursor -> next;
            L -> cursor = L -> cursor -> prev;
        }

        free(p);
        L -> size--;
        printf("\nCURSOR NOVO: %s\n", L -> cursor -> val);
    }
    else
    {
        printf(">> ESSA LISTA ESTA NULA. CRIE UMA NOVA LISTA. <<\n");
    }
}

//////////////////////////////////////////// GO TO VALUE

void List_GoStart(List *L)
{
    L -> cursor = L -> begin;
    printf("\n");
    List_Print(L);
}

void List_GoEnd(List *L)
{
    L -> cursor = L -> end;
    printf("\n");
    List_Print(L);
}

void List_GoPrev(List *L)
{
    if(L -> cursor != L -> begin && L -> cursor -> prev != NULL)
        L -> cursor = L -> cursor -> prev;
    else
        printf("PARECE QUE NAO EXISTE UM NO ANTERIOR");

    printf("\n");
    List_Print(L);
}

void List_GoNext(List *L)
{
    if(L -> cursor != L -> end && L -> cursor -> next != NULL)
        L -> cursor = L -> cursor -> next;
    else
        printf("PARECE QUE NAO EXISTE UM NO POSTERIOR");

    printf("\n");
    List_Print(L);
}

//////////////////////////////////////////// SEARCH

int List_SearchPos(List *L, TypeData val)
{
    if(L == NULL)
        return 0;

    int pos = 1;
    Node* current = L->begin;

    while(current != NULL)
    {
        if(strncmp(val, current -> val, maxSize) == 0)
        {
            L -> cursor = current;
            return pos;
        }


        current = current -> next;
        pos++;
    }

    return (-1*pos);
}

Node* List_SearchNode(List *L, TypeData val)
{
    if(L == NULL)
        return NULL;

    Node* current = L->begin;

    while(current != NULL)
    {
        if(strncmp(val, current -> val, maxSize) == 0)
        {
            L -> cursor = current;
            return current;
        }


        current = current -> next;
    }

    return NULL;
}

//////////////////////////////////////////// HELPERS

bool List_IsEmpty(List *L)
{
    return (L -> size <= 0);
}

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
        printf(" %s ->", p -> val);
        p = p -> next;
    }

    printf(" NULL");

    printf("\nBEGIN: %s", L -> begin -> val);
    printf("\nEND: %s", L -> end -> val);
    printf("\nCURSOR: %s", L -> cursor -> val);
    printf("\nSIZE: %d\n", List_GetSize(L));
}
