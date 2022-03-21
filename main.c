#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "disco.h"

int comp_suf_array(const void *pa, const void * pb);
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
    fprintf(saida, "\n%7d", qtd);
    
    long int size = 0;
    for(long int i = 0; i < qtd; i++)
        size +=dados[i];
    
    Lista *l,*l2,*l3,*l4;

    clock_t init = clock();
        
    printf("\nTotal size(GB): %0.2lf\n", size/TAM_SIZE);
    printf("\nNumber of disks:\n");
    
    l = worstFit(l,dados, qtd);
    l2 = bestFit(l2, dados, qtd);    
    
    printf("Wors-fit: %d\n", l->tam);    
    printf("Best-fit: %d\n", l2->tam);
    fprintf(saida, "\t%d", l->tam);
    fprintf(saida, "\t%d", l2->tam);
    
    qsort((void*)dados, qtd, sizeof(int*), comp_suf_array);
    
    l3 = worstFit(l3,dados, qtd);
    l4 = bestFit(l4, dados, qtd);    

    printf("Wors-fit decreasing: %d\n", l3->tam);
    printf("Best-fit decreasing: %d\n", l4->tam);
    fprintf(saida, "\t%d", l3->tam);
    fprintf(saida, "\t\t%d", l4->tam);
    
    clock_t fim = clock();                              
    double time = (double)(fim - init)/CLOCKS_PER_SEC;

    printf("\ntempo: %lf\n", time);
    fprintf(saida, "\t\t%lf", time);
    
    excluiLista(l);
    excluiLista(l2);
    excluiLista(l3);
    excluiLista(l4);

    fclose(entrada);
    free(dados);
    
    return (EXIT_SUCCESS);
}

int comp_suf_array(const void *pa, const void * pb){
    if((*(int*)pa) < (*(int*)pb)) return 1;
    else return 0;
}