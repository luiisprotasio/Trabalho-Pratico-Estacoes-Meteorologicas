    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "../packages/stats.h"
    #include "../packages/stations.h"
    #include "../packages/data.h"
int main() {
    // Vetor de testes com 5 leituras
    float dados[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    int n = 5;

    printf("=== TESTE DAS FUNÇÕES METEOROLÓGICAS ===\n\n");
    printf("Dados de teste: [10.0, 20.0, 30.0, 40.0, 50.0]\n\n");

    // 1. Teste da Média Iterativa
    float media = calcularMedia(dados, n);
    printf("Média (Iterativa):   %.2f  (Esperado: 30.00)\n", media);

    // 2. Teste da Média Recursiva (A sobrevivente da prova!)
    float mediaRec = calcularMediaRecursiva(dados, n);
    printf("Média (Recursiva):   %.2f  (Esperado: 30.00)\n", mediaRec);

    // 3. Teste de Maior e Menor
    float maior = achaMaior(dados, n);
    float menor = achaMenor(dados, n);
    printf("Maior Valor:         %.2f  (Esperado: 50.00)\n", maior);
    printf("Menor Valor:         %.2f  (Esperado: 10.00)\n", menor);

    // 4. Teste de Variância e Desvio Padrão
    float variancia = calcularVariancia(dados, n);
    float desvio = calcularDesvioPadrao(dados, n);
    printf("Variância:           %.2f (Esperado: 200.00)\n", variancia);
    printf("Desvio Padrão:       %.2f  (Esperado: 14.14)\n", desvio);

    printf("\n=========================================\n");

    return 0;
}