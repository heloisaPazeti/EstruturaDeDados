#ifndef RED_BLACK_H_INCLUDED
#define RED_BLACK_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node* Remove_RB(Tree* tree, TypeData info);

//////////////////////////////////// ROTATE

Node* RR_Rotate(Tree* tree, Node* a);
Node* LL_Rotate(Tree* tree, Node* a);

//////////////////////////////////// SEARCH

Node* Find_Node(Tree* tree, TypeData info);
Node* Find_Successor(Node* node);
Node* Find_Predecessor(Node* node);
Node* Find_Substitute(Tree* tree, TypeData info);
Node* Find_Uncle(Node* node);
Node* Find_Sibling(Node* node);

//////////////////////////////////// PRINTS

void PrintNode(Node* node);
void Print_InOrder(Node* root);
void Print_PreOrder(Node* root);
void Print_PosOrder(Node* root);

//////////////////////////////////// HELPERS

void Delete_Leaf(Node* node);
void Swap_Colors(Node* a, Node* b);
void Swap_Values(Node* a, Node* b);
Node* Has_RedChildren(Node* node);
Node* Has_AnyChildren(Node* node);
bool IsOnLeft(Node* node);
bool IsLeaf(Node* node);
void ShowTotalNodes(Tree* tree);


#endif // RED_BLACK_H_INCLUDED
