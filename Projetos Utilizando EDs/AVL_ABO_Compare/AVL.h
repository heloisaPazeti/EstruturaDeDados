#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef float Tipo_Dado;

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, Tipo_Dado data);
int remove_ArvAVL(ArvAVL *raiz, Tipo_Dado valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, Tipo_Dado valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

/////////////////////////////////////////////////// ADDS

void ArvAVL_Prof(ArvAVL *raiz, int prof, int *profMax);


#endif // AVL_H_INCLUDED
