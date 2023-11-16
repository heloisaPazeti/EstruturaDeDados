#include "BinaryTree.h"

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, Tipo_Dado data){

    if(raiz == NULL)
        return 0;

    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    if(novo == NULL)
        return 0;

    novo->dir = NULL;
    novo->esq = NULL;

    strncpy(novo -> info.tag, data.tag, tagSize);
    novo -> info.tag[strlen(novo -> info.tag)] = '\0';
    novo -> info.status = data.status;

    if(*raiz == NULL)
    {
        *raiz = novo;
    }

    else
    {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while(atual != NULL)
        {
            ant = atual;
            if(strncmp(data.tag, atual -> info.tag, tagSize) == 0) //elemento já existe
            {
                free(novo);
                return 0;
            }
            if(strncmp(data.tag, atual -> info.tag, tagSize) > 0)
            {
                atual = atual->dir;
            }

            else
            {
                atual = atual->esq;
            }

        }

        if(strncmp(data.tag, ant -> info.tag, tagSize) > 0)
        {
            //printf("[%s] ADICIONADO A DIREITA DE [%s]\n", data.tag, ant ->info.tag);
            ant -> dir = novo;
        }
        else
        {
            //printf("[%s] ADICIONADO A ESQUERDA DE [%s]\n", data.tag, ant ->info.tag);
            ant -> esq = novo;
        }

    }

    return 1;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, char tag[10])
{
    if(raiz == NULL)
        return 0;

    int qtdeNodes = 0;
    struct NO* atual = *raiz;

    while(atual != NULL){
        if(strncmp(tag, atual -> info.tag, tagSize) == 0){
            return (qtdeNodes + 1);
        }
        if(strncmp(tag, atual -> info.tag, tagSize) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;

        qtdeNodes++;
    }

    return (-1*qtdeNodes);
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s %d\n",(*raiz)->info.tag, (*raiz)->info.status);

        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%s %d\n",(*raiz)->info.tag, (*raiz)->info.status);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}


// Funcoes Adicionais de Arvore

void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dado data, int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        //if (data == (*raiz)->info)
        if (strncmp(data.tag, (*raiz) -> info.tag, tagSize) == 0)
        {
            printf("%s %d\n",(*raiz)->info.tag, (*raiz)->info.status);
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),data,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),data,achou);
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("DADO: %s || STATUS: %d\n", (*raiz)->info.tag, (*raiz)->info.status);
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
    }
}
