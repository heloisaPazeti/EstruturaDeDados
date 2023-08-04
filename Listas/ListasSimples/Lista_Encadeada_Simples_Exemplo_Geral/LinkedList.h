#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdbool.h>

///////////////////////////////////////// DEFININDO STRUCT(S)

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

///////////////////////////////////////// DEFININDO MÉTODO(S) PRIVADO(S)

bool LinkedList_IsEmpty(LinkedList *L);

///////////////////////////////////////// DEFININDO MÉTODO(S) DE CRIAÇÃO

SNode *SNode_Create(int val);
LinkedList *LinkedList_Create();

///////////////////////////////////////// DEFININDO MÉTODO(S) DE INSERÇÃO

void LinkedList_AddFirst(LinkedList *L, int val);
void LinkedList_AddLast(LinkedList *L, int val);

///////////////////////////////////////// DEFININDO MÉTODO(S) DE REMOÇÃO

void LinkedList_Remove(LinkedList *L, int val);

///////////////////////////////////////// DEFININDO OUTRO(S) MÉTODO(S)

void LinkedList_Print(LinkedList *L);

#endif
