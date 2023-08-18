#ifndef CIRC_LIST_H_INCLUDED
#define CIRC_LIST_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////// STRUCTS

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

CircList *CircList_Create();
CircNode *CircNode_Create(int val);

void CircNode_Destroy(CircNode **cnode_ref);
void CircList_Destroy(CircList **L_ref);

////////////////////////////////////////// ADDING AND REMOVING

void CircList_AddFirst(CircList *L, int val);
void CircList_AddLast(CircList *L, int val);

void CircList_Remove(CircList *L, int val);

////////////////////////////////////////// HELPERS

void CircList_Print(const CircList *L);
bool CircList_IsEmpty(CircList *L);

#endif // CIRC_LIST_H_INCLUDED
