#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../packages/functions.h"

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
    for(int i=0;i<strlen(temp)-1;i++){
        if(!isalpha(temp[i])){
            return 1;
        }
    }
    return 0;

}