#ifndef ABO_H_INCLUDED
#define ABO_H_INCLUDED

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, float valor);
int remove_ArvBin(ArvBin *raiz, float valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, float valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, float valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);


#endif // ABO_H_INCLUDED
