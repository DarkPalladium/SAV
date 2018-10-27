//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "Matriz_Voos.h"

//Ela recebe uma Matriz
//E cria uma lista encadeada vazia para cada posição da matriz
//E tbm atribui ao campo data, a data do computador, e diz que o numero total de voos armazenados na matriz e 0
void inicializar_matriz(Matriz_Voos *MVoos){
    char data[20];
    int i, j;
    i = 0;
    j = 0;
    while (i != 24) {
        while (j != 24) {
            iniciar_item_matriz(&MVoos->IMatriz[i][j]);
            j ++;
        }
        i ++;
        j = 0;
    }
    MVoos->n_voos = 0;
    _strdate(data);
    strcpy(MVoos->data, data);
}

//Recebe a matriz, o voo que será inserido e as posicoes da matriz onde sera armazenado
//a funcao em si nao faz nada, ela simplismente chama as funcoes das TAD listavoos e item matriz
void inserir_voo(Matriz_Voos *MVoos, tipovoo *voo, int i, int j){
    Lista_insere(&MVoos->IMatriz[i][j].lvoo, voo);
    Set_n_voos(&MVoos->IMatriz[i][j]);
    Set_h_ultima_att(&MVoos->IMatriz[i][j]);
    n_total_voos(MVoos);
}

//Rececbe uma matriz, um ponteiro para um tipo voo, sera onde armazenado o item removido para utilizacao pelo usuario
//e o ID do voo a ser removido
//Ela percorre a matriz, em cada posicao da matriz ele chama a funcao procura da listavoos para ver se o voo existe naquela posicao
//quando ele encontra o voo, chama a funcao de remover da listavoos e depois atualiza a hora da ultima atualizacao e a quant. de voos na lista
int remover_voo(Matriz_Voos *MVoos, tipovoo *voo, int Vid){
    int i=0, j=0;

    for (i=0;i<24;i++) {
        for (j=0;j<24;j++) {
            if(ProcuraVoo_lista(&MVoos->IMatriz[i][j].lvoo, voo, Vid) == 1){
                Lista_remove(&MVoos->IMatriz[i][j].lvoo, voo, Vid);
                Set_h_ultima_att(&MVoos->IMatriz[i][j]);
                Set_n_voos(&MVoos->IMatriz[i][j]);
                return 1;
            }
        }
    }
    return 0;
}

//Recebe a matriz, um pontiro para voo e o id do voo a ser procurado
//ele vai armazenar a onde o ponteiro aponta o voo solicitado
//e ira retornar 1 se o voo foi encontrado, ou 0 se não foi encontrado
int localizar_voo_matriz(Matriz_Voos *MVoos, tipovoo *voo, int Vid) {
    int i = 0, j = 0;

    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            if (ProcuraVoo_lista(&MVoos->IMatriz[i][j].lvoo, voo, Vid) == 1) {
                return 1;
            }
        }
    }
    return 0;// se � achou retorna zero
}

//recebe uma matriz e a posicao i e j
//imprimi todos os voos da lista da posicao i e j
void imprimir_voo(Matriz_Voos *MVoos, int i, int j){
    tcelula *aux = MVoos->IMatriz[i][j].lvoo.primeiro->prox;

    if(aux == NULL){
        printf("\n\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
               "|                              |\n"
               "|         LISTA ESTA VAZIA     |\n"
               "|                              |\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
    }
    if ( i != 25 && aux != NULL){
        printf("\n\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
               "|                                                     |\n"
               "|                TODOS OS VOOS COM                    |\n"
               "|            HORA DE DECOLAGEM = %d:00                |\n"
               "|               HORA DE POUSO = %d:00                 |\n"
               "|                                                     |\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-", i, j);
    }
    while(aux != NULL){
        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
               "|                                           |\n"
               "|               ID = %d                     |\n"
               "|         HORA DE DECOLAGEM = %s         |\n"
               "|     HORA DE PREVISAO DE POUSO = %s     |\n"
               "|       AEROPORTO DE DECOLAGEM = %s        |\n"
               "|        AEROPORTO DE POUSO = %s           |\n"
               "|               PISTA = %d                   |\n"
               "|                                           |\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
               getvid(&aux->voo), getHD(&aux->voo), getHP(&aux->voo), getAD(&aux->voo), getAP(&aux->voo), getpista(&aux->voo));
        aux = aux->prox;
    }

}

//recebe uma matriz e a posicao j
//imprimi todos voos das listas da coluna j
void imprimir_voos_HP(Matriz_Voos *MVoos, int j){ //i = hora de decolagem
    int i = 0;
    printf("\n\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                                     |\n"
           "| TODOS OS VOOS COM HORA DE POUSO DE %d:00 ATE %d:59  |\n"
           "|                                                     |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-", j, j);
    for (i=0; i<24; i++){
        tcelula *aux = MVoos->IMatriz[i][j].lvoo.primeiro->prox;
        while (aux != NULL) {
            printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                   "|                                           |\n"
                   "|               ID = %d                     |\n"
                   "|         HORA DE DECOLAGEM = %s         |\n"
                   "|     HORA DE PREVISAO DE POUSO = %s     |\n"
                   "|       AEROPORTO DE DECOLAGEM = %s        |\n"
                   "|        AEROPORTO DE POUSO = %s           |\n"
                   "|               PISTA = %d                   |\n"
                   "|                                           |\n"
                   "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
                   getvid(&aux->voo), getHD(&aux->voo), getHP(&aux->voo), getAD(&aux->voo), getAP(&aux->voo), getpista(&aux->voo));
            aux = aux->prox;
        }
    }
}

