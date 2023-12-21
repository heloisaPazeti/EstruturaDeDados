#include "AVL.h"

///////////////////////////////////// STRUCTS

typedef struct _avl_node
{
    TypeData info;
    int height;
    struct _avl_node *left;
    struct _avl_node *right;

} Node;

///////////////////////////////////// CREATE AND DESTROY

Node** Create_AVL()
{
    Node** root = (Node**) malloc(sizeof(Node*));
    if(root != NULL)
        *root = NULL;

    return root;
}

Node* Create_Node(TypeData newInfo)
{
    Node* node = (Node*)malloc(sizeof(Node));

    strcpy(node -> info, newInfo); //node -> info = newInfo;
    node -> height = 0;
    node -> left = NULL;
    node -> right = NULL;

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

void Free_AVL(Node** root)
{
    if(root == NULL)
        return;

    Free_Node(*root);
    free(root);
}

///////////////////////////////////// INSERT

Node* Insert_AVL(Node* root, TypeData info)
{
    if(root == NULL)
        return (root = Create_Node(info));
    else if(strcmp(info, root -> info) < 0) //info < current -> info
        root -> left = Insert_AVL(root -> left, info);
    else
        root -> right = Insert_AVL(root -> right, info);

    root -> height = Greater(GetHeight(root -> left), GetHeight(root -> right)) +1;

    /// MAKING BALANCED ///

    if(GetHeight(root -> left) - GetHeight(root -> right) >= 2)
    {
        if(strcmp(info, root -> left -> info) < 0) //info  < current -> left -> info
            root = RR_Rotate(root);
        else
            root = LR_Rotate(root);
    }
    else if(GetHeight(root -> right) - GetHeight(root -> left) >= 2)
    {
         if(strcmp(info, root -> right -> info) < 0) //info  < current -> right  -> info
            root = RL_Rotate(root);
        else
            root = LL_Rotate(root);
    }

    return root;

}


///////////////////////////////////// REMOVE

Node* Remove_AVL(Node* root, TypeData info)
{
    if(root == NULL)
        return NULL;

    if(strcmp(info, root -> info) == 0) //info == root -> info
    {
        if(root -> right == NULL) //no successor
        {
            Node* temp = root;
            root = root -> left;
            free(temp);
            return root;
        }
        else
        {
            Node* temp = root -> right;

            while(temp -> left != NULL)
                temp = temp -> left;

            strcpy(root -> info, temp -> info);//root -> info = temp -> info // copy the value
            root -> right = Remove_AVL(root -> right, temp -> info);
        }
    }

    /// ELSE IF
}

///////////////////////////////////// ROTATE

Node* RR_Rotate(Node* a)
{
    Node* b = a -> left;
    a -> left = b -> right;
    b -> right = a;

    a -> height = Greater(GetHeight(a -> left), GetHeight(a -> right)) +1;
    b -> height = Greater(GetHeight(b -> left), GetHeight(b -> right)) +1;

    return b;
}

Node* LL_Rotate(Node* a)
{
    Node* b = a -> right;
    a -> right = b -> left;
    b -> left = a;

    a -> height = Greater(GetHeight(a -> left), GetHeight(a -> right)) +1;
    b -> height = Greater(GetHeight(b -> left), GetHeight(b -> right)) +1;

    return b;
}

Node* LR_Rotate(Node* c)
{
    c -> left = LL_Rotate(c -> left);
    return RR_Rotate(c);
}

Node* RL_Rotate(Node* c)
{
    c -> right = RR_Rotate(c -> right);
    return LL_Rotate(c);
}

///////////////////////////////////// SEARCH


///////////////////////////////////// HELPERS

int GetHeight(Node* node)
{
    return (node == NULL)? -1 : node -> height;
}

int Greater(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}
