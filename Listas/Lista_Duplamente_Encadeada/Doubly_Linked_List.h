#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED

typedef struct _doubly_node Node;
typedef struct _doubly_List List;

Node *Node_Create(int val);
List *List_Create();

void List_AddFirst(List *L, int val);
void List_AddLast(List *L, int val);

void List_Print(List *L);
int List_GetSize(List *L);

void List_Remove(List *L, int val);

#endif // DOUBLY_LINKED_LIST_H_INCLUDED
