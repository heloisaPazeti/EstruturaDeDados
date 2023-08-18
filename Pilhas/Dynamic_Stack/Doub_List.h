#ifndef DOUB_LIST_H_INCLUDED
#define DOUB_LIST_H_INCLUDED

typedef struct _doubly_node Node;
typedef struct _doubly_List List;

Node *Node_Create(int val);
List *List_Create();
void List_Destroy(List **L_ref);

void List_AddLast(List *L, int val);

void List_RemoveLast(List *L);

bool List_IsEmpty(const List *L);
size_t List_Size(const List *L);
int List_GetLastValue(const List *L);
int List_GetSize(const List *L);
void List_Print(const List *L);

#endif // DOUB_LIST_H_INCLUDED
