//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include <string.h>
#include <time.h>
#include "TAD_item_matriz.h"

//Recebe um ponteiro para um item matriz
// E faz sua inicializacao, atribuindo aos seus campos valores nulos
//exeto a hora de atualizacao, que sera atribuido a ele a hora atual do computador
void iniciar_item_matriz(Item_Matriz *IM){
    char hora[10];
    _strtime(hora);
    strcpy(IM->h_ultima_att, hora);
    Lnovavazia(&IM->lvoo); //usa o inicializar da lista de voos;
    IM->n_voos = 0;
}

//Todas as funcoes GET's recebe um Item Matriz
//Todas as funcoes GET's retornam o valor armazenado na sua respectiva solicitacao
int Get_n_voos(Item_Matriz *IM){
    return IM->n_voos;
}

char* Get_h_ultima_att(Item_Matriz *IM){
    return IM->h_ultima_att;
}

//Todas as funcoes SET's recebe um Item Matriz
// Todas as funcoes SET's modificam o valor solicitado, utilizando funcoes ja existentes em outras TADs
void Set_n_voos(Item_Matriz *IM){
    (*IM).n_voos = quantvoos_lista(&IM->lvoo); //atualiza a quantidade de voos que tem na lista, utilizando a funcao da TAD listavoos.
}

void Set_h_ultima_att(Item_Matriz *IM){
    char hora[10];
    _strtime(hora); // essa funcao recebe um char e armazena nele a hora atual do computador
    strcpy(IM->h_ultima_att, hora);
}
