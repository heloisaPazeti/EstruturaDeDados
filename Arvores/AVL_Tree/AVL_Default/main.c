#include "AVL.h"

#define commandSize 3

void Awake();
void PrintMenu();
void GetInfo();
void Start(Node* root);

int main()
{
    Awake();
	return 0;
}

//////////////////////////////////////// INITIALIZE

void Awake()
{
    Node* root = NULL;

    TypeData info;
    GetInfo(&info);

    root = Insert_AVL(root, info);

    Start(root);
}

//////////////////////////////////////// PROGRAM

void Start(Node* root)
{

    char option[commandSize];
    TypeData info;

    system("cls");   //-- if in windows
    //system("clear"); -- if in linux

    PrintMenu();

    printf("Digite seu comando: ");

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
            root = Insert_AVL(root, info);
            break;
        }
        case 2:
        {
            GetInfo(&info);
            root = Remove_AVL(root, info);
            break;
        }
        case 3:
        {
            GetInfo(&info);
            Search_AVL(root, info);
            printf("\nPress anything to continue...\n");
            getchar();
            break;
        }
        case 4:
        {
            printf("\n>> [PRINTING VALUES]\n\n");
            Print_InOrder(root);
            printf("\nPress anything to continue...\n");
            getchar();
            break;
        }
        case 5:
        {
            printf("\n>> [PRINTING VALUES]\n\n");
            Print_PreOrder(root);
            printf("\nPress anything to continue...\n");
            getchar();
            break;
        }
        case 6:
        {
            printf("\n>> [PRINTING VALUES]\n\n");
            Print_PosOrder(root);
            printf("\nPress anything to continue...\n");
            getchar();
            break;
        }
        case 7:
        {
            int total = TotalNodes_AVL(root);
            printf(">> [TOTAL NODES RESULT]: %d\n", total);
            printf("\nPress anything to continue...\n");
            getchar();
            break;
        }
        default:
        {
            printf("This command appears to be incorrect, please try again...\n");
        }
    }

    Start(root);
}

//////////////////////////////////////// HELPERS

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

void GetInfo(TypeData *info)
{
    char *ptr;

    printf("Type Info: ");
    fflush(stdin);
    fgets(*info, maxSize, stdin);

    if((ptr = strchr(*info, '\n')) != NULL)
        *ptr = '\0';
}
