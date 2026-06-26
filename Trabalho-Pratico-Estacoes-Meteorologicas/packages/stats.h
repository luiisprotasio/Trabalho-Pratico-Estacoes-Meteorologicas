#ifndef STATSH
#define STATSH
float calcularMediaRecursiva(float *leituras, int n); /*calcula recursivamente a médias das leituras*/
float calcularMedia(float *leituras,int n);//calcula normalmente a média das leituras
float achaMaior(float *leituras, int n); //encontra o maior valor dentro das leituras
float achaMenor(float *leituras, int n); //encontra o menor valor dentro das leituras
float calcularVariancia(float *leituras, int n); //calcula a variancia das leituras
float calcularDesvioPadrao(float *leituras, int n);//calcula o desvio padrão das leituras
#endif