//recebe uma matriz e a posicao i
//imprimi todos voos das listas da linha i
void imprimir_voos_HD(Matriz_Voos *MVoos, int i){ //j = hora de pouso
    int j = 0;
    printf("\n\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                                         |\n"
           "| TODOS OS VOOS COM HORA DE DECOLAGEM DE %d:00 ATE %d:59  |\n"
           "|                                                         |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-", i, i);
    for (j=0; j<24; j++){
        tcelula *aux = MVoos->IMatriz[i][j].lvoo.primeiro->prox;
        while (aux != NULL) {
            printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                   "|                                           |\n"
                   "|               ID = %d                     |\n"
                   "|         HORA DE DECOLAGEM = %s         |\n"
                   "|     HORA DE PREVISAO DE POUSO = %s     |\n"
                   "|       AEROPORTO DE DECOLAGEM = %s        |\n"
                   "|        AEROPORTO DE POUSO = %s           |\n"
                   "|               PISTA = %d                   |\n"
                   "|                                           |\n"
                   "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
                   getvid(&aux->voo), getHD(&aux->voo), getHP(&aux->voo), getAD(&aux->voo), getAP(&aux->voo), getpista(&aux->voo));
            aux = aux->prox;
        }
    }
}

//recebe uma matriz
//imprimi todos voos das listas da matriz
void imprimir_toda_matriz(Matriz_Voos *MVoos) {
    int i = 0, j = 0;
    printf("\n\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                                     |\n"
           "|    TODOS OS VOOS QUE ESTAM NA MATRIZ ATUALMENTE     |\n"
           "|                                                     |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-");
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            tcelula *aux = MVoos->IMatriz[i][j].lvoo.primeiro->prox;
            while (aux != NULL) {
                printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                       "|                                           |\n"
                       "|               ID = %d                     |\n"
                       "|         HORA DE DECOLAGEM = %s         |\n"
                       "|     HORA DE PREVISAO DE POUSO = %s     |\n"
                       "|       AEROPORTO DE DECOLAGEM = %s        |\n"
                       "|        AEROPORTO DE POUSO = %s           |\n"
                       "|               PISTA = %d                   |\n"
                       "|                                           |\n"
                       "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
                       getvid(&aux->voo), getHD(&aux->voo), getHP(&aux->voo), getAD(&aux->voo), getAP(&aux->voo), getpista(&aux->voo));
                aux = aux->prox;
            }
        }

    }
}

//recebe uma matriz
//imprimi as posicoes da matriz com maior numero de voos
void Get_maior_n_voos(Matriz_Voos *MVoos) {
    int i, j, max_i, max_j, maior_num, n_voos;
    max_i = 0;
    max_j = 0;
    i = 0;
    j = 0;
    maior_num = 0;
    n_voos = 0;
    while (i != 24) {
        while (j != 24) {
            n_voos = Get_n_voos(&MVoos->IMatriz[i][j]);
            if (n_voos > maior_num) {
                maior_num = n_voos;
                max_i = i;
                max_j = j;
            }
            j++;
        }
        i++;
        j = 0;
    }
    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                           |\n"
           "|      HORARIO COM MAIOR NUMERO DE VOO'S    |\n"
           "|                                           |\n"
           "|          HORA DE DECOLAGEM = %d:00        |\n"
           "|       HORA DE PREVISAO DE POUSO = %d:00   |\n"
           "|          TEM %d VOO(s) CADASTRADOS         |\n"
           "|                                           |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*",
         max_i, max_j, Get_n_voos(&MVoos->IMatriz[max_i][max_j]));
}

//recebe uma matriz
//imprimi as posicoes da matriz com menor numero de voos
void Get_menor_n_voos(Matriz_Voos *MVoos){
    int i, j, max_i, max_j, menor_num, n_voos;
    i = 0;
    j = 0;
    max_i = 0;
    max_j = 0;
    n_voos = 0;
    menor_num = Get_n_voos(&MVoos->IMatriz[i][j]);
    while (i != 24) {
        while (j != 24) {
            n_voos = Get_n_voos(&MVoos->IMatriz[i][j]);
            if (n_voos < menor_num){
                menor_num = n_voos;
                max_i = i;
                max_j = j;
            }
            j ++;
        }
        i ++;
        j = 0;
    }
    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                           |\n"
           "|      HORARIO COM MENOS NUMERO DE VOO'S    |\n"
           "|                                           |\n"
           "|          HORA DE DECOLAGEM = %d:00         |\n"
           "|       HORA DE PREVISAO DE POUSO = %d:00    |\n"
           "|          TEM %d VOO(s) CADASTRADOS         |\n"
           "|                                           |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*",
           max_i, max_j, Get_n_voos(&MVoos->IMatriz[max_i][max_j]));
}

