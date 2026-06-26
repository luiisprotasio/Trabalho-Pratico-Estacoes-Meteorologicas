 #include "../packages/data.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

void salvarCSV(Estacao **lista, int qtdEstacoes, const char *nomeArquivo){
    char caminho[150];
    sprintf(caminho,"./data/%s.csv",nomeArquivo);
    FILE *arquivo = fopen(caminho,"w");
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
    printf("Dados salvos em um arquivo CSV. Procure por %s\n",nomeArquivo);
}
void carregarCSV(Estacao **lista, int qtdEstacoes, const char *nomeArquivo){
    char caminho[150];
    sprintf(caminho,"./data/%s.csv",nomeArquivo);
    FILE *arquivo= fopen(caminho,"r");
    if (arquivo==NULL){
        printf("ERRO: Cheque o nome do arquivo e tente novamente");
        return;
    }
    char temp[2000];
    if (fgets(temp, sizeof(temp), arquivo) == NULL) { //percorre a primeira linha, garantindo que o arquivo não está em branco e descartando o cabeçalho do csv
        fclose(arquivo);
        return;
    }while(fgets(temp,sizeof(temp),arquivo)!=NULL){
        int id;
        sscanf(temp,"%d",&id);
        if(id<0||id>9999){
            printf("ID inválido encontrado.\n");
            fclose(arquivo);
            return;
        }
        if (lista[id] != NULL) {
            if (lista[id]->leituras != NULL) {
            free(lista[id]->leituras);
            free(lista[id]);
        }
        }
        lista[id]=(Estacao *)calloc(1, sizeof(Estacao));
        if (lista[id] == NULL) {
            printf("ERRO: Falta de memória para abrir o arquivo\n");
            fclose(arquivo);
            return;
        }
        char *token = strtok(temp,",");
        lista[id]->id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(lista[id]->nome, token);
        token = strtok(NULL, ",");
        strcpy(lista[id]->operador, token);
        token = strtok(NULL, ",");
        strcpy(lista[id]->sensor, token);
        token = strtok(NULL,",");
        sscanf(token, "%d/%d/%d", &lista[id]->data.dia, &lista[id]->data.mes, &lista[id]->data.ano);
        token = strtok(NULL, ",");
        lista[id]->n = atoi(token);
        token = strtok(NULL, ",");
        lista[id]->media = atof(token);
        token = strtok(NULL, ",");
        lista[id]->variancia = atof(token);
        token = strtok(NULL, ",");
        lista[id]->desvioPadrao = atof(token);
        lista[id]->leituras=(float *)calloc(lista[id]->n,sizeof(float));
        if(lista[id]->leituras==NULL){
            printf("ERRO: Falta de memória para carregar as leituras.\n");
            return;
        }else {
            for(int i = 0; i < lista[id]->n;i++){
                token = strtok(NULL,",");
                lista[id]->leituras[i]=atof(token);
            }
        }
    }
printf("Dados carregados com sucesso!\n");
fclose(arquivo);
    

    

}