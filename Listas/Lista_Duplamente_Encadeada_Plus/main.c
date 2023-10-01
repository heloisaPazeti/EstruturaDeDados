#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Doubly_Linked_List.h"

#define commandSize 10

void CreateMainMenu();
void GetInsertValue(TypeData *sentence);
void GetRemoveValue(TypeData *sentence);
void GetValue(TypeData *sentence);
int GetPosition();

List *L;

int main()
{
    L = List_Create();

    while(1)
    {
        if(L != NULL)
            CreateMainMenu();
        else
            exit(0); /// ADICIONAR AQUI OUTRO MENU PARA SAIR OU CRIAR NOVA LISTA
    }

    return 0;
}

void CreateMainMenu()
{
    char option[commandSize];
    TypeData sentence;

    printf("-------------- CHOOSE ONE OF THE FOLLOWING OPTIONS ---------------------------------------\n\n");
    printf("[0] EXIT                    [5] INSERT AFTER CURSOR             [10] GO TO PREVIOUS\n");
    printf("[1] PRINT LIST              [6] INSERT BEFORE POSITION          [11] GO TO NEXT\n");
    printf("[2] INSERT AT BEGGINING     [7] INSERT AFTER POSITION           [12] REMOVE CURSOR\n");
    printf("[3] INSERT AT END           [8] GO TO START                     [13] REMOVE VALUE\n");
    printf("[4] INSERT BEFORE CURSOR    [9] GO TO END                       [14] DESTROY LIST\n");
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
            List_Print(L);
            break;
        }
        case 2:
        {
            GetInsertValue(&sentence);
            List_AddFirst(L, sentence);
            printf("\n\n");
            break;
        }
        case 3:
        {
            GetInsertValue(&sentence);
            List_AddLast(L, sentence);
            printf("\n\n");
            break;
        }
        case 4:
        {
            GetInsertValue(&sentence);
            List_AddBefore_Cursor(L, sentence);
            printf("\n\n");
            break;
        }
        case 5:
        {
            GetInsertValue(&sentence);
            List_AddAfter_Cursor(L, sentence);
            printf("\n\n");
            break;
        }
        case 6:
        {
            GetInsertValue(&sentence);
            List_Add_Position(L , sentence, GetPosition(), true);
            printf("\n\n");
            break;
        }
        case 7:
        {
            GetInsertValue(&sentence);
            List_Add_Position(L , sentence, GetPosition(), false);
            printf("\n\n");
            break;
        }
        case 8:
        {
            List_GoStart(L);
            break;
        }
         case 9:
        {
            List_GoEnd(L);
            break;
        }
         case 10:
        {
            List_GoPrev(L);
            break;
        }
         case 11:
        {
            List_GoNext(L);
            break;
        }
         case 12:
        {
            List_RemoveCursor(L);
            break;
        }
        case 13:
        {
            GetRemoveValue(&sentence);
            List_Remove(L, sentence);
            printf("\n\n");
            break;
        }
        case 14:
        {
            List_Destroy(&L);
            break;
        }
        default:
        {
            printf("COMANDO INVALIDO.\n");
        }

    }
}

void GetInsertValue(TypeData *sentence)
{
    printf("VALOR PARA ADICIONAR:");
    GetValue(sentence);
}

void GetRemoveValue(TypeData *sentence)
{
    printf("VALOR PARA REMOVER:");
    GetValue(sentence);
}

void GetValue(TypeData *sentence)
{
    char *ptr;
    fflush(stdin);
    fgets(*sentence, maxSize, stdin);

    if((ptr = strchr(*sentence, '\n')) != NULL)
        *ptr = '\0';

    printf("\n\n");
}

int GetPosition()
{
    char position[commandSize];
    printf("POSICAO EM QUE ADICIONAR:");
    fflush(stdin);
    fgets(position, commandSize, stdin);
    printf("\n\n");

    return atoi(position);
}
