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
void Tree_DeteleNode(Node* node);
bool Tree_Delete(Node** root);

///////////////////////////////////// INSERT

Node* Tree_Insert(TypeData info, Node* root);

///////////////////////////////////// REMOVE

bool Tree_Remove(Node** root, TypeData info);
Node* Tree_RemoveCurrent(Node* current);

///////////////////////////////////// READ AND SEARCH

bool Tree_PrintInOrder(Node *node);
bool Tree_PrintPreOrder(Node *node);
bool Tree_PrintPosOrder(Node *node);
int Tree_Search(Node** root, TypeData value);
void Tree_SearchPreOrder(Node** root, TypeData value, bool* found);
Node* Tree_SeachChildOrParent(Node *root, int isParent, TypeData value);

///////////////////////////////////// HELPERS

bool Tree_IsEmpty(Node** root);
int Tree_TotalNodes(Node** root);
int Tree_Height(Node** root);
Node* Tree_FindMaxNode(Node* root, int isParent);

#endif // BST_H_INCLUDED
