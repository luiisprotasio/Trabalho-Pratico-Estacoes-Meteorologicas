 #include "../packages/data.h"
 #include <stdio.h>
 #include <stdlib.h>

void salvarCSV(Estacao **lista, int qtdEstacoes, const char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo,"w");
    if (arquivo==NULL){
        printf("Erro ao abrir o arquivo.\n");
        return; //verifica que a criação do arquivo teve sucesso
    }
    fprintf(arquivo,"ID,Nome,Operador,Sensor,Data,N,Media,Variancia,DesvioPadrao,Leituras->\n");
    for (int i =0; i<qtdEstacoes; i++){
        if(lista[i]!=NULL){
        fprintf(arquivo, "%d,%s,%s,%s,%d/%d/%d,%d,%.2f,%.2f,%.2f",lista[i]->id,lista[i]->nome,lista[i]->operador,lista[i]->sensor,lista[i]->data.dia,lista[i]->data.mes,lista[i]->data.ano,lista[i]->n,lista[i]->media,lista[i]->variancia,lista[i]->desvioPadrao);
        for (int j = 0; j<lista[i]->n;j++){
            fprintf(arquivo,",%.2f",lista[i]->leituras[j]);
        }
        fprintf(arquivo,"\n");
    }
}
    fclose(arquivo);
    printf("Dados salvos em um arquivo CSV. Procure por %s.csv\n",nomeArquivo);
}
void carregarCSV(Estacao **lista, int qtdEstacoes, const char *nomeArquivo);// carrega um arquivo cujo nome deve ser informado, extraindo as informações pra memória do programa
