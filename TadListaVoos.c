//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include <string.h>
#include <stdlib.h>
#include "TadListaVoos.h"

// Cria uma lista encadeada vazia
// Fazendo a alocacao de memoria de uma celula e fazendo dela a celula cabeca
void Lnovavazia (ListaVoos* lista){
    lista->primeiro = (apontador) malloc(sizeof(tcelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

// Recebe uma lista de voos e o voo a ser adicionado
// E coloca esse novo voo na lista antes do voo com horario mais similar a ele
void Lista_insere (ListaVoos* lista, tipovoo* voo){
    tcelula *voo_atual, *proxvoo, *novo;

    novo = (apontador) malloc(sizeof(tcelula));
    novo->voo = *voo;

    voo_atual = lista->primeiro;
    proxvoo = lista->primeiro->prox;

    while (proxvoo != NULL) {
        if (strcmp(proxvoo->voo.horadecolar, voo->horadecolar) >= 0) {
            break;
        }
        voo_atual = proxvoo;
        proxvoo = proxvoo->prox;
    }
    novo->prox = proxvoo;
    voo_atual->prox = novo;
    if (lista->ultimo->prox != NULL){  //este IF esta conferindo se a necessidade de modificar o endereço para onde ultimo aponta
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->prox = NULL;
    }
}

//Recebe uma lista de voos e o VID do voo que gostaria de remover
//Retornara 1 se a remoção for um sucesso
//ou 0 se o voo não existir na lista
int Lista_remove (ListaVoos* lista, tipovoo *voo, int vid){
    tcelula *voo_atual, *prox_voo;

    voo_atual = lista->primeiro;
    prox_voo = lista->primeiro->prox;

    while(prox_voo != NULL && prox_voo->voo.VID != vid){
        voo_atual = prox_voo;
        prox_voo = voo_atual->prox;
    }

    if(prox_voo != NULL){
        *voo = prox_voo->voo;
        voo_atual->prox = prox_voo->prox;
        free(prox_voo);
        if(lista->ultimo->prox != NULL){
            lista->ultimo = lista->ultimo->prox;
            lista->ultimo->prox = NULL;
        }
        return 1;
    }
    return 0;
}

// Recebe a lista de voos, o VID do voo que procura e o ponteiro que aponta para onde será aramazenado o voo
// Ele retornará 1 se o voo for encontrado, ou 0 se o voo não for encontrado
int ProcuraVoo_lista (ListaVoos* lista, tipovoo *voo, int vid){
    tcelula *voo_atual, *prox_voo;

    voo_atual = lista->primeiro;
    prox_voo = lista->primeiro->prox;

    while(prox_voo != NULL && prox_voo->voo.VID != vid){
        voo_atual = prox_voo;
        prox_voo = prox_voo->prox;
    }

    if(prox_voo != NULL){
        *voo = prox_voo->voo;
        return 1;
    }
    return 0;
}

//Recebe a lista de voos
//Retorna a quantidade de voos que existem na lista
int quantvoos_lista (ListaVoos* lista){
    tcelula *aux;
    int cont;
    cont = 0;
    aux = lista->primeiro;
    while (aux->prox != NULL){
        cont ++;
        aux = aux->prox;
    }
    return cont;
}