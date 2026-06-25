#ifndef STATIONH
#define STATIONH

typedef struct DataLeitura {
    int dia;
    int mes;
    int ano;
}DataLeitura;
typedef struct Estacao {
    int id;
    char nome[40];
    char operador[40];
    char sensor[20];
    int n; //QUANTIDADE DE LEITURAS
    float *leituras;
    float desvioPadrao;
    DataLeitura data;
}Estacao;

/*struct Estacao adicionarEstacao(); pretendia fazer desta forma, mas optei por fazer passagem por ponteiros...*/
void adicionarEstacao(Estacao *name);
void editarEstacao(Estacao *name);
void removerEstacao(Estacao *name);
void listarEstacoes();
void buscarPorOperador(char *name);
void detectarAnomalias(Estacao *name);
#endif