//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matriz_Voos.h"

int main()
{
    int id, pista, operacao_sistema, auxiliar_while;
    char aerodecolar[50], aeropousar[50], horadecolar[10], horapouso[10], operacao_interativa[5], operador[2];
    tipovoo voo_aleatorio;
    Matriz_Voos Matriz_Primaria; //Declarando a Matriz de Voos (que e do tipo Matriz_Voos).
    auxiliar_while = 1; // Auxiliar da operacao. Enquanto for diferente de 0 ele continuara.

    while (operacao_sistema != 0){
        printf("\n\n----------------- BEM VINDO AO SAV -------------------\n\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
               "|                                                    |\n"
               "| ESCOLHA UMA DAS SEGUINTES FORMAS DE INICIALIZACAO: |\n"
               "|                                                    |\n"
               "| INTERATIVO = 1                                     |\n"
               "| POR AQUIVO = 2                                     |\n"
               "| ENCERRAR OPERACOES = 0                             |\n"
               "|                                                    |\n"
               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&operacao_sistema);

        if (operacao_sistema == 1){       // Operacao referente ao sistema interativo.

            auxiliar_while = 7; // esta sendo utilizado para que a condição do while seja verdadeira.
            while (auxiliar_while!=0){
                printf("\n\n"
                       "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                       "|                                                                                                   |\n"
                       "| QUAL OPERACAO DESEJA REALIZAR:                                                                    |\n"
                       "|                                                                                                   |\n"
                       "| a) Inicializar                                                                                    |\n"
                       "| b) Inserir voo;                                                                                   |\n"
                       "| c) Remover voo;                                                                                   |\n"
                       "| d) Procurar voo;                                                                                  |\n"
                       "| e) Imprimir voos (Horariso de Decolagem e de Pouso);                                              |\n"
                       "| f) Imprimir voos (Horario de Decolagem);                                                          |\n"
                       "| g) Imprimir voos (Horagem de Pouso);                                                              |\n"
                       "| h) Imprimir todos os voos;                                                                        |\n"
                       "| i) Procurar faixa de horario decolagem e previsao de pouso com maior numero de voos cadastrados;  |\n"
                       "| j) Procurar faixa de horario decolagem e previsao de pouso com menor numero de voos cadastrados;  |\n"
                       "| k) Encontrar a lista de voos mais recentemente alterada;                                          |\n"
                       "| l) Encontra a lista de voos menos recentemente alterada;                                          |\n"
                       "| m) Verificar se a matriz e esparca.                                                               |\n"
                       "|                                                                                                   |\n"
                       "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n"
                       "DIGITE A OPCAO DESEJADA: ");
                scanf("%s",operacao_interativa);
                printf("\n\n");


                if (strcmp(operacao_interativa,"a")==0 || strcmp(operacao_interativa,"A")==0){
                    inicializar_matriz(&Matriz_Primaria); // Iniciando o TAD Matriz de Voos.
                    inicializa_voo(&voo_aleatorio); // Iniciando o TAD Voo.
                }


                if (strcmp(operacao_interativa,"b")==0 || strcmp(operacao_interativa,"B")==0){
                    printf("DIGITE A HORA DE DECOLAGEM: ");
                    scanf("%s",horadecolar);
                    printf("DIGITE A HORA DE POUSO: ");
                    scanf("%s",horapouso);
                    printf("DIGITE O AEROPORTO DE DECOLAGEM: ");
                    scanf("%s",aerodecolar);
                    printf("DIGITE O AEROPORTO DE POUSO: ");
                    scanf("%s",aeropousar);
                    printf("DIGITE A PISTA: ");
                    scanf("%d", &pista);
                    novovoo(&voo_aleatorio, horadecolar, horapouso, aerodecolar, aeropousar, pista);
                    inserir_voo(&Matriz_Primaria,&voo_aleatorio,conversor_ij(getHD(&voo_aleatorio)), conversor_ij(getHP(&voo_aleatorio)));
                    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                           "|                                           |\n"
                           "|         VOO ADICIONADO COM SUCESSO        |\n"
                           "|                ID DO VOO = %d             |\n"
                           "|                                           |\n"
                           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*", getvid(&voo_aleatorio));

                }
                if (strcmp(operacao_interativa,"c")==0 || strcmp(operacao_interativa,"C")==0){
                    printf("DIGITE O ID DO VOO A SER REMOVIDO:");
                    scanf("%d",&id);
                    if(remover_voo(&Matriz_Primaria, &voo_aleatorio, id) == 1){
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|         VOO REMOVIDO COM SUCESSO          |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                    else{
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|            VOO NAO ENCONTRADO             |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }
                if (strcmp(operacao_interativa,"d")==0 || strcmp(operacao_interativa,"D")==0){
                    printf("Digite o ID do voo que procura: ");
                    scanf("%d", &id);
                    if (localizar_voo_matriz(&Matriz_Primaria, &voo_aleatorio, id) == 1){
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|               VOO ENCONTRADO              |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                        imprimir_voo_procura(&voo_aleatorio);
                    }
                    else{
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|             VOO NAO ENCONTRADO            |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }
                if (strcmp(operacao_interativa,"e")==0 || strcmp(operacao_interativa,"E")==0){
                    printf("DIGITE A HORA DE DECOLAGEM ");
                    scanf("%s", horadecolar);
                    printf("\n");
                    printf("DIGITE A HORA DE PREVISAO DE POUSO: ");
                    scanf("%s", horapouso);
                    printf("\n\n");
                    imprimir_voo(&Matriz_Primaria, conversor_ij(horadecolar), conversor_ij(horapouso));
                }
                if (strcmp(operacao_interativa,"f")==0 || strcmp(operacao_interativa,"F")==0){
                    printf("DIGITE A HORA DE DECOLAGEM: ");
                    scanf("%s", horadecolar);
                    imprimir_voos_HD(&Matriz_Primaria, conversor_ij(horadecolar));
                }
                if (strcmp(operacao_interativa,"g")==0 || strcmp(operacao_interativa,"G")==0){
                    printf("DIGITE A HORA DE PREVISAO DE POUSO: ");
                    scanf("%s", horapouso);
                    imprimir_voos_HP(&Matriz_Primaria, conversor_ij(horapouso));
                }
                if (strcmp(operacao_interativa,"h")==0 || strcmp(operacao_interativa,"H")==0){
                    imprimir_toda_matriz(&Matriz_Primaria);
                }
                if (strcmp(operacao_interativa,"i")==0 || strcmp(operacao_interativa,"I")==0){
                    Get_maior_n_voos(&Matriz_Primaria);

                }
                if (strcmp(operacao_interativa,"j")==0 || strcmp(operacao_interativa,"J")==0){
                    Get_menor_n_voos(&Matriz_Primaria);
                }
                if (strcmp(operacao_interativa,"k")==0 || strcmp(operacao_interativa,"K")==0){
                    Get_recente_att(&Matriz_Primaria);
                }
                if (strcmp(operacao_interativa,"l")==0 || strcmp(operacao_interativa,"L")==0){
                    Get_antigo_att(&Matriz_Primaria);
                }
                if (strcmp(operacao_interativa,"m")==0 || strcmp(operacao_interativa,"M")==0){
                    Verifica_esparca(&Matriz_Primaria);
                    if (Verifica_esparca(&Matriz_Primaria)==1){
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|          A MATRIZ E ESPARCA               |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                    else{
                        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|          A MATRIZ NAO E ESPARCA           |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }
                printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                       "| GOSTARIA DE EFETUAR OUTRA OPERACAO:       |\n"
                       "| SIM = 1                                   |\n"
                       "| NAO = 0                                   |\n"
                       "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n"
                       "DIGITE OPERACAO DESEJADA: ");
                scanf("%d",&auxiliar_while);
            }
        }
        if (operacao_sistema==2){

            FILE *ptr_arq;

            ptr_arq = fopen("entrada1.txt", "r");

            if ((ptr_arq = fopen("entrada1.txt","r"))==NULL)
                printf("Erro na abertura do arquivo.\n\n");

            else
                printf("Arquivo aberto com sucesso!\n\n");

            while ((fscanf(ptr_arq,"%s",operador))!= EOF){
                if (strcmp(operador,"a")==0){
                    inicializar_matriz(&Matriz_Primaria);
                    inicializa_voo(&voo_aleatorio);
                }
                if (strcmp(operador,"b")==0 || strcmp(operador,"B")==0){
                    fscanf(ptr_arq,"%s",horadecolar);
                    fscanf(ptr_arq,"%s",horapouso);
                    fscanf(ptr_arq,"%s",aerodecolar);
                    fscanf(ptr_arq,"%s",aeropousar);
                    fscanf(ptr_arq,"%d",&pista);
                    novovoo(&voo_aleatorio,horadecolar,horapouso,aerodecolar,aeropousar,pista);
                    inserir_voo(&Matriz_Primaria,&voo_aleatorio,conversor_ij(getHD(&voo_aleatorio)), conversor_ij(getHP(&voo_aleatorio)));
                    printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                           "|                                           |\n"
                           "|         VOO ADICIONADO COM SUCESSO        |\n"
                           "|                ID DO VOO = %d             |\n"
                           "|                                           |\n"
                           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*", getvid(&voo_aleatorio));
                }
                if (strcmp(operador,"c")==0 || strcmp(operador,"C")==0){
                    fscanf(ptr_arq,"%d",&id);
                    remover_voo(&Matriz_Primaria, &voo_aleatorio, id);

                    if(remover_voo(&Matriz_Primaria, &voo_aleatorio, id) == 0){
                        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|            VOO NAO ENCONTRADO             |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                    else{
                        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|         VOO REMOVIDO COM SUCESSO          |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }
                if (strcmp(operador,"d")==0 || strcmp(operador,"D")==0){
                    fscanf(ptr_arq,"%d",&id);
                    if (localizar_voo_matriz(&Matriz_Primaria, &voo_aleatorio, id)==1){
                        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|               VOO ENCONTRADO              |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                        imprimir_voo_procura(&voo_aleatorio);
                    }
                    else{
                        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|             VOO NAO ENCONTRADO            |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }

                if (strcmp(operador,"e")==0 || strcmp(operador,"E")==0){
                    fscanf(ptr_arq,"%s",horadecolar);
                    fscanf(ptr_arq,"%s",horapouso);
                    imprimir_voo(&Matriz_Primaria,conversor_ij(getHD(&voo_aleatorio)), conversor_ij(getHP(&voo_aleatorio)));
                }
                if (strcmp(operador,"f")==0 || strcmp(operador,"F")==0){
                    fscanf(ptr_arq,"%s",horadecolar);
                    imprimir_voos_HD(&Matriz_Primaria,conversor_ij(getHD(&voo_aleatorio)));

                }
                if (strcmp(operador,"g")==0 || strcmp(operador,"G")==0){
                    fscanf(ptr_arq,"%s",horapouso);
                    imprimir_voos_HP(&Matriz_Primaria,conversor_ij(getHP(&voo_aleatorio)));
                }
                if (strcmp(operador,"h")==0 || strcmp(operador,"H")==0){
                    imprimir_toda_matriz(&Matriz_Primaria);
                }
                if (strcmp(operador,"i")==0 || strcmp(operador,"I")==0){
                    Get_maior_n_voos(&Matriz_Primaria);

                }
                if (strcmp(operador,"j")==0 || strcmp(operador,"J")==0){
                    Get_menor_n_voos(&Matriz_Primaria);
                }
                if (strcmp(operador,"k")==0 || strcmp(operador,"K")==0){
                    Get_recente_att(&Matriz_Primaria);
                }
                if (strcmp(operador,"l")==0 || strcmp(operador,"L")==0){
                    Get_antigo_att(&Matriz_Primaria);
                }
                if (strcmp(operador,"m")==0 || strcmp(operador,"M")==0){
                    Verifica_esparca(&Matriz_Primaria);
                    if (Verifica_esparca(&Matriz_Primaria)==1){
                        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|          A MATRIZ E ESPARCA               |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                    else{
                        printf("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
                               "|                                           |\n"
                               "|          A MATRIZ NAO E ESPARCA           |\n"
                               "|                                           |\n"
                               "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    }
                }
            }
            fclose(ptr_arq);
        }
    }
    printf("\n\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n"
           "|                                           |\n"
           "|       OGRIGADO POR UTILIZAR O SAV         |\n"
           "|                                           |\n"
           "|   DESENVOLVEDORES:                        |\n"
           "|       PABLO MIRANDA BATISTA               |\n"
           "|       LUCAS RANIERI OLIVEIRA MARTINS      |\n"
           "|       JOAO VICTOR MAGALHAES SOUZA         |\n"
           "|                                           |\n"
           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    return 0;
}
