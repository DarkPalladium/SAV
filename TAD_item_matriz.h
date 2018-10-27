//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include "TadListaVoos.h"

// definição do tipo celula da matriz
typedef struct{
    ListaVoos lvoo;
    int n_voos;
    char h_ultima_att[10]; //ex: 00:00:00
}Item_Matriz;

//Cabeçalho das funções
void iniciar_item_matriz(Item_Matriz *IM);

//GETS
int Get_n_voos(Item_Matriz *IM);
char* Get_h_ultima_att(Item_Matriz *IM); //ponteiro p/ ñ ter cópia na memória.

//SETS
void Set_n_voos(Item_Matriz *IM);
void Set_h_ultima_att(Item_Matriz *IM);