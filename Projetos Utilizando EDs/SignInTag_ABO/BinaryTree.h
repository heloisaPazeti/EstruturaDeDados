#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

#define tagSize 9

struct _info
{
    char tag[tagSize];
    int status;
};

typedef struct _info Info;
typedef Info Tipo_Dado;

//Definição do tipo Arvore
struct NO{
    Tipo_Dado info;
    struct NO *esq;
    struct NO *dir;
};


typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;


ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Tipo_Dado valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, char tag[10]);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dado valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);

#endif // BINARYTREE_H_INCLUDED
