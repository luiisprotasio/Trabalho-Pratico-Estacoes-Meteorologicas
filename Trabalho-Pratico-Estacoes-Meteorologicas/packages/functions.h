#ifndef FUNCTIONSH
#define FUNCTIONSH
int verificaCorteEntrada(char *str);//Verifica se a entrada foi cortada pelo limite do buffer na leitura de dados. Retorna 1 caso haja erro, 0 caso esteja tudo certo.
int verificaAlfa(char *str);//Verifica que a string só contém caracteres alfabéticos. Retorna 1 caso haja caracteres estranhos à regra, 0 caso sejam todos alfabéticos.
#endif