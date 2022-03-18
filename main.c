#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "disco.h"

int comp_suf_array(const void *pa, const void * pb);
int main(int argc, char** argv) {
    FILE* entrada;                                          //Arquivo de entrada para o sistema
    FILE* saida;                                            //Arquivo de saida

    //Abre o arquivo de Entrada e o de Saida
    entrada = fopen(argv[1], "r+");
    saida = fopen("saida.txt", "a+");

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
    long int **dadosAux = (long int**)malloc(sizeof(long int*)*5);
    for(int i=0;i<5;i++)
        dadosAux[i]=(long int*)malloc(sizeof(long int)*qtd);
    //todos os dados do arquivo
    for(long int i = 0; i < qtd; i++)
        fscanf(entrada, "%ld", &dados[i]);
    ///////////////////////////////////////////

    //qsort((void*)dados, qtd, sizeof(int*), comp_suf_array);
    
    //for(long int i = 0; i < qtd; i++)
    //    printf("%ld\n", dados[i]);
    
    int h = worstFit(dados, qtd);

    printf("\n%d\n", h);
    
    fclose(entrada);
    fclose(saida);
    
    return (EXIT_SUCCESS);
}

int comp_suf_array(const void *pa, const void * pb){
    if((*(int*)pa) < (*(int*)pb)) return 1;
    else return 0;
}