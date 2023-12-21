#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef char TypeData[maxSize];

///////////////////////////////////// STRUCTS

typedef struct _avl_node Node;

///////////////////////////////////// CREATE AND DESTROY

Node** Create_AVL();
Node* Create_Node(TypeData newInfo);
void Free_Node(Node* node);
void Free_AVL(Node** root);

///////////////////////////////////// INSERT

Node* Insert_AVL(Node* root, TypeData info);

///////////////////////////////////// REMOVE

Node* Remove_AVL(Node* root, TypeData info);

///////////////////////////////////// ROTATE

Node* RR_Rotate(Node* a);
Node* LL_Rotate(Node* a);
Node* LR_Rotate(Node* a);
Node* RL_Rotate(Node* a);

///////////////////////////////////// SEARCH


///////////////////////////////////// HELPERS

int GetHeight(Node* node);
int Greater(int x, int y);
void Print_InOrder(Node* root);


#endif // AVL_H_INCLUDED
