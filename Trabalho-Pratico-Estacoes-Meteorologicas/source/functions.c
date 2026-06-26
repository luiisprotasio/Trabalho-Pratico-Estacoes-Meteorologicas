#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../packages/functions.h"
#include "../packages/stations.h"

int verificaCorteEntrada(char *str){
    if(str==NULL){
        return 1; //fgets encontrou erro
    }
    else if(strlen(str)>0 && str[strlen(str)-1]!='\n'){
        return 1; //entrada foi cortada
    }
    else {
        return 0;
    }
}
int verificaAlfa(char *str){
    char temp[60];
    strcpy(temp,str);
    temp[strlen(temp)-1]='\0';
    if(strlen(temp)==1){
        if(!isalpha(temp[0])){
            return 1;
        }
    }
    for(int i=0;i<strlen(temp)-1;i++){
        if(!isalpha(temp[i])){
            return 1;
        }
    }
    return 0;

}
int verificaData(DataLeitura data){
    if(data.ano>2200||data.ano<=0){
        return 1; //verifica se é um ano válido
    }
    if(data.mes<1||data.mes>12){
        return 1; // verifica se é um mês válido
    }
    if(data.dia<1||data.dia>31){
        return 1; // verifica se é um dia válido num geral
    }
    if(data.ano%4!=0&&data.mes==2&&data.dia>28){
        return 1; //verifica que fevereiro tem 28 dias em anos comuns
    }
    if(data.ano%4==0&&data.mes==2&&data.dia>29){
        return 1; //permite que fevereiro tenha 29 dias em anos bissextos
    }
    if((data.mes==4||data.mes==6||data.mes==9||data.mes==11)&&data.dia>30){
        return 1; //verifica que meses de 30 dias tenham no máximo 30 dias
    }
    return 0;
}