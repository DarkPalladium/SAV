//Autores:
// Pablo Miranda Batista          3482
//Lucas Ranieri Oliveira Martins  3479
//João Victor Magalhães Souza     3483

//Estrutura da TAD voo
typedef struct {
    int VID, pista;
    char aerodecolar[50], aeropousar[50], horadecolar[10], horapouso[10];
}tipovoo;

//FUNCOES DA TAD VOO

void inicializa_voo (tipovoo *voo);
void novovoo (tipovoo *voo, char* h_decolar, char* h_pouso, char* a_decolar, char* a_pouso, int pista);

//GET's
int getvid (tipovoo *voo);
char* getHD (tipovoo *voo);
char* getHP (tipovoo *voo);
int getpista (tipovoo *voo);
char* getAD (tipovoo *voo);
char* getAP (tipovoo *voo);

//SET'S
void setHD (tipovoo *voo, char* hora);
void setHP (tipovoo *voo, char* hora);
void setpista (tipovoo *voo, int pista);
void setAD (tipovoo *voo, char* aeroporto);
void setAP (tipovoo *voo, char* aeroporto);
void setVID (tipovoo *voo, int id);

void imprimir_voo_procura (tipovoo *voo);