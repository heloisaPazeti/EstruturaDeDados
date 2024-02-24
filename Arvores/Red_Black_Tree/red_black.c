#include "red_black.h"

#define RED 0
#define BLACK 1

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

Node* Remove(Tree* tree, TypeData info)
{
    if(tree == NULL || tree -> root == NULL)
        return NULL;

    Node* toRemove = Find_Node(tree, info);

    if(toRemove == NULL)
        return NULL;

    Node* substitute = Find_Substitute(tree, toRemove -> info);
    toRemove -> info = substitute -> info;
    Delete_Leaf(substitute);

    /////////////////////////
    //       CASES
    /////////////////////////


    if((toRemove -> color == RED) && (IsLeaf(substitute)))      // TO REMOVE IS RED LEAF (HAS NO CHILDREN)
        Delete_Leaf(substitute);
    else if(toRemove -> color == BLACK)                         // TO REMOVE IS BLACK
    {
        Node* sibling = Find_Sibling(toRemove);
        if(sibling == NULL)                                     // TO REMOVE IS ROOT
        {
            if(Has_RedChildren(toRemove) == NULL)
                Has_AnyChildren(toRemove) -> color = RED;
        }
        else if(sibling -> color == BLACK)                      //SIBLING IS BLACK
        {
            Node* redChildren = Has_RedChildren(sibling);
            if(redChildren != NULL)                            // AT LEAST ONE OF SIBLINGS CHILDREN IS RED
            {
                if((IsOnLeft(sibling)))
                {
                    if(IsOnLeft(redChildren)) // LL CASE
                    {
                        RR_Rotate(tree, sibling -> parent);
                        sibling -> left -> color = RED;
                    }
                    else // LR CASE
                    {
                        Swap_Values(sibling, redChildren);
                        redChildren -> color = BLACK;
                        RR_Rotate(tree, sibling -> parent);
                    }
                }
                else
                {
                    if(!IsOnLeft(redChildren))  // RR CASE
                    {
                        LL_Rotate(tree, sibling -> parent);
                        sibling -> right -> color = RED;
                    }
                    else  // RL CASE
                    {
                        Swap_Values(sibling, redChildren);
                        redChildren -> color = BLACK;
                        LL_Rotate(tree, sibling -> parent);
                    }
                }
            }
            else                                          //BOTH CHILDREN ARE BLACK / NULL
            {
                if(Has_AnyChildren(toRemove))
                    sibling -> color = RED;
            }


        }
        else                                              //SIBLING IS RED
        {
            if(IsOnLeft(sibling)) // LEFT CASE
            {
                RR_Rotate(tree, sibling -> parent);
                Swap_Colors(sibling -> parent, sibling -> parent -> left);
            }
            else                  // RIGHT CASE
            {
                LL_Rotate(tree, sibling -> parent);
                Swap_Colors(sibling -> parent, sibling -> parent -> right);
            }

        }
    }

    return NULL;
}

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

Node* Find_Node(Tree* tree, TypeData info)
{
    Node *result = tree -> root;

    while(result != NULL)
    {
        if(result -> info == info)
            return result;
        else
        {
            if(result -> info > info)
                result = result -> left;
            else
                result = result -> right;
        }
    }

    printf(">> INFO NOT FOUND...\n\n");
    return NULL;
}

Node* Find_Successor(Node* node)
{
    node = node -> right;

    while(node != NULL)
    {
        if(node -> left == NULL)
            return node;
        else
            node = node -> left;
    }

    printf(">> NO SUCCESSSOR FOUND...\n\n");
    return node;
}

Node* Find_Predecessor(Node* node)
{
     node = node -> left;

    while(node != NULL)
    {
        if(node -> right == NULL)
            return node;
        else
            node = node -> right;
    }

    printf(">> NO PREDECESSOR FOUND...\n\n");
    return node;
}

Node* Find_Substitute(Tree* tree, TypeData info)
{

    Node* node = Find_Node(tree, info);

    if(node == NULL)
        return NULL;

    if(node -> right != NULL)
        return (Find_Successor(node));
    else if(node -> left != NULL)
        return (Find_Predecessor(node));
    else
        return node;
}

Node* Find_Uncle(Node* node)
{
    if(node -> parent == NULL || node -> parent -> parent == NULL)
        return NULL;

    if(IsOnLeft(node -> parent))
        return (node -> parent -> parent -> right);
    else
        return (node -> parent -> parent -> left);
}

Node* Find_Sibling(Node* node)
{
    if(node -> parent == NULL)
        return NULL;

    if(IsOnLeft(node))
        return (node -> parent -> right);
    else
        return (node -> parent -> left);
}

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

void Delete_Leaf(Node* node)
{
    if(IsOnLeft(node))
        node -> parent -> left = NULL;
    else
        node -> parent -> right = NULL;

    free(node);
    node = NULL;
}

void Swap_Colors(Node* a, Node* b)
{
    if(a == NULL || b == NULL)
        return;

    int tempColor = a -> color;
    a -> color = b -> color;
    b -> color = tempColor;
}

void Swap_Values(Node* a, Node* b)
{
    if(a == NULL || b == NULL)
        return;

    TypeData temp;
    temp = a -> info;
    a -> info = b -> info;
    b -> info = temp;
}

Node* Has_RedChildren(Node* node)
{
    if(node -> right != NULL && node -> right -> color == RED)
        return node -> right;
    else if(node -> left != NULL && node -> left -> color == RED)
        return node -> left;
    else
        return NULL;
}

Node* Has_AnyChildren(Node* node)
{
    if(node -> right != NULL)
        return node -> right;
    else if (node -> left != NULL)
        return node -> left;
    else
        return NULL;
}

bool IsOnLeft(Node* node) { return (node == node -> parent -> left);}
bool IsLeaf(Node* node) {return (node -> right == NULL && node -> left == NULL);}
