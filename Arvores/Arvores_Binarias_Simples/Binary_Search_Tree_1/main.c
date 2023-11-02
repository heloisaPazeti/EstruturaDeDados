#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


//void CreateMainMenu();
//float GetInsertValue();

int main()
{
    Node* root = Tree_Insert(0.25, NULL);
    Tree_Insert(0.1, root);
    Tree_Insert(0.6, root);
    Tree_Insert(0.9, root);
    Tree_Insert(1.2, root);
    Tree_Insert(1.2, root);
    Tree_Insert(0.8, root);
    Tree_Insert(0.3, root);

    printf(" -- PRINTING IN ORDER --\n\n");
    Tree_PrintInOrder(root);

    printf("\n\n -- REMOVING NODE: 1.2 --\n\n");
    Tree_Remove(&root, 1.2);
    Tree_PrintInOrder(root);

    printf("\n\n -- REMOVING ROOT --\n\n");
    Tree_Remove(&root, 0.25);
    Tree_PrintInOrder(root);

    Tree_Delete(root);
    root = NULL;

    return 0;
}

/*
void CreateMainMenu()
{
    char option[commandSize];
    TypeData sentence;

    printf("-------------- CHOOSE ONE OF THE FOLLOWING OPTIONS ---------------------------------------\n\n");
    printf("[0] EXIT                    [5] PRINT POS ORDER             [10] DESTROY\n");
    printf("[1] INSERT IN TREE          [6] CONSULT TREE                [11] ...\n");
    printf("[2] REMOVE VALUE            [7] GET HIGH                    [12] ...\n");
    printf("[3] PRINT IN ORDER          [8] GET TOTAL LEAFS             [13] ...\n");
    printf("[4] PRINT PRE ORDER         [9] FIND MAX NODES              [14] ...\n");
    printf("------------------------------------------------------------------------------------------\n\n");

    fgets(option, commandSize, stdin);

     switch(atoi(option))
     {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            Tree_Insert(GetInsertValue(), root);
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
        case 0:
        {
            break;
        }
     }
}

float GetInsertValue()
{
    float f;

    printf("\n\nValor P/ Add: ");

    fflush(stdin);
    scanf("%.4f", &f);
    printf("\n\n");

    return f;
}*/
