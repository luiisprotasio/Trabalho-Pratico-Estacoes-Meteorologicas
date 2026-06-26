#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../packages/stats.h"

float calcularMediaRecursiva(float *leituras, int n){
    if(n==1){
        return leituras[0];
    }else {
        return (leituras[n-1]+calcularMediaRecursiva(leituras,n-1)*(n-1))/n;
    }


}
float calcularMedia(float *leituras,int n){
    float soma = 0;
    for (int i = 0; i< n; i++){
        soma+= leituras[i];
    }
    return soma/n;
}
float achaMaior(float *leituras, int n){
    float temp = leituras[0];
    for (int i = 0; i<n;i++){
        if (leituras[i]>temp){
            temp = leituras[i];
        }
    }
    return temp;
}
float achaMenor(float *leituras, int n){
    float temp = leituras[0];
    for (int i = 0; i<n;i++){
        if (leituras[i]<temp){
            temp = leituras[i];
        }
    }
    return temp;
}
float calcularVariancia(float *leituras, int n){
   float media = calcularMedia(leituras,n);
   float soma = 0;
   for (int i = 0; i<n; i++){
    soma +=pow((leituras[i]-media),2);
   } 
   return soma/n;
}
float calcularDesvioPadrao(float *leituras, int n){
    float variancia = calcularVariancia(leituras,n);
    return sqrt(variancia);
}