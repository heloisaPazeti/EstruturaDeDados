#include "red_black.h"

#define RED 0
#define BLACK 1

#define LEFT 0
#define RIGHT 1

//////////////////////////////////// CREATE AND DESTROY

Node* Create_Node(TypeData newInfo)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node -> info = newInfo;
    //strcpy(node -> info, newInfo);
    node -> color = RED;
    node -> quant = 1;
    node -> left = NULL;
    node -> right = NULL;
    node -> parent = NULL;

    return node;
}

void Free_Node(Node* node)
{
    if(node == NULL)
        return;

    Free_Node(node -> left);
    Free_Node(node -> right);
    free(node);
    node = NULL;
}

void Free_RB(Tree* tree)
{
    if(tree == NULL || tree -> root == NULL)
        return;

    Free_Node(tree -> root);
    free(tree -> root);
    free(tree);
}

//////////////////////////////////// FIX UP

Node* FixUp(Tree* tree, Node* newNode)
{
    while((newNode -> parent != NULL) && (newNode -> parent -> color == RED))
    {
        if(newNode -> parent == newNode -> parent -> parent -> left)
        {
            Node* uncle = newNode -> parent -> parent -> right;
            if((uncle == NULL) || (uncle -> color == BLACK))
            {
                if(newNode == newNode -> parent -> right)
                {
                    newNode = newNode -> parent;
                    LL_Rotate(tree, newNode);
                }

                newNode -> parent -> color = BLACK;
                newNode -> parent -> parent -> color = RED;
                RR_Rotate(tree, newNode -> parent -> parent);
            }
            else
            {
                newNode -> parent -> color = BLACK;
                uncle -> color = BLACK;
                newNode -> parent -> parent -> color = RED;
                newNode = newNode -> parent -> parent;
            }
        }
        else
        {
            Node* uncle = newNode -> parent -> parent -> left;
            if((uncle == NULL) || (uncle -> color == BLACK))
            {
                if(newNode == newNode -> parent -> left)
                {
                    newNode = newNode -> parent;
                    RR_Rotate(tree, newNode);
                }

                newNode -> parent -> color = BLACK;
                newNode -> parent -> parent -> color = RED;
                LL_Rotate(tree, newNode -> parent -> parent);
            }
            else
            {
                newNode -> parent -> color = BLACK;
                uncle -> color = BLACK;
                newNode -> parent -> parent -> color = RED;
                newNode = newNode -> parent -> parent;
            }
        }
    }

    return newNode;
}

//////////////////////////////////// INSERT

Node* Insert_Node(TypeData info, Tree* tree)
{
    Node* current;
    Node* newNode;
    current = tree -> root;
    newNode = Create_Node(info);

    if(newNode == NULL)
        return NULL;

    while(current != NULL)
    {
        if(current -> info > newNode -> info)
        {
            if(current -> left == NULL)
            {
                current -> left = newNode;
                newNode -> parent = current;
                break;
            }
            else
                current = current -> left;
        }
        else if (current -> info < newNode -> info)
        {
            if(current -> right == NULL)
            {
                current -> right = newNode;
                newNode -> parent = current;
                break;
            }
            else
                current = current -> right;
        }
        else //duplicated info
        {
            current -> quant++;
            break;
        }
    }

    FixUp(tree, newNode);
    return newNode;
}

Tree* Insert_RB(Tree* tree, TypeData info)
{

    if(tree == NULL)
    {
        tree = (Tree*)malloc(sizeof(tree));
        tree -> quant = 0;
        tree -> root = Create_Node(info);
    }
    else
        Insert_Node(info, tree);

    tree -> root -> color = BLACK;
    tree -> quant++;
    return tree;
}

//////////////////////////////////// REMOVE

//////////////////////////////////// ROTATE

Node* RR_Rotate(Tree* tree, Node* a)
{
    Node* b = a -> left;
    a -> left = b -> right;

    if(b -> right != NULL)
        b -> right -> parent = a;

    b -> parent = a -> parent;

    if(a -> parent != NULL)
    {
        if(a == (a -> parent) -> left)
            a -> parent -> left = b;
        else
            a -> parent -> right = b;
    }
    else
        tree -> root = b;

    b -> right = a;
    a -> parent = b;

    return b;
}

Node* LL_Rotate(Tree* tree, Node* a)
{
    Node* b = a -> right;
    a -> right = b -> left;

    if(b -> left != NULL)
        b -> left -> parent = a;

    b -> parent = a -> parent;

    if(a -> parent != NULL)
    {
        if(a == (a -> parent) -> left)
            a -> parent -> left = b;
        else
            a -> parent -> right = b;
    }
    else
        tree -> root = b;


    b -> left = a;
    a -> parent = b;

    return b;
}

//////////////////////////////////// SEARCH

//////////////////////////////////// PRINTS

void Print_InOrder(Node* root)
{
    if(root != NULL)
    {
        Print_InOrder(root -> left);
        PrintNode(root);
        Print_InOrder(root -> right);
    }
}

void PrintNode(Node* node)
{
    printf("Info: '%d'", node -> info);

    if(node -> color == 0)
        printf(" || COLOR: RED\n");
    else
        printf(" || COLOR: BLACK\n");

    if(node -> left != NULL)
        printf("    - Left Child: '%d'\n", node -> left -> info);
    if(node -> right != NULL)
        printf("    - Right Child: '%d'\n", node -> right -> info);
    if(node -> parent != NULL)
        printf("    - Node Parent: '%d'\n", node -> parent -> info);

    printf("\n");
}

//////////////////////////////////// HELPERS
