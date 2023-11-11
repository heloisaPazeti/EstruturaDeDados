#include <string.h>

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

///////////////////////////////////////////// STRUCT

typedef char Tipo_Dado[12];

typedef struct elemento Elem;
typedef struct elemento* Lista;

///////////////////////////////////////////// CREATORS AND DESTROYERS

Lista* cria_lista();
void libera_lista(Lista* li);

///////////////////////////////////////////// INSERT

int insere_lista_final(Lista* li, Elem **cursor, Tipo_Dado *dt);
int insere_lista_inicio(Lista* li, Elem **cursor, Tipo_Dado *dt);
int insere_lista_antes(Lista* li, Elem **cursor, Tipo_Dado *dt);
int insere_lista_depois(Lista* li, Elem **cursor, Tipo_Dado *dt);

///////////////////////////////////////////// REMOVE
int remove_lista(Lista* li, Elem **cursor);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);

///////////////////////////////////////////// CONSULTS

int consulta_lista_dado(Lista* li, Elem **cursor, Tipo_Dado *dt);

///////////////////////////////////////////// GO TO

void go_inicio(Lista* li, Elem **cursor);
void go_fim(Lista* li, Elem **cursor);
void go_prox(Lista* li, Elem **cursor);
void go_ant(Lista* li, Elem **cursor);

///////////////////////////////////////////// HELPERS

int tamanho_lista(Lista* li);
void imprime_texto(Lista* li);
void imprime_palavra(Elem *cursor);
void imprime_lista(Lista* li, Elem *cursor);
