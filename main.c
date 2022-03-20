#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "disco.h"

int comp_suf_array(const void *pa, const void * pb);
int main(int argc, char** argv) {
    FILE* entrada;                                          //Arquivo de entrada para o sistema

    //Abre o arquivo de Entrada
    entrada = fopen(argv[1], "r+");

    //Verifica se o arquivo de Entrada é existente
    if (entrada == NULL) {
        printf("\n\tErro Arquivo de entrada não encontrado\n\n");
        return 0;
    }
    ///////////////////////////////////////

    //Tratamento do dados do arquivo //////////
    int qtd, k=0;                                                //quantidade de itens
    fscanf(entrada, "%d", &qtd);
    long int *dados = (long int*)malloc(sizeof(long int)*qtd);
    //todos os dados do arquivo
    for(long int i = 0; i < qtd; i++)
        fscanf(entrada, "%ld", &dados[i]);
    ///////////////////////////////////////////

    
    long int size = 0;
    for(long int i = 0; i < qtd; i++)
        size +=dados[i];
    
    clock_t init = clock();
        
    printf("\nTotal size(GB): %0.2lf\n", size/TAM_SIZE);
    printf("\nNumber of disks:\n");
    
    //int wF = worstFit(dados, qtd);
    int bF = bestFit(dados, qtd);    
    
    //printf("Wors-fit: %d\n", wF);    
    printf("Best-fit: %d\n", bF);
    
    //qsort((void*)dados, qtd, sizeof(int*), comp_suf_array);
    
    //wF = worstFit(dados, qtd);
    //bF = bestFit(dados, qtd); 

    //printf("Wors-fit decreasing: %d\n", wF);
    //printf("Best-fit decreasing: %d\n", bF);
    
    clock_t fim = clock();                              
    double time = (double)(fim - init)/CLOCKS_PER_SEC;

    printf("\ntempo: %lf\n", time);
    
    fclose(entrada);
    free(dados);
    
    return (EXIT_SUCCESS);
}

int comp_suf_array(const void *pa, const void * pb){
    if((*(int*)pa) < (*(int*)pb)) return 1;
    else return 0;
}