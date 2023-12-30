#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include "infoStruct.h"

typedef struct NO* ArvAVL;

///////////////////////////////////// CREATE AND DESTROY

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);

///////////////////////////////////// INSERT AND REMOVE

int insere_ArvAVL(ArvAVL *raiz, Tipo_Dado data);
int remove_ArvAVL(ArvAVL *raiz, Tipo_Dado valor);

///////////////////////////////////// SEARCH

int consulta_ArvAVL(ArvAVL *raiz, char tag[10]);

///////////////////////////////////// PRINTS

void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

///////////////////////////////////// HELPERS

int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
struct NO* procuraMenor(struct NO* atual);
int fatorBalanceamento_NO(struct NO* no);
int maior(int x, int y);
int altura_NO(struct NO* no);

#endif // AVL_H_INCLUDED
