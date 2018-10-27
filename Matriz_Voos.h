//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include "TAD_item_matriz.h"

//definiçao do tipo matriz
typedef struct{
    Item_Matriz IMatriz[24][24]; //[partida][chegada]
    char data[10]; //ex: 20/20/2000
    int n_voos;
}Matriz_Voos;


//cabeçalho das funções
void inicializar_matriz(Matriz_Voos *MVoos);
void inserir_voo(Matriz_Voos *MVoos, tipovoo *voo, int i, int j);
int remover_voo(Matriz_Voos *MVoos, tipovoo *voo, int Vid);
int localizar_voo_matriz(Matriz_Voos *MVoos, tipovoo *voo, int Vid); //Retorna o que procurou em lista de voos;
void imprimir_voo(Matriz_Voos *MVoos, int i, int j);
void imprimir_voos_HP(Matriz_Voos *MVoos, int j);
void imprimir_voos_HD(Matriz_Voos *MVoos, int i);
void imprimir_toda_matriz(Matriz_Voos *MVoos);
void Get_maior_n_voos(Matriz_Voos *MVoos); //"i" da lista de operações; mostra i e j e o n°;
void Get_menor_n_voos(Matriz_Voos *MVoos);
void Get_recente_att(Matriz_Voos *MVoos);
void Get_antigo_att(Matriz_Voos *MVoos);
int Verifica_esparca(Matriz_Voos *MVoos);
void n_total_voos (Matriz_Voos *Mvoos);
int conversor_ij (char* hora);
int conversor_horacompleta (char* hora);