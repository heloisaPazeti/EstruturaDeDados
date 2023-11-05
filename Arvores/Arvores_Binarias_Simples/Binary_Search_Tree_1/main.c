#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#define commandSize 5

Node* CreateTree();
void CreateMainMenu();
TypeData GetInsertValue();

int main()
{
    /*
    Node* root = Tree_Insert(10, NULL);

    Tree_Insert(1, root);
    Tree_Insert(2, root);
    Tree_Insert(3, root);
    Tree_Insert(4, root);
    Tree_Insert(5, root);

    Tree_Remove(&root, 10);

    Tree_PrintInOrder(root);

    Tree_Insert(10, root);
    Tree_PrintInOrder(root);
    */

    Node* root = CreateTree();

    while(1)
        CreateMainMenu(&root);


    return 0;
}

Node* CreateTree()
{
    printf(">> ROOT INFO: ");
    Node* root = Tree_Insert(GetInsertValue(), NULL);

    return root;
}

void CreateMainMenu(Node** root)
{
    char option[commandSize];

    printf("-------------- CHOOSE ONE OF THE FOLLOWING OPTIONS ---------------------------------------\n\n");
    printf("[0] EXIT                    [5] PRINT POS ORDER                 [10] GET TOTAL LEAFS\n");
    printf("[1] INSERT IN TREE          [6] CONSULT TREE                    [11] FIND MAX NODES\n");
    printf("[2] REMOVE VALUE            [7] CONSULT TREE IN PRE ORDER       [12] ...\n");
    printf("[3] PRINT IN ORDER          [8] CONSULT TREE CURRENT OR PARENT  [13] ...\n");
    printf("[4] PRINT PRE ORDER         [9] GET HEIGHT                      [14] DESTROY\n");
    printf("------------------------------------------------------------------------------------------\n\n");

    fflush(stdin);
    fgets(option, commandSize, stdin);

     switch(atoi(option))
     {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            printf("\nADD INFO: ");
            Tree_Insert(GetInsertValue(), *root);
            break;
        }
        case 2:
        {
            printf("\nREMOVE INFO: ");
            Tree_Remove(root, GetInsertValue());
            Tree_PrintInOrder(*root);
            break;
        }
        case 3:
        {
            Tree_PrintInOrder(*root);
            break;
        }
        case 4:
        {
            Tree_PrintPreOrder(*root);
            break;
        }
        case 5:
        {
            Tree_PrintPosOrder(*root);
            break;
        }
        case 6:
        {
            printf("\nSEARCH FOR VALUE: ");
            printf("\n>> CURRENT QUANT: %d\n", Tree_Search(root, GetInsertValue()));
            break;
        }
        case 7:
        {
            bool b;
            printf("\nSEARCH FOR VALUE: ");
            Tree_SearchPreOrder(root, GetInsertValue(), &b);
            break;
        }
        case 8:
        {
            TypeData f;
            int b;

            printf("\nSEARCH FOR VALUE: ");
            f = GetInsertValue();
            printf("LOOK FOR PARENT? [0 = FALSE / 1 = TRUE]: ");

            fflush(stdin);
            scanf("%d", &b);

            Tree_SeachChildOrParent(*root, b, f);
            break;
        }
        case 9:
        {
            printf("\n>> CURRENT TREE HEIGHT: %d\n\n", Tree_Height(root));
            break;
        }
        case 10:
        {
            printf("\n>> CURRENT TOTAL NODES IN TREE: %d\n\n", Tree_TotalNodes(root));
            break;
        }
        case 11:
        {
            int i;

            printf("\n>> SEACH FOR MAX VALUE PARENT? [0 = FALSE / 1 = TRUE]: ");
            fflush(stdin);
            scanf("%d", &i);
            Tree_FindMaxNode(*root, i);
            break;
        }
        default:
        {
            printf("\n>> SORRY, THIS OPTIONS IS NOT AVAILABLE...\n\n");
            break;
        }
     }

     printf("\n");
}

TypeData GetInsertValue()
{
    TypeData f;

    fflush(stdin);
    scanf(" %f", &f);
    printf("\n");

    return f;
}
