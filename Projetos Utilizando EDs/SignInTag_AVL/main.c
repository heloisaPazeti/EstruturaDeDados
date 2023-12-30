#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "AVL.h"

#define tSize 20

int main()
{
    char line[tSize];

    ArvBin* root = cria_ArvBin();
    ArvAVL* avl = cria_ArvAVL();

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

            insere_ArvBin(root, newInfo);
            insere_ArvAVL(avl, newInfo);

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
            printf("NA:%d NB:%d\n", totalNO_ArvBin(root), totalNO_ArvAVL(avl));
            break;
        }
        case 1:
        {
            int avlPos, treePos;

            avlPos = consulta_ArvAVL(avl, tag);
            treePos = consulta_ArvBin(root, tag);

            if((treePos > 0) && (avlPos > 0))
            {
                printf("S:0 NA:%d NB:%d\n", treePos, avlPos);
            }
            else
            {
                printf("S:-1 NA:%d NB:%d\n", -treePos, -avlPos);
            }
            break;
        }
        case 2:
        {
            preOrdem_ArvBin(root);
            break;
        }
        case 3:
        {
            preOrdem_ArvAVL(avl);
            break;
        }
    }

    return 0;
}
