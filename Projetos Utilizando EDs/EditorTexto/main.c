#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h"

int main()
{
    Elem* cursor;
    Lista* li = cria_lista();

    while(1)
    {
        char *c;
        char *wordReceiver;
        char word[12];
        char sentence[15];
        fgets(sentence, 15, stdin);
        sentence[strcspn(sentence, "\r\n")] = 0;

        c = strtok(sentence, " ");
        wordReceiver = strtok(NULL, " ");
        strcpy(word, wordReceiver);

        switch(*c)
        {
            case 'I':
            {
                insere_lista_inicio(li, &cursor, &word);
                break;
            }
            case 'F':
            {
                insere_lista_final(li, &cursor, &word);
                break;
            }
            case 'A':
            {
                insere_lista_antes(li, &cursor, &word);
                break;
            }
            case 'D':
            {
                insere_lista_depois(li, &cursor, &word);
                break;
            }
            case 'P':
            {
                consulta_lista_dado(li, &cursor, &word);
                break;
            }
            case 'R':
            {
                if(strncmp(word, "atual", 5) == 0)
                {
                    if(tamanho_lista(li) > 0)
                    {
                        remove_lista(li, &cursor);
                    }
                    else
                    {
                        printf("Essa lista ainda nao possue elementos...");
                    }
                }
                else
                {
                    printf("Comando invalido, voce quis dizer: 'R atual' ?\n");
                }

                break;
            }
            case 'G':
            {
                if(strncmp(word, "inicio", 6) == 0)
                {
                    go_inicio(li, &cursor);
                }
                else if(strncmp(word, "fim", 3) == 0)
                {
                    go_fim(li, &cursor);
                }
                else if(strncmp(word, "prox", 4) == 0)
                {
                    go_prox(li, &cursor);
                }
                else if(strncmp(word, "ant", 3) == 0)
                {
                    go_ant(li, &cursor);
                }
                else
                {
                    printf("Comando invalido, tente outra vez...\n");
                }

                break;
            }
            case 'L':
            {
                if(strncmp(word, "texto", 5) == 0)
                {
                    if(tamanho_lista(li) > 0)
                        imprime_texto(li);
                    else
                        printf("A lista está vazia... Utilize I ou F para adicionar novos itens");
                }
                else if(strncmp(word, "palavra", 7) == 0)
                {
                    if(tamanho_lista(li) > 0)
                        imprime_palavra(cursor);
                    else
                        printf("A lista está vazia... Utilize I ou F para adicionar novos itens");
                }
                else
                {
                    printf("Comando invalido. Tente 'L palavra' ou 'L texto'.\n");
                }

                break;
            }
            case 'X':
            {
                if(word != NULL)
                {
                    if(strncmp(word, "editor", 6) == 0)
                    {
                        return 0;
                    }
                    else
                    {
                        printf("Comando invalido, talvez voce queira dizer 'X editor'...\n");
                    }
                }
                else
                {
                    printf("Comando invalido, talvez voce queira dizer 'X editor'...\n");
                }
                break;
            }

            default:
                printf("Comando nao reconhecido, tente novamente.\n");
                break;

        }
    }

    return 0;
}

