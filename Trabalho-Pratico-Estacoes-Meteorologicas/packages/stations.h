#ifndef STATIONH
#define STATIONH

typedef struct DataLeitura {
    int dia;
    int mes;
    int ano;
}DataLeitura;
typedef struct Estacao {
    int id;
    char nome[60];
    char operador[60];
    char sensor[60];
    int n; //QUANTIDADE DE LEITURAS
    float *leituras;
    float media;
    float variancia;
    float desvioPadrao;
    DataLeitura data;
}Estacao;

/*struct Estacao adicionarEstacao(); pretendia fazer desta forma, mas optei por fazer passagem por ponteiros...*/
void criaEstacao(Estacao **lista);// cria e aloca uma nova estação
void adicionarEstacao(Estacao *name);// Adiciona uma nova estação ao sistema, registrando todos seus dados e automaticamente calculando suas estatísticas.
void editarEstacao(Estacao *name, int modo); // Permite editar nome(1), operador(2), sensor(3) ou data da estação(4), de acordo com o modo.
void removerEstacao(Estacao *name);
void listarEstacoes();
void buscarPorOperador(char *name);
void detectarAnomalias(Estacao *name);
#endif