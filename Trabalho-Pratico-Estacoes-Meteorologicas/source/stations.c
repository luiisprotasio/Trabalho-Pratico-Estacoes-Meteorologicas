#include "../packages/functions.h"
#include "../packages/stations.h"
#include "../packages/stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int criaEstacao(Estacao **lista){
    char temp;
    int id;
while(scanf("%d%c",&id,&temp)!=2||id>9999||id<0){
    printf("ID inválido. O identificador deve ser tal que 0<ID<9999.\n");  
    clean();
}
    if (lista[id]!=NULL){
        printf("Já existe uma estação com este id...\n");
        return 1;
    }
    lista[id]=(Estacao *)calloc(1,sizeof(Estacao));
    if(lista[id]==NULL){
        return 1;
    }
    return 0;
}
void adicionarEstacao(Estacao *name){
    char temp;
    while(criaEstacao(name)){
        printf("Houve um erro na criação da estação. Tentando novamente.\n");
    }
  
    printf("Configurando estação %d. Informe o nome da estação.\n",name->id);
    fgets(name->nome,sizeof(name->nome),stdin);
    while(verificaCorteEntrada(name->nome)||verificaAlfa(name->nome)){
        printf("Nome inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->nome,sizeof(name->nome),stdin);
    }formatarEntry(name->nome); 
     printf("Nome registrado. Informe o nome do operador.\n");
    fgets(name->operador,sizeof(name->operador),stdin);
    while(verificaCorteEntrada(name->operador)||verificaAlfa(name->operador)){
        printf("Operador inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->operador,sizeof(name->operador),stdin);
    }formatarEntry(name->operador); 
    printf("Operador registrado. Informe o sensor da estação.\n");
    fgets(name->sensor,sizeof(name->sensor),stdin);
    while(verificaCorteEntrada(name->sensor)||verificaAlfa(name->sensor)){
        printf("Sensor inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->sensor,sizeof(name->sensor),stdin);
    }formatarEntry(name->sensor);  
    printf("Sensor registrado. Estação pronta para registrar leituras! Informe o número de leituras a serem feitas.\n");
    while(scanf("%d%c",&name->n,&temp)!=2||temp!='\n'||name->n<=0||name->n>9999){ printf("Número inválido. Certifique-se de inserir somente um inteiro entre 1 e 9999\n");
    clean();
    }
    name->leituras = (float *)calloc(name->n,sizeof(float));
    if (name->leituras==NULL){
        printf("Erro na alocação da memória.");
        return;
    }
    printf("Foram alocadas %d leituras.Registrando %d leituras. Digite-as uma por vez.\n",name->n,name->n);
    for (int i =0;i<name->n;i++){
        if(scanf("%f%c",&name->leituras[i],&temp)!=2||temp!='\n'){
            printf("Leitura inválida. Tente novamente.\n");
            i--;
            clean();
        }
    }   printf("Leituras registradas. Informe a data da leitura (dd/mm/aaaa).\n");
    while(scanf("%d/%d/%d",&name->data.dia,&name->data.mes,&name->data.ano)!=3||verificaData(name->data)){
        printf("Data inválida. Certifique-se de inserir uma data válida seguindo o modelo dd/mm/aaaa.\n");
        clean();
    }
    printf("Data registrada com sucesso. Calculando estatísticas...\n");
    name->media=calcularMediaRecursiva(name->leituras,name->n);
    name->variancia= calcularVariancia(name->leituras,name->n);
    name->desvioPadrao=calcularDesvioPadrao(name->leituras,name->n);
    printf("Estatísticas calculadas com sucesso!\n");

}



void editarEstacao(Estacao *name,int modo){
    // Permite editar nome(1), operador(2), sensor(3) ou data da estação(4), de acordo com o modo.
if(modo==1){
     printf("MODO NOME: Informe o novo nome da estação.\n");
    fgets(name->nome,sizeof(name->nome),stdin);
    while(verificaCorteEntrada(name->nome)||verificaAlfa(name->nome)){
        printf("Nome inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->nome,sizeof(name->nome),stdin);
    }formatarEntry(name->nome); 
     printf("Nome registrado com sucesso.\n");
     return;
}
if(modo==2){printf("MODO OPERADOR: Informe o novo nome do operador.\n");
    fgets(name->operador,sizeof(name->operador),stdin);
    while(verificaCorteEntrada(name->operador)||verificaAlfa(name->operador)){
        printf("Operador inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->operador,sizeof(name->operador),stdin);
    }formatarEntry(name->operador); 
     printf("Operador registrado com sucesso.\n");
     return;
}

if(modo==3){
    printf("MODO SENSOR: Informe o novo sensor da estação.\n");
    fgets(name->sensor,sizeof(name->sensor),stdin);
    while(verificaCorteEntrada(name->sensor)||verificaAlfa(name->sensor)){
        printf("Sensor inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(name->sensor,sizeof(name->sensor),stdin);
    }formatarEntry(name->sensor);
     printf("Sensor registrado com sucesso.\n"); 
     return;
}
if(modo==4){printf("MODO DATA: Informe a data da leitura (dd/mm/aaaa).\n");
    while(scanf("%d/%d/%d",&name->data.dia,&name->data.mes,&name->data.ano)!=3||verificaData(name->data)){
        printf("Data inválida. Certifique-se de inserir uma data válida seguindo o modelo dd/mm/aaaa.\n");
       clean();
    }
    printf("Data registrada com sucesso.\n");
    return;
}
    printf("Modo inválido. ERRO\n");
    return;


}
void removerEstacao(Estacao *name){
    name=NULL;
}
void removerEstacao(Estacao *name);
void listarEstacoes();
void buscarPorOperador(char *name);
void detectarAnomalias(Estacao *name);