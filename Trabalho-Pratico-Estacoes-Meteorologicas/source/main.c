    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "../packages/stats.h"
    #include "../packages/stations.h"
    #include "../packages/data.h"
int main() {
    Estacao *lista[10000]={NULL};
    // Alocando as estações dessa forma, teremos exatamente a quantia possíveis de estações que atendam ao requisito de ID, porém, sem estourar a memória de uma vez, pois alocar esta quantidade de estrutura gasta uma boa quantia de memória. Além disso, o id será o próprio índice do array, o que facilita o acesso.
    

    return 0;
}