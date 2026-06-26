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
    Estacao *lista[10000]={NULL};
    adicionarEstacao(lista);
    salvarCSV(lista,10000,"teste.csv");
    return 0;
}