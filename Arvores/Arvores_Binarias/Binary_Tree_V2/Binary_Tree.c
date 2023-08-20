#include "Binary_Tree.h"

/////////////////////////////////////////// STRUCTS

typedef struct _node
{
    int val;
    struct _node *right;
    struct _node *left;

}Node;

typedef struct _tree
{
    struct _node *mainRoot;
    int size;

} Tree;

/////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

Node *Node_Create(int val)
{
    Node *p = (Node*)calloc(1, sizeof(Node));
    p -> val = val;
    p -> right = NULL;
    p -> left = NULL;

    return p;
}

Tree *Tree_Create()
{
    Tree *T = (Tree*)calloc(1, sizeof(Tree));
    T -> mainRoot = NULL;
    T -> size = 0;

    return T;
}

/////////////////////////////////////////// INSERT AND REMOVE

void Tree_Insert(Tree *T, int val)
{
    Node *p = Node_Create(val);
    if(Tree_IsEmpty(T))
    {
        T -> mainRoot = p;
    }
    else
    {
        Node *aux = T -> mainRoot;

        while(aux != NULL)
        {
            if(aux -> val < val)
            {
                if(aux -> right == NULL)
                {
                    aux -> right = p;
                    aux = NULL;
                }
                else
                {
                    aux = aux -> right;
                }
            }
            else
            {
                if(aux -> left == NULL)
                {
                    aux -> left = p;
                    aux = NULL;
                }
                else
                {
                    aux = aux -> left;
                }
            }
        }
    }
}

/////////////////////////////////////////// INSERT AND REMOVE - V2

Node* Tree_Insert_V2(Tree *T, Node *root, int val)
{
    if(root == NULL)
    {
        Node *p = Node_Create(val);
        T -> mainRoot = p;
        return p;
    }
    else
    {
        if(val > root -> val)
        {
            root -> right = Tree_Insert_V2(T, root -> right, val);
        }
        else
        {
            root -> left = Tree_Insert_V2(T, root -> left, val);
        }

        return root;
    }
}

/////////////////////////////////////////// HELPERS

bool Tree_IsEmpty(Tree *T)
{
    return T -> size == 0;
}
