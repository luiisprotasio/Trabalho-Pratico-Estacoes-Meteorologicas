    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <ctype.h>
    #include "../packages/stats.h"
    #include "../packages/stations.h"
    #include "../packages/data.h"
    #include "../packages/functions.h"
int main() {
    Estacao lista[10];
    adicionarEstacao(&lista[1]);
    int media,maior,menor,v,dp;
    /*media = lista[1].media;
    maior=achaMaior(lista[1].leituras,lista[1].n);
    menor=achaMenor(lista[1].leituras,lista[1].n);
    dp=lista[1].desvioPadrao;
    v=lista[1].variancia;
    printf("%d %d %d %d %d",media,maior,menor,dp,v);*/
    salvarCSV(lista,1,"teste");
    return 0;
}