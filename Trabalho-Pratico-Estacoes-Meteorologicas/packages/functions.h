#ifndef FUNCTIONSH
#define FUNCTIONSH
#include "../packages/stations.h"
void clean();//Limpa o buffer
int verificaCorteEntrada(char *str);//Verifica se a entrada foi cortada pelo limite do buffer na leitura de dados. Retorna 1 caso haja erro, 0 caso esteja tudo certo.
int verificaAlfa(char *str);//Verifica que a string só contém caracteres alfabéticos. Retorna 1 caso haja caracteres estranhos à regra, 0 caso sejam todos alfabéticos.
void formatarEntry(char *str);//Formata a string vinda do fgets. Esta função retorna a string quase identica, porém sem o \n advindo do fgets no final. 
int verificaData(DataLeitura data);//Verifica a validade da data inserida. Retorna 1 caso haja alguma incoerencia, 0 caso esteja tudo de acordo.
#endif