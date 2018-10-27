//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include "TadVoo.h"

//Estrutura da celula da lista encadeada
typedef  struct celula *apontador; // utilizamos essa redefinicao de ponteiro na hora de fazer a alocacao dinamica de memoria
typedef struct celula{
    tipovoo voo;
    struct celula* prox;
} tcelula;

// Estrutura da lista encadeada
typedef struct {
    tcelula* primeiro;
    tcelula* ultimo;
} ListaVoos;

void Lnovavazia (ListaVoos* lista);
void Lista_insere (ListaVoos* lista, tipovoo* voo);
int Lista_remove (ListaVoos* lista, tipovoo *voo, int vid);
int ProcuraVoo_lista (ListaVoos* lista, tipovoo *voo, int vid);
int quantvoos_lista (ListaVoos* lista);