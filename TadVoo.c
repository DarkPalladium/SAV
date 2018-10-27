//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "TadVoo.h"

//Recebe um tipo voo
//e deixa todas a sua estrtura zerada
void inicializa_voo (tipovoo *voo) {
    voo->VID = 0;
    voo->pista = 0;
    strcpy(voo->aeropousar, """");
    strcpy(voo->aerodecolar, """");
    strcpy(voo->horapouso, """");
    strcpy(voo->horadecolar, """");
}

//Essa função recebe todas as informações necessarias para preencher o voo
//E coloca elas em seus devidos lugares e volta para o main
void novovoo (tipovoo *voo, char* h_decolar, char* h_pouso, char* a_decolar, char* a_pouso, int pista){
    int aux;
    aux = 1 + (rand() % 1000); // estamos utilizando a funcao rand para gerar o ID aleatorio
    setVID(voo, aux);
    setHD(voo, h_decolar);
    setHP(voo, h_pouso);
    setAD(voo, a_decolar);
    setAP(voo, a_pouso);
    setpista(voo, pista);
}

//Todas as funções GET's tem a tarefa de receber um Tipo voo
// E retornar uma informação contida dentro do tipo voo
int getvid (tipovoo *voo){
    return voo->VID;
}

char* getHD (tipovoo *voo){
    return voo->horadecolar;
}
char* getHP (tipovoo *voo){
    return voo->horapouso;
}
int getpista (tipovoo *voo){
    return voo->pista;
}
char* getAD (tipovoo *voo){
    return voo->aerodecolar;
}
char* getAP (tipovoo *voo){
    return voo->aeropousar;
}

//Todas as funções SET's tem a tarefa de receber um Tipo voo e a variavel que será modificada
// E substituir a informação solicitada
void setHD (tipovoo *voo, char* hora){
    strcpy(voo->horadecolar, hora);
}
void setHP (tipovoo *voo, char* hora){
    strcpy(voo->horapouso, hora);
}
void setpista (tipovoo *voo, int pista){
    voo->pista = pista;
}
void setAD (tipovoo *voo, char* aeroporto){
    strcpy(voo->aerodecolar, aeroporto);
}
void setAP (tipovoo *voo, char* aeroporto){
    strcpy(voo->aeropousar, aeroporto);
}
void setVID (tipovoo *voo, int id){
    voo->VID = id;
}
void imprimir_voo_procura (tipovoo *voo){
    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                           |\n"
           "|               ID = %d                     |\n"
           "|         HORA DE DECOLAGEM = %s         |\n"
           "|     HORA DE PREVISAO DE POUSO = %s     |\n"
           "|               PISTA = %d                   |\n"
           "|                                           |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n",
           getvid(voo), getHD(voo), getHP(voo), getpista(voo));
}