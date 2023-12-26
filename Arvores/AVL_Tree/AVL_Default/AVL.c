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
    if(root == NULL) // CASE TREE IS EMPTY
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
    else if (strcmp(info, root -> info) < 0)
        root -> left = Remove_AVL(root -> left, info);
    else
        root -> right = Remove_AVL(root -> right, info);

    root -> height = Greater(GetHeight(root -> left), GetHeight(root -> right)) +1;

    if(GetHeight(root -> left) - GetHeight(root -> right) == 2)
    {
        if(GetHeight(root -> right -> right) >= GetHeight(root -> right -> left))
            root = LL_Rotate(root);
        else
            root = RL_Rotate(root);
    }
    else if(GetHeight(root -> right) - GetHeight(root -> left) == 2)
    {
        if(GetHeight(root -> left -> left) >= GetHeight(root -> left -> right))
            root = RR_Rotate(root);
        else
            root = LR_Rotate(root);
    }

    return root;
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

Node* Search_AVL(Node* root, TypeData info)
{
    if(root == NULL)
    {
        printf(">> [SEARCH RESULT]: Value not Found. Null Root Exception.\n");
        return NULL;
    }

    if(strcmp(info, root -> info) == 0) //if(info == root -> info)
    {
        printf(">> [Search Result]: Value %s Found!\n", root -> info);
        printf("    Left Leaf: %s\n", root -> left -> info);
        printf("    Right Leaf: %s\n\n", root -> right -> info);
        return root;
    }
    else
    {
        Node* result = NULL;

        if(strcmp(info, root -> info) > 0) // if(info > root -> info)
            result = Search_AVL(root -> right, info);
        else
            result = Search_AVL(root -> left, info);

        return result;
    }
}

///////////////////////////////////// PRINTS

void Print_InOrder(Node* root)
{
    if(root != NULL)
    {
        Print_InOrder(root -> left);
        PrintNode(root);
        Print_InOrder(root -> right);
    }
}

void Print_PreOrder(Node* root)
{
    if(root != NULL)
    {
        PrintNode(root);

        Print_PreOrder(root -> left);
        Print_PreOrder(root -> right);
    }
}

void Print_PosOrder(Node* root)
{
    if(root != NULL)
    {
        Print_PosOrder(root -> left);
        Print_PosOrder(root -> right);

        PrintNode(root);
    }
}

void PrintNode(Node* node)
{
    printf("Info: '%s' || Height: %d\n", node -> info, node -> height);
        printf("    - Left Child: '%s'\n", node -> left -> info);
        printf("    - Right Child: '%s'\n", node -> right -> info);

    printf("\n");
}

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

int TotalNodes_AVL(Node* root)
{
    if(root == NULL)
        return 0;

    int left_height = TotalNodes_AVL(root -> left);
    int right_height = TotalNodes_AVL(root -> right);

    return (left_height + right_height + 1);
}
