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
void adicionarEstacao(Estacao **name);// Adiciona uma nova estação ao sistema, registrando todos seus dados e automaticamente calculando suas estatísticas.
void editarEstacao(Estacao *name, int modo); // Permite editar nome(1), operador(2), sensor(3) ou data da estação(4), de acordo com o modo.
void removerEstacao(Estacao **name,int id); // Remove a estação da memória, permitindo que uma nova estação seja criada com o id da antiga
void listarEstacoes(Estacao **name); // Exibe todas as estações e suas estatísticas.
void buscarPorOperador(Estacao **name,char *operador); // Busca todas as estações atribuidas a um operador
void buscarPorSensor(Estacao **name, char *sensor); // Busca todas as estações que tem o mesmo tipo de sensor
void detectarAnomalias(Estacao **name,int id);//detecta quais leituras da estação são anomalas. Leituras anomalas são aquelas que se afastam da média em pelo menos dois desvios-padrão.
#endif