#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef char TypeData[maxSize];
typedef float TypeData;

///////////////////////////////////// STRUCTS

typedef struct _node Node;

///////////////////////////////////// CREATE AND DESTROY

Node* Tree_CreateNode(TypeData info);
void Tree_Destroy(Node* node);
bool Tree_RootDestroy(Node** root);

///////////////////////////////////// INSERT

Node* Tree_Insert(TypeData info, Node* root);

///////////////////////////////////// REMOVE

bool Tree_Remove(Node** root, TypeData info);
Node* Tree_RemoveCurrent(Node* current);

///////////////////////////////////// READ AND SEARCH

bool Tree_PrintInOrder(Node *node);
bool Tree_PrintPreOrder(Node *node);
bool Tree_PrintPosOrder(Node *node);

///////////////////////////////////// HELPERS

#endif // BST_H_INCLUDED
