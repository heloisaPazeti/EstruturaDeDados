#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "List.h"

#define tSize 20

int main()
{
    char line[tSize];

    List* L = List_Create();
    ArvBin* root = cria_ArvBin();
    FILE *fp = fopen("arq.txt", "r");

    if(fp == NULL)
    {
        printf("OU NOUS!\nAnyway.");
    }
    else
    {
        char c = 'x';
        fgets(line, tSize, fp);
        line[strcspn(line, "\r\n")] = 0;
        line[strlen(line)] = '\0';

        while(strncmp(line, &c, 1) != 0)
        {
            Info newInfo;
            strcpy(newInfo.tag, line);

            newInfo.status = atoi(fgets(line, tSize, fp));

            List_AddInOrder(L, newInfo);
            insere_ArvBin(root, newInfo);

            fgets(line, tSize, fp);
            line[strcspn(line, "\r\n")] = 0;
            line[strlen(line)] = '\0';
        }

        fclose(fp);
    }

    char *option;
    char *tag;
    char command[15];
    fflush(stdin);

    fgets(command, 15, stdin);
    command[strcspn(command, "\r\n")] = 0;

    option = strtok(command, " ");
    tag = strtok(NULL, " ");

    switch(atoi(option))
    {
        case 0:
        {
            printf("NL:%d NA:%d\n", List_GetSize(L), totalNO_ArvBin(root));
            break;
        }
        case 1:
        {
            int listPos, treePos;

            listPos = List_Search(L, tag);
            treePos = consulta_ArvBin(root, tag);

            if((treePos > 0) && (listPos > 0))
            {
                printf("S:0 NL:%d NA:%d\n", listPos, treePos);
            }
            else
            {
                printf("S:-1 NL:%d NA:%d\n", -listPos, -treePos);
            }
            break;
        }
        case 2:
        {
            List_PrintData(L);
            break;
        }
        case 3:
        {
            preOrdem_ArvBin(root);
            break;
        }
    }

    return 0;
}
