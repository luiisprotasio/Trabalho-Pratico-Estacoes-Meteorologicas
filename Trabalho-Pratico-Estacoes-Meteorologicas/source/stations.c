#include "../packages/functions.h"
#include "../packages/stations.h"
#include "../packages/stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void adicionarEstacao(Estacao *name){
    char temp;
    printf("Registrando nova estação...\nInsira o ID da Estação:\n");
    while(scanf("%d",name->id)<0||name->id>9999){
    printf("ID inválido. O identificador deve ser tal que 0<ID<9999.\n");
    }
    printf("ID registrado. Informe o nome da estação.\n");
    fgets(name->nome,sizeof(name->nome),stdin);
    while(verificaCorteEntrada(name->nome)||verificaAlfa(name->nome)){
        printf("Nome inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->nome,sizeof(name->nome),stdin);
    }
     printf("Nome registrado. Informe o nome do operador.\n");
    fgets(name->operador,sizeof(name->operador),stdin);
    while(verificaCorteEntrada(name->operador)||verificaAlfa(name->operador)){
        printf("Operador inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->operador,sizeof(name->operador),stdin);
    } printf("Operador registrado. Informe o sensor da estação.\n");
    fgets(name->sensor,sizeof(name->sensor),stdin);
    while(verificaCorteEntrada(name->sensor)||verificaAlfa(name->sensor)){
        printf("Sensor inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->sensor,sizeof(name->sensor),stdin);
    } printf("Sensor registrado. Estação pronta para registrar leituras! Informe o número de leituras a serem feitas.\n");
    while(scanf("%d%c",&name->n,&temp)!=2||temp!='\n'||name->n<=0||name->n>9999){ printf("Número inválido. Certifique-se de inserir somente um inteiro entre 1 e 9999");
        scanf("%d%c",&name->n,&temp);
    } printf("Registrando %d leituras. Digite-as uma por vez.",name->n);
    for (int i =0;i<name->n;i++){
        if(scanf("%f%c",&name->leituras[i])!=2||temp!='\n'){
            printf("Leitura inválida. Tente novamente.\n");
            i--;
        }
    }   printf("Leituras registradas. Informe a data da leitura (dd/mm/aaaa).\n");
    while(scanf("%d/%d/%d",&name->data.dia,&name->data.mes,&name->data.ano)!=3||verificaData(name->data)){
        printf("Data inválida. Certifique-se de inserir uma data válida seguindo o modelo dd/mm/aaaa.\n");
    } printf("Data registrada com sucesso. Calculando estatísticas...\n");
    name->media=calcularMediaRecursiva(name->leituras,name->n);
    name->variancia= calcularVariancia(name->leituras,name->n);
    name->desvioPadrao=calcularDesvioPadrao(name->leituras,name->n);
    printf("Estatísticas calculadas com sucesso!\n");

}
void editarEstacao(Estacao *name);
void removerEstacao(Estacao *name);
void listarEstacoes();
void buscarPorOperador(char *name);
void detectarAnomalias(Estacao *name);