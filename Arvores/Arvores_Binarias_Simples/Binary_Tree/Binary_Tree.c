#include "Binary_Tree.h"

/////////////////////////////////////////// STRUCTS

typedef struct _node
{
    int val;
    struct _node *right;
    struct _node *left;

} Node;

/////////////////////////////////////////// CONSTRUCTORS AND DESTROYERS

Node *Node_Create(int val)
{
    Node *p = (Node*)calloc(1, sizeof(Node));
    p -> val = val;
    p -> right = NULL;
    p -> left = NULL;

    return p;
}

/////////////////////////////////////////// INSERT AND REMOVE

Node* Tree_Insert(Node *root, int val)
{
    if(root == NULL)
    {
        Node *p = Node_Create(val);
        return p;
    }
    else
    {
        if(val > root -> val)
        {
            root -> right = Tree_Insert(root -> right, val);
        }
        else
        {
            root -> left = Tree_Insert(root -> left, val);
        }

        return root;
    }
}
