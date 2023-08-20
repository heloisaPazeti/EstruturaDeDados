#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/////////////////////////////////////////// STRUCTS

typedef struct _node Node;
typedef struct _tree Tree;

/////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

Node *Node_Create(int val);
Tree *Tree_Create();
void Tree_Destroy(Tree *T);

/////////////////////////////////////////// INSERT AND REMOVE

void Tree_Insert(Tree *T, int val);

/////////////////////////////////////////// INSERT AND REMOVE - V2

Node* Tree_Insert_V2(Tree *T, Node *root, int val);

/////////////////////////////////////////// HELPERS

bool Tree_IsEmpty(Tree *T);

#endif // BINARY_TREE_H_INCLUDED
