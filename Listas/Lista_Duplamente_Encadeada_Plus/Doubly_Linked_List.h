#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED

#include <stdbool.h>

#define maxSize 100

typedef char TypeData[maxSize];

//////////////////////////////////////////// STRUCTS

typedef struct _doubly_node Node;
typedef struct _doubly_List List;

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

///Returns number of nodes until find data (pos)
///Returns pos > 0 if found data  ; set cursor on value
///Returns pos < 0 if haven't found data
int List_SearchPos(List *L, TypeData val);

///Returns node if found or NULL if not  ; set cursor on value  (if found)
Node* List_SearchNode(List *L, TypeData val);

//////////////////////////////////////////// HELPERS

bool List_IsEmpty(List *L);
void List_Print(List *L);
int List_GetSize(List *L);



#endif // DOUBLY_LINKED_LIST_H_INCLUDED
