#include "red_black.h"

#define commandSize 3

void Awake();
void Start(Tree* t);
void PrintMenu();
void GetInfo(TypeData *info);
void Await();

int main()
{
    Awake();

    /*
    Tree* tree = NULL;
    tree = Insert_RB(tree, 20);
    tree = Insert_RB(tree, 10);
    tree = Insert_RB(tree, 30);
    tree = Insert_RB(tree, 5);
    tree = Insert_RB(tree, 15);
    tree = Insert_RB(tree, 6);

    Remove(tree, 6);
    Remove(tree, 30);

    Print_PosOrder(tree -> root);
    */
    return 0;
}

//////////////////////////////////////// INITIALIZE

void Awake()
{
    Tree* tree = NULL;

    TypeData info;
    GetInfo(&info);

    tree = Insert_RB(tree, info);

    Start(tree);
}

void Start(Tree* tree)
{
    char option[commandSize];
    TypeData info;

    system("cls");   //-- if in windows
    //system("clear"); -- if in LINUX

    PrintMenu();

    printf("Type Option: ");
    fflush(stdin);
    fgets(option, commandSize, stdin);

    switch(atoi(option))
    {
        case 0:
        {
            exit(0);
            break;
        }
        case 1:
        {
            GetInfo(&info);
            tree = Insert_RB(tree, info);
            break;
        }
        case 2:
        {
            GetInfo(&info);
            Remove_RB(tree, info);
            break;
        }
        case 3:
        {
            GetInfo(&info);
            Node* result = Find_Node(tree, info);
            if(result != NULL)
                printf(">> RESULT: %d\n\n", result -> info);

            Await();
            getchar();
            break;
        }
        case 4:
        {
            system("cls");
            printf(">> PRINTING VALUES IN ORDER: \n\n");
            Print_InOrder(tree -> root);

            Await();
            break;
        }
        case 5:
        {
            system("cls");
            printf(">> PRINTING VALUES PRE ORDER: \n\n");
            Print_PreOrder(tree -> root);

            Await();
            break;
        }
        case 6:
        {
            system("cls");
            printf(">> PRINTING VALUES POS ORDER: \n\n");
            Print_PosOrder(tree -> root);

            Await();
            break;
        }
        case 7:
        {
            ShowTotalNodes(tree);

            Await();
            break;
        }
        default:
        {
            printf(">> THIS COMMAND APPEARS TO BE INCORRECT, PLEASE TRY AGAIN...\n");
            break;
        }
    }

    Start(tree);
}

//////////////////////////////////////// MENU

void PrintMenu()
{
    printf(">> MAIN MENU <<\n\n");

    printf(" [0] - Exit\n");
    printf(" [1] - Insert\n");
    printf(" [2] - Remove\n");
    printf(" [3] - Search\n");
    printf(" [4] - Print In Order\n");
    printf(" [5] - Print Pre Order\n");
    printf(" [6] - Print Pos Order\n");
    printf(" [7] - Total Nodes\n");
    printf("\n");
}

//////////////////////////////////////// HELPERS

void GetInfo(TypeData *info)
{
    printf("Type Data: ");
    scanf("%d", info);

    // IF TYPEDATA IS STRING:
    /*

        fflush(stdin);
        fgets(*info, maxSize, stdin);

        if((ptr = strchr(*info, '\n')) != NULL)
            *ptr = '\0';

    */
}

void Await()
{
    printf(">> PRESS ANYTHING TO CONTINUE...\n");
    getchar();
    return;
}
