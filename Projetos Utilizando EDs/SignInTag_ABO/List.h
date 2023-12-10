#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 100

//////////////////////////////////////////// STRUCTS

typedef struct _doubly_node Node;
typedef struct _doubly_List List;
typedef struct _info Info;

typedef Info TypeData;

//////////////////////////////////////////// CONSTRUCTORS / DESTROY

Node *Node_Create(TypeData val);
List *List_Create();
void List_Destroy(List **L_ref);

//////////////////////////////////////////// ADD FIRST / LAST

void List_AddFirst(List *L, TypeData val);
void List_AddLast(List *L, TypeData val);
void List_AddInOrder(List *L, TypeData val);

//////////////////////////////////////////// ADD BEFORE /  AFTER CURSOR

void List_AddBefore_Cursor(List *L, TypeData val);
void List_AddAfter_Cursor(List *L, TypeData val);

//////////////////////////////////////////// ADD BEFORE /  AFTER POSITION

void List_Add_Position(List *L, TypeData val, int position, bool isBefore);

//////////////////////////////////////////// REMOVE CURSOR / REMOVE VALUE

void List_Remove(List *L, TypeData val);
void List_RemoveCursor(List *L);

//////////////////////////////////////////// GO TO VALUE

void List_GoStart(List *L);
void List_GoEnd(List *L);
void List_GoPrev(List *L);
void List_GoNext(List *L);

//////////////////////////////////////////// SEARCH

int List_Search(List *L, char tag[10]);

//////////////////////////////////////////// HELPERS

bool List_IsEmpty(List *L);
void List_Print(List *L);
void List_PrintData(List *L);
int List_GetSize(List *L);

#endif // LIST_H_INCLUDED
