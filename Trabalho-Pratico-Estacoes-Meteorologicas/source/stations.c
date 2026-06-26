#include "../packages/functions.h"
#include "../packages/stations.h"
#include "../packages/stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void adicionarEstacao(Estacao **name){
    char temp;
    int id;
    printf("Criando estação! Digite o ID da estação.\n");
    while(scanf("%d%c",&id,&temp)!=2||id>9999||id<0){
    printf("ID inválido. O identificador deve ser tal que 0<ID<9999.\n");  
    clean();
}
    if (name[id]!=NULL){
        printf("Já existe uma estação com este id...\n");
        return;
    }
    name[id]=(Estacao *)calloc(1,sizeof(Estacao));
    if(name[id]==NULL){
        return;
    }
    Estacao *estacaoAtual = name[id];
    estacaoAtual->id= id;
    
    printf("Configurando estação %d. Informe o nome da estação.\n",estacaoAtual->id);
    fgets(estacaoAtual->nome,sizeof(estacaoAtual->nome),stdin);
    while(verificaCorteEntrada(estacaoAtual->nome)||verificaAlfa(estacaoAtual->nome)){
        printf("Nome inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(estacaoAtual->nome,sizeof(estacaoAtual->nome),stdin);
    }formatarEntry(estacaoAtual->nome); 
     printf("Nome registrado. Informe o nome do operador.\n");
    fgets(estacaoAtual->operador,sizeof(estacaoAtual->operador),stdin);
    while(verificaCorteEntrada(estacaoAtual->operador)||verificaAlfa(estacaoAtual->operador)){
        printf("Operador inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(estacaoAtual->operador,sizeof(estacaoAtual->operador),stdin);
    }formatarEntry(estacaoAtual->operador); 
    printf("Operador registrado. Informe o sensor da estação.\n");
    fgets(estacaoAtual->sensor,sizeof(estacaoAtual->sensor),stdin);
    while(verificaCorteEntrada(estacaoAtual->sensor)||verificaAlfa(estacaoAtual->sensor)){
        printf("Sensor inválido. Tenha certeza de que o nome tenha no máximo 59 caracteres,todos alfabéticos,e tente novamente.\n");
        fgets(estacaoAtual->sensor,sizeof(estacaoAtual->sensor),stdin);
    }formatarEntry(estacaoAtual->sensor);  
    printf("Sensor registrado. Estação pronta para registrar leituras! Informe o número de leituras a serem feitas.\n");
    while(scanf("%d%c",&estacaoAtual->n,&temp)!=2||temp!='\n'||estacaoAtual->n<=0||estacaoAtual->n>9999){ printf("Número inválido. Certifique-se de inserir somente um inteiro entre 1 e 9999\n");
    clean();
    }
    estacaoAtual->leituras = (float *)calloc(estacaoAtual->n,sizeof(float));
    if (estacaoAtual->leituras==NULL){
        printf("Erro na alocação da memória.");
        return;
    }
    printf("Foram alocadas %d leituras.Registrando %d leituras. Digite-as uma por vez.\n",estacaoAtual->n,estacaoAtual->n);
    for (int i =0;i<estacaoAtual->n;i++){
        if(scanf("%f%c",&estacaoAtual->leituras[i],&temp)!=2||temp!='\n'){
            printf("Leitura inválida. Tente novamente.\n");
            i--;
            clean();
        }
    }   printf("Leituras registradas. Informe a data da leitura (dd/mm/aaaa).\n");
    while(scanf("%d/%d/%d",&estacaoAtual->data.dia,&estacaoAtual->data.mes,&estacaoAtual->data.ano)!=3||verificaData(estacaoAtual->data)){
        printf("Data inválida. Certifique-se de inserir uma data válida seguindo o modelo dd/mm/aaaa.\n");
        clean();
    }
    printf("Data registrada com sucesso. Calculando estatísticas...\n");
    estacaoAtual->media=calcularMediaRecursiva(estacaoAtual->leituras,estacaoAtual->n);
    estacaoAtual->variancia= calcularVariancia(estacaoAtual->leituras,estacaoAtual->n);
    estacaoAtual->desvioPadrao=calcularDesvioPadrao(estacaoAtual->leituras,estacaoAtual->n);
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