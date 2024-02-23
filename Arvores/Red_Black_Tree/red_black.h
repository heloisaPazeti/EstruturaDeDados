#ifndef RED_BLACK_H_INCLUDED
#define RED_BLACK_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

//typedef char TypeData[maxSize];
typedef int TypeData;

//////////////////////////////////// STRUCTS

typedef struct _rb_node
{
    TypeData info;
    int color;
    int quant;
    struct _rb_node *left, *right, *parent;

} Node;

typedef struct _rb_tree
{
    int quant;
    struct _rb_node *root;

} Tree;

//////////////////////////////////// CREATE AND DESTROY

Node* Create_Node(TypeData newInfo);
void Free_Node(Node* node);
void Free_RB(Tree* root);

//////////////////////////////////// FIX UP

Node* FixUp(Tree* tree, Node* newNode);

//////////////////////////////////// INSERT

Node* Insert_Node(TypeData info, Tree* tree);
Tree* Insert_RB(Tree* tree, TypeData info);

//////////////////////////////////// REMOVE

//////////////////////////////////// ROTATE

Node* RR_Rotate(Tree* tree, Node* a);
Node* LL_Rotate(Tree* tree, Node* a);

//////////////////////////////////// SEARCH

//////////////////////////////////// PRINTS

void PrintNode(Node* node);
void Print_InOrder(Node* root);

//////////////////////////////////// HELPERS

#endif // RED_BLACK_H_INCLUDED