//Recebe uma matriz
//imprimi as posicoes da matriz com hora de atualizacao mais recente
void Get_recente_att(Matriz_Voos *MVoos){
    int i, j, max_i, max_j, n, n_maior;
    i = 0;
    j = 0;
    max_i = 0;
    max_j = 0;
    n = 0;
    n_maior = conversor_horacompleta(MVoos->IMatriz[i][j].h_ultima_att);
    while (i != 24) {
        while (j != 24) {
            n = conversor_horacompleta(MVoos->IMatriz[i][j].h_ultima_att);
            if (n > n_maior){
                n_maior = n;
                max_i = i;
                max_j = j;
            }
            j ++;
        }
        i ++;
        j = 0;
    }
    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                           |\n"
           "|      HORARIO RECENTEMENTE ATUALIZADO      |\n"
           "|                                           |\n"
           "|       ULTIMA ATUALIZACAO = %s       |\n"
           "|          HORA DE DECOLAGEM = %d:00        |\n"
           "|       HORA DE PREVISAO DE POUSO = %d:00   |\n"
           "|          TEM %d VOO(s) CADASTRADOS         |\n"
           "|                                           |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
           Get_h_ultima_att(&MVoos->IMatriz[max_i][max_j]), max_i, max_j, Get_n_voos(&MVoos->IMatriz[max_i][max_j]));
}

//Recebe uma matriz
//imprimi as posicoes da matriz com hora de atualizacao mais antiga
void Get_antigo_att(Matriz_Voos *MVoos){
    int i, j, max_i, max_j, n, n_menor;
    i = 0;
    j = 0;
    max_i = 0;
    max_j = 0;
    n = 0;
    n_menor = 0;
    n_menor = conversor_horacompleta(MVoos->IMatriz[i][j].h_ultima_att);
    while (i != 24) {
        while (j != 24) {
            n = conversor_horacompleta(MVoos->IMatriz[i][j].h_ultima_att);
            if (n < n_menor){
                n_menor = n;
                max_i = i;
                max_j = j;
            }
            j ++;
        }
        i ++;
        j = 0;
    }
    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                           |\n"
           "|    HORARIO COM ATUALIZACAO MAIS ANTIGA    |\n"
           "|                                           |\n"
           "|       ULTIMA ATUALIZACAO = %s       |\n"
           "|          HORA DE DECOLAGEM = %d:00         |\n"
           "|       HORA DE PREVISAO DE POUSO = %d:00    |\n"
           "|          TEM %d VOO(s) CADASTRADOS         |\n"
           "|                                           |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
           Get_h_ultima_att(&MVoos->IMatriz[max_i][max_j]), max_i, max_j, Get_n_voos(&MVoos->IMatriz[max_i][max_j]));
}

//recebe uma matriz
//percorre a matiz fazendo a soma de quantos voos tem no total dentra de toda a matriz
//e armazena essa soma na variavel n_voos existente dentro da estrutura matriz
void n_total_voos (Matriz_Voos *Mvoos) {
    int i, j, total;
    total = 0;
    i = 0;
    j = 0;
    while (i != 24) {
        while (j != 24) {
            total = total + Get_n_voos(&Mvoos->IMatriz[i][j]);
            j++;
        }
        i++;
        j = 0;
    }
    Mvoos->n_voos = total;
}

//recebe uma matriz
//confere se a matriz e esparca
//ou seja se a quant de posicoes da matriz com nenhum voo e o dobro ou mais que a quant de posicoes com pelo menos 1 voo
int Verifica_esparca(Matriz_Voos *MVoos){
    int i, j, pos_sem_voos, pos_com_voos;
    i = 0;
    j = 0;
    pos_com_voos = 0;
    pos_sem_voos = 0;
    while (i != 24) {
        while (j != 24) {
            if (Get_n_voos(&MVoos->IMatriz[i][j]) == 0){
                pos_sem_voos ++;
            }
            else{
                pos_com_voos ++;
            }
            j ++;
        }
        i ++;
        j = 0;
    }
    if ((pos_sem_voos*pos_sem_voos) >= pos_com_voos){
        return 1;
    }
    return 0;
}

//recebe um char
//e retorna a conversao das dois primeiros caracteres convertidos em um int
//ex: char = 11:00:00 retorna int = 11
int conversor_ij (char* hora){
    int n = ((hora[0] - '0')*10) + (hora[1] - '0');
    return n;
}

//faz o mesmo processo da funcao conversor_ij
//porem ele converte os 4 caracteres do char
//ex: char = 12:20:00 retorna int = 1220
//essa funcao e para fazer as comparacoes das funcoes GET da matriz com mais facilidade
int conversor_horacompleta (char* hora){
    int n;
    n = ((hora[0] - '0')*1000) + ((hora[1] - '0')*100) + ((hora[3] - '0')*10) + (hora[4] - '0');
    return n;
}