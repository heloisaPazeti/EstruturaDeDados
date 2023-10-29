#include "BST.h"

///////////////////////////////////// STRUCTS

typedef struct _node
{
    TypeData info;
    int quant;
    struct _node *right;
    struct _node *left;

} Node;

///////////////////////////////////// CREATE AND DESTROY

Node* Tree_CreateNode(TypeData info)
{
    Node* leaf = (Node*) malloc(sizeof(Node));

    if(leaf == NULL)
        return NULL;

    leaf -> info = info;
    leaf -> quant = 1;
    leaf -> left = NULL;
    leaf -> right = NULL;

    return leaf;
}

void Tree_Destroy(Node* node)
{
    if(node == NULL)
        return;

    printf("2\n\n");
    /// RECURSION
    Tree_Destroy(node -> left);
    Tree_Destroy(node -> right);

    free(node);
    node = NULL;
}

bool Tree_RootDestroy(Node** root)
{
    if(root == NULL)
        return false;

    Tree_Destroy(*root);
    printf("1\n\n");

    free(root); ///ERROR

    return true;
}

///////////////////////////////////// INSERT

Node* Tree_Insert(TypeData info, Node* root)
{
    Node *leaf = Tree_CreateNode(info);

    if(leaf == NULL)
        return NULL;

    Node *current = root;
    Node *parent = NULL;

    if(current != NULL)
    {
        while(current != NULL)
        {
            parent = current;
            if(info ==  current -> info)
            {
                current -> quant++;
                free(leaf);
                return current;
            }
            else if (info > current -> info)
            {
                current = current -> right;
            }
            else
            {
                current = current -> left;
            }
        }

        if(info >  parent -> info)
            parent -> right = leaf;
        else
            parent -> left = leaf;
    }

    return leaf;
}

/////////////////////////////////////

bool Tree_Remove(Node** root, TypeData info)
{
    if(root == NULL)
        return 0;

    Node *current = *root;
    Node *parent = NULL;

    while(current != NULL)
    {
        if(info == current -> info)
        {
            if(current -> quant > 1)
                current -> quant--;
            else
            {
                if(current == *root)
                    *root = Tree_RemoveCurrent(current);
                else
                {
                    if(parent -> right == current)
                        parent -> right = Tree_RemoveCurrent(current);
                    else
                        parent -> left = Tree_RemoveCurrent(current);
                }
            }

            return true;

        }

        parent = current;

        if(info >  current -> info)
            current = current -> right;
        else
            current = current -> left;

    }

    return false;
}

///SUCCESSOR METHOD
Node* Tree_RemoveCurrent(Node* current)
{
    Node *parent, *suc;

    if(current -> right == NULL)
    {
        suc = current -> left;
        free(current);

        return suc;
    }

    parent = current;
    suc = parent -> right;

    while(suc -> left != NULL)
    {
        parent = suc;
        suc = suc -> left;
    }

    if(parent != current)
    {
        parent -> left = suc -> right;
        suc -> right = current -> right;
    }

    suc -> left = current -> left;
    free(current);
    return suc;
}

///////////////////////////////////// READ AND SEARCH

bool Tree_PrintInOrder(Node *node)
{
    if(node == NULL)
        return false;

    if(node != NULL)
    {
        Tree_PrintInOrder(node -> left);
        printf(">> INFO: %.2f || QUANT: %d.\n", node -> info, node -> quant);
        Tree_PrintInOrder(node -> right);
    }

    return true;
}

bool Tree_PrintPreOrder(Node *node)
{
    if(node == NULL)
        return false;

    if(node != NULL)
    {
        printf(">> INFO: %.2f || QUANT: %d.\n", node -> info, node -> quant);
        Tree_PrintInOrder(node -> left);
        Tree_PrintInOrder(node -> right);
    }

    return true;
}

bool Tree_PrintPosOrder(Node *node)
{
    if(node == NULL)
        return false;

    if(node != NULL)
    {
        Tree_PrintInOrder(node -> left);
        Tree_PrintInOrder(node -> right);
        printf(">> INFO: %.2f || QUANT: %d.\n", node -> info, node -> quant);
    }

    return true;
}
///////////////////////////////////// HELPERS
