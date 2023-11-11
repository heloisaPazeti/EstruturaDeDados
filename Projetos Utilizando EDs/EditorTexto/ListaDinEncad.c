#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

///////////////////////////////////////////// STRUCT

typedef struct elemento
{
    Tipo_Dado dado;
    struct elemento *prox;

} Elem;

///////////////////////////////////////////// CREATORS AND DESTROYER

Lista* cria_lista()
{
    Lista* li;

    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;

    return li;
}

void libera_lista(Lista* li)
{
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

///////////////////////////////////////////// INSERT

int insere_lista_final(Lista* li, Elem **cursor, Tipo_Dado *dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no -> dado, *dt);
    no->prox = NULL;

    if ((*li) == NULL)
    {
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }

    *cursor = no;
    return OK;
}

int insere_lista_inicio(Lista* li, Elem **cursor, Tipo_Dado *dt)
{
   Elem* no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no -> dado, *dt);
    no -> prox = (*li);
    *li = no;
    *cursor = no;

    return OK;
}

int insere_lista_antes(Lista* li, Elem **cursor, Tipo_Dado *dt)
{
    if (li == NULL) return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no -> dado, *dt);
    if ((*cursor == NULL) && (*li==NULL))
    {
        no->prox = NULL;
        *li = no;
        *cursor = no;
        return OK;
    }
    else
    {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual != *cursor)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual != *cursor)
            return ERRO;

        if (atual == *li)
        {
            no->prox = (*li);
            *li = no;
            *cursor = no;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
            *cursor = no;
        }

        return OK;
    }
}

int insere_lista_depois(Lista* li, Elem **cursor, Tipo_Dado *dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return ERRO;

    strcpy(no -> dado, *dt);
    if ((*cursor == NULL) && (*li==NULL))
       no->prox = NULL;
    else
       if ((*cursor == NULL) || (*li==NULL))
           return(ERRO);

    if ((*li) == NULL)
    {
        *li = no;
        *cursor = no;
    }
    else
    {
        no->prox  = (*cursor)->prox;
        (*cursor)->prox = no;
        *cursor = no;
    }

    return OK;
}

///////////////////////////////////////////// REMOVE

int remove_lista(Lista* li, Elem **cursor)
{
    if(li == NULL)
        return ERRO;

    if((*li) == NULL)
        return ERRO;

    Elem *ant, *no = *li;
    while(no != NULL && no != *cursor)
    {
        ant = no;
        no = no->prox;
    }
    if(no == NULL)
        return ERRO;

    if(no == *li)
    {
        *li = no->prox;
        *cursor = no -> prox;
    }
    else
    {
        ant->prox = no->prox;
        *cursor = ant;
    }

    free(no);
    return OK;
}

///////////////////////////////////////////// CONSULTS

int consulta_lista_dado(Lista* li, Elem **cursor, Tipo_Dado *dt)
{
    Elem *no;

    no = *li;
    if(li == NULL)
        return ERRO;
    while(no != NULL && strcmp(no->dado, *dt) != 0)
    {
        no = no->prox;
    }

    if(no == NULL)
        return ERRO;
    else{
        *cursor = no;
        return OK;
    }
}

///////////////////////////////////////////// GO TO

void go_inicio(Lista* li, Elem **cursor)
{
    Elem *no;
    no = *li;
    *cursor = no;
}

void go_fim(Lista* li, Elem **cursor)
{
    if(li == NULL)
        return;

    Elem *ant, *no = *li;

    while(no != NULL)
    {
        ant = no;
        no = no->prox;
    }


    *cursor = ant;
}

void go_prox(Lista* li, Elem **cursor)
{
    *cursor = (*cursor) -> prox;
}

void go_ant(Lista* li, Elem **cursor)
{
    if(li == NULL)
        return ;

    Elem *ant, *no = *li;

    while(no != NULL && no != *cursor)
    {
        ant = no;
        no = no->prox;
    }

    *cursor = ant;
}

///////////////////////////////////////////// HELPERS

int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return 0;

    int cont = 0;
    Elem* no = *li;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}

void imprime_texto(Lista* li)
{
    if(li == NULL)
        return;

    Elem* no = *li;

    while(no != NULL)
    {
        printf("%s ",no->dado);
        no = no->prox;
    }
    printf("\n");
}

void imprime_palavra(Elem *cursor)
{
    printf("%s\n", cursor -> dado);
}

void imprime_lista(Lista* li, Elem *cursor)
{
    printf("-------------- INICIO LISTA -----------------\n");

    if(li == NULL)
        return;

    Elem* no = *li;

    while(no != NULL)
    {
        printf("Dado: %s [ %p ]\n",no->dado, no);
        no = no->prox;
    }

    printf("\nCURSOR: %s [ %p ]\n", cursor -> dado, cursor);
    printf("-------------- FIM LISTA -----------------\n");
}
