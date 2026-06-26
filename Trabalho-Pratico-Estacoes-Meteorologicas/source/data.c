 #include "../packages/data.h"

void salvarCSV(Estacao *lista, int qtdEstacoes); //persiste os dados em um arquivo com base em uma lista de estações e a quantidade de estações desta
void carregarCSV(Estacao *lista, int qtdEstacoes, const char *nomeArquivo);// carrega um arquivo cujo nome deve ser informado, extraindo as informações pra memória do programa
