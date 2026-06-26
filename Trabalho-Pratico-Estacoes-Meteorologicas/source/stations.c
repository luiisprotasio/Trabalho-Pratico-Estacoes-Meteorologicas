 #include "../packages/functions.h"
  #include "../packages/stations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void adicionarEstacao(Estacao *name){
    printf("Registrando nova estação...\nInsira o ID da Estação:\n");
    while(scanf("%d",name->id)<0||name->id>9999){
    printf("ID inválido. O identificador deve ser tal que 0<ID<9999.\n");
    }
    printf("ID registrado. Informe o nome da estação.\n");
    fgets(name->nome,sizeof(name->nome),stdin);
    while(verificaCorteEntrada(name->nome)||verificaAlfa(name->nome)){
        printf("Nome inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres e tente novamente.\n");
        fgets(name->nome,sizeof(name->nome),stdin);
    }

}
void editarEstacao(Estacao *name);
void removerEstacao(Estacao *name);
void listarEstacoes();
void buscarPorOperador(char *name);
void detectarAnomalias(Estacao *name);