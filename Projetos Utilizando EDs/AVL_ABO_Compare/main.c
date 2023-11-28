#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include "ABO.h"

long lrand48 (void);   // Rotina da Rand48

int main(){
    ArvAVL* avl;
    int i;
    int N = 1000000;
    int valor;
    double dado;

    printf("Iniciando...\n");

    system("pause");

    printf(">> Criando Arvore ABO << \n");

    ArvBin* raiz = cria_ArvBin();

     for(i=0; i < N; i++)
    {
        dado = lrand48();
        insere_ArvBin(raiz,(float)(dado));
    }

    printf("Total Nodos ABO: %d\n", totalNO_ArvBin(raiz));
    printf("Altura ABO: %d\n", altura_ArvBin(raiz));

    system("pause");
    printf(">> Criando Arvore AVL << \n");

    avl = cria_ArvAVL();

    for(i=0;i<N;i++)
    {
        valor=lrand48();
        insere_ArvAVL(avl,valor);
    }

    printf("Total Nodos AVL: %d\n", totalNO_ArvAVL(avl));
    printf("Altura AVL: %d\n", altura_ArvAVL(avl));

    system("pause");


    int profMax = 0;
    ArvAVL_Prof(avl, 0, &profMax);
    printf(">> Verificando altura Max da AVL: %d", profMax);

    return 0;
}
