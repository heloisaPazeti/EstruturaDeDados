#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/////////////////////////////////////////// STRUCTS

typedef struct _node Node;

/////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

Node *Node_Create(int val);

/////////////////////////////////////////// INSERT AND REMOVE

Node* Tree_Insert(Node *root, int val);

/////////////////////////////////////////// HELPERS

#endif // BINARY_TREE_H_INCLUDED
