#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../disco.h"

int main(int argc, char** argv) {
    FILE* entrada;                                          //Arquivo de entrada para o sistema
    FILE* saida;                                          //Arquivo de saida para o sistema

    //Abre o arquivo de Entrada
    entrada = fopen(argv[1], "r");
    saida = fopen("ED2_Trab3_results.txt", "a");

    //Verifica se o arquivo de Entrada é existente
    if (entrada == NULL) {
        printf("\n\tErro Arquivo de entrada não encontrado\n\n");
        return 0;
    }
    ///////////////////////////////////////
    
    //Tratamento do dados do arquivo //////////
    int qtd;                                                //quantidade de itens
    fscanf(entrada, "%d", &qtd);
    long int *dados = (long int*)malloc(sizeof(long int)*qtd);
    //todos os dados do arquivo
    for(long int i = 0; i < qtd; i++)
        fscanf(entrada, "%ld", &dados[i]);
    ///////////////////////////////////////////
    fprintf(saida, "%7d", qtd);
    
    /*long int size = 0;
    for(long int i = 0; i < qtd; i++)
        size +=dados[i];
    
    Lista *l1;

    clock_t init = clock();
        
    printf("\nTotal size(GB): %0.2lf\n", size/TAM_SIZE);
    printf("\nNumber of disks:\n");
    
    l1 = bestFit(l1, dados, qtd);    
     
    printf("Best-fit: %d\n", l1->tam);
    fprintf(saida, "\t\t%d", l1->tam);
    
    clock_t fim = clock();                              
    double time = (double)(fim - init)/CLOCKS_PER_SEC;

    printf("\ntempo: %lf\n", time);
    fprintf(saida, "\t\t\t\t\t%lf\n", time);
    
    excluiLista(l1);*/
    fprintf(saida, "\n");
    
    free(dados);
    fclose(saida);    
    fclose(entrada);
    return (EXIT_SUCCESS);
}
