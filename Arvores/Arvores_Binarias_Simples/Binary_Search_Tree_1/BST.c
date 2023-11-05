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


/// STILL DEVELOPING THESE TWO BAD BOYS

void Tree_DeteleNode(Node* node)
{
    if(node == NULL)
        return;

    Tree_DeteleNode(node -> left);
    Tree_DeteleNode(node -> right);

    free(node);
    node = NULL;
}

bool Tree_Delete(Node** root)
{
    if(root == NULL)
        return false;

    Tree_DeteleNode(*root);
    free(root);

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

    /// SEE IF WE CAN USE THE SEARCH METHOD TO IMPROVE

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

int Tree_Search(Node** root, TypeData value)
{
    if(root == NULL)
        return 0;

    Node* current = *root;

    while(current != NULL)
    {
        if(value == current -> info)
            return (current -> quant);

        if(value > current -> info)
            current = current -> right;
        else
            current = current -> left;
    }

    return 0;
}

void Tree_SearchPreOrder(Node** root, TypeData value, bool* found)
{
    if(root == NULL || *root == NULL)
        return;

    if(*found)
        return;

    if(*root != NULL)
    {
        if(value == (*root) -> info)
        {
            printf("\n\n >> HEY, HEY! LOOKED WHAT I FOUND, BOSS: %0.2f\n\n", (*root) -> info);
            *found = true;
        }

        Tree_SearchPreOrder(&((*root) -> left), value, found);
        Tree_SearchPreOrder(&((*root) -> right), value, found);
    }

    printf("\n>> VALUE NOT FOUND.");
}

Node* Tree_SeachChildOrParent(Node *root, int isParent, TypeData value)
{
    Node* current = root;
    Node* parent = NULL;

    if(current == NULL)
        return NULL;

    while(current != NULL)
    {
        if(value < current -> info)
        {
            parent = current;
            current = current -> left;
        }
        else if(value == current -> info)
            break;
        else
        {
            parent = current;
            current = current -> right;
        }
    }

    if(current == NULL)
    {
        printf("\n>> VALUE NOT FOUND.");
        return NULL;;
    }

    if(isParent)
    {
        printf("\n>PARENT'S [%0.2f] QUANT: %d", parent -> info ,parent  -> quant);
        return parent;
    }

    printf("\n> [%.2f] QUANT: %d", current -> info, current  -> quant);
    return current;
}

///////////////////////////////////// HELPERS

bool Tree_IsEmpty(Node** root)
{
    if(root == NULL || *root == NULL)
        return true;

    return false;
}

int Tree_TotalNodes(Node** root)
{
    if(root == NULL || *root == NULL)
        return 0;

    int leftH = Tree_TotalNodes(&((*root) -> left));
    int rightH = Tree_TotalNodes(&((*root) -> right));

    return (leftH + rightH + 1);
}

int Tree_Height(Node** root)
{
    if(root == NULL || *root == NULL)
        return 0;

    int leftH = Tree_Height(&((*root) -> left));
    int rightH = Tree_Height(&((*root) -> right));

    if(leftH > rightH)
        return (leftH + 1);
    else
        return (rightH + 1);
}

Node* Tree_FindMaxNode(Node* root, int isParent)
{
    Node* current = root;
    Node* parent = NULL;

    if(current == NULL)
        return NULL;

    while(current -> right != NULL)
    {
        parent = current;
        current = current -> right;
    }

    if(isParent)
    {
        printf("\n>>MAX NODE PARENT [%.2f] QUANT: %d\n", parent -> info, parent -> quant);
        return parent;
    }

    printf("\n>>MAX NODE [%.2f] QUANT: %d\n", current -> info, current -> quant);
    return current;
}
