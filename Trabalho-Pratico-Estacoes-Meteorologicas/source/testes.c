    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "../packages/stats.h"
    #include "../packages/stations.h"
    #include "../packages/data.h"
    #include "../packages/functions.h"
int main() {
    Estacao *lista[10000]={NULL};
    int q1,q2,q3,q4,q5,q6,q7,q8=0; char temp; //variáveis auxiliares para seleções no menu
    // Alocando as estações dessa forma, teremos exatamente a quantia possíveis de estações que atendam ao requisito de ID, porém, sem estourar a memória de uma vez, pois alocar esta quantidade de estrutura gasta uma boa quantia de memória. Além disso, o id será o próprio índice do array, o que facilita o acesso.
    while(1){//LOOP PRINCIPAL, ONDE O PROGRAMA EXECUTA 
        printf("=============|Painel de controle - Estações Meteorológicas|=============\nSelecione a opção desejada:\n1-Controle de estações.\n2-Exportar/Importar dados.\n3-Estatísticas.\n4-Visualizar.\n5-Encerrar.\n==============================================================================\n");
       while(scanf("%d%c",&q1,&temp)!=2||q1>5||q1<1){
    printf("Opção inválida.\n");  
    clean();
}clear(); 
while(q1==1){
    printf("=============|Controle de estações - Estações Meteorológicas|=============\nSelecione a opção desejada:\n1-Adicionar nova estação.\n2-Editar estação.\n3-Excluir estação.\n4-Voltar.\n==============================================================================\n");
     while(scanf("%d%c",&q2,&temp)!=2||q2>4||q2<1){
    printf("Opção inválida.\n");  
    clean();}clear(); 
    while(q2==1){
        adicionarEstacao(lista);
        printf("Estação adicionada e configurada com sucesso.\nRetornando.\n");
        break;
    } 
    while(q2==2){
        int ide;
        printf("=============|Edição de Estações - Estações Meteorológicas|=============\nSelecione a opção desejada:\n1-Mudar nome.\n2-Mudar operador.\n3-Mudar sensor.\n4-Mudar data.\n5-Voltar.\n==============================================================================\n");
         while(scanf("%d%c",&q3,&temp)!=2||q3>5||q3<1){
    printf("Opção inválida.\n");  
    clean();}clear();
    if(q3<5){
    printf("Qual o id da estação a ser editada?\n");
    while(scanf("%d%c",&ide,&temp)!=2||ide>9999||ide<0){
    printf("ID inválida.\n");  
    clean();}clear();
    editarEstacao(lista[ide],q3);
    } else {break;}
}while (q2==3){
     int ide;
        printf("=============|Exclusão de Estações - Estações Meteorológicas|=============\nSelecione a opção desejada:\n1-Excluir estação.\n2-Voltar\n==============================================================================\n");
         while(scanf("%d%c",&q3,&temp)!=2||q3>2||q3<1){
    printf("Opção inválida.\n");  
    clean();}clear();
    while (q3==1){
        printf("Qual o id da estação a ser editada?\n");
    while(scanf("%d%c",&ide,&temp)!=2||ide>9999||ide<0){
    printf("ID inválida.\n");  
    clean();}clear();
    if(lista[ide]!=NULL){
        removerEstacao(lista,ide);
    } else {printf("Estação não existente.\n");}
    }while(q3==2){
        clear();
        break;
    }
}while(q2==4){
    clear();
    break;
}

}while(q1==2){printf("=============|Exportar/Importar dados - Estações Meteorológicas|=============\nSelecione a opção desejada:\n1-Exportar Dados.\n2-Voltar.\n==============================================================================\n"); while(scanf("%d%c",&q3,&temp)!=2||q3>2|q1<3){
    printf("Opção inválida.\n");  
    clean();}clear();

}


while(q1==3){printf("=============|Estatísticas - Estações Meteorológicas|=============\nSelecione a opção desejada:\n1-Imprimir estatísicas.\n2-Voltar.\n==============================================================================\n"); while(scanf("%d%c",&q3,&temp)!=2||q3>2|q1<3){
    printf("Opção inválida.\n");  
    clean();}clear();
    if(q3==1){
        int ide;
        printf("Insira o ID da estação desejada.\n");
        while(scanf("%d%c",&ide,&temp)!=2||ide>9999||ide<0){
    printf("ID inválida.\n");  
    clean();}clear();
    if (lista[ide]!=NULL){
    Estacao *atual=lista[ide];
    printf("Número de leituras:%d\nMédia:%.5f\nVariância:%.5f\nDesvio Padrão:%.5f\nMaior leitura:%.5f\nMenor leitura:%.5f\n",atual->n,atual->media,atual->variancia,atual->desvioPadrao,achaMaior(atual->leituras,atual->n),achaMenor(atual->leituras,atual->n));
    } else {printf("Não existe uma estação com esse ID.\n");
    }
    }

}while(q1==5){
    return 0;
}
    
    }
    return 0;
}