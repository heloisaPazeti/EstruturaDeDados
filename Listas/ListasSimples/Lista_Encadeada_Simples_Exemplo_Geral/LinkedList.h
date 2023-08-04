#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdbool.h>

///////////////////////////////////////// DEFININDO STRUCT(S)

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

///////////////////////////////////////// DEFININDO M�TODO(S) PRIVADO(S)

bool LinkedList_IsEmpty(LinkedList *L);

///////////////////////////////////////// DEFININDO M�TODO(S) DE CRIA��O

SNode *SNode_Create(int val);
LinkedList *LinkedList_Create();

///////////////////////////////////////// DEFININDO M�TODO(S) DE INSER��O

void LinkedList_AddFirst(LinkedList *L, int val);
void LinkedList_AddLast(LinkedList *L, int val);

///////////////////////////////////////// DEFININDO M�TODO(S) DE REMO��O

void LinkedList_Remove(LinkedList *L, int val);

///////////////////////////////////////// DEFININDO OUTRO(S) M�TODO(S)

void LinkedList_Print(LinkedList *L);

#endif
