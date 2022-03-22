#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "disco.h"

//Função de comparação utilizada pelo qsort
int comp_suf_array(const void *pa, const void * pb);
int main(int argc, char** argv) {
    FILE* entrada;  //Arquivo de entrada para o sistema
    FILE* saida;    //Arquivo de saida para o sistema

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
    int qtd;  //quantidade de itens
    fscanf(entrada, "%d", &qtd);
    long int *dados = (long int*)malloc(sizeof(long int)*qtd);
    //Pega todos os dados do arquivo
    for(long int i = 0; i < qtd; i++)
        fscanf(entrada, "%ld", &dados[i]);
    ///////////////////////////////////////////
    fprintf(saida, "%7d", qtd);//printa no arquivo de saida a quantidade de dados
    
    //Calcula o tamanho em GB da base de dados
    long int size = 0;
    for(long int i = 0; i < qtd; i++)
        size +=dados[i];
    
    Lista *l,*l2,*l3,*l4;

    clock_t init = clock(); //Pega o tempo inicial da execução
        
    printf("\nTotal size(GB): %0.2lf\n", size/TAM_SIZE);
    printf("\nNumber of disks:\n");
    
    l = worstFit(l,dados, qtd);     //Heuristica Worst-fit
    l2 = bestFit(l2, dados, qtd);   //Heuristica Best-fit
    
    printf("Wors-fit: %d\n", l->tam);       //Imprime na saida padrão a quantidade de discos criados no Worst-fit
    printf("Best-fit: %d\n", l2->tam);      //Imprime na saida padrão a quantidade de discos criados no Best-fit
    fprintf(saida, "\t%d", l->tam);         //Imprime no arquivo de saida a quantidade de discos criados no Worst-fit
    fprintf(saida, "\t%d", l2->tam);        //Imprime no arquivo de saida a quantidade de discos criados no Best-fit
    
    //Ordena a base de dados
    qsort((void*)dados, qtd, sizeof(int*), comp_suf_array);
    
    l3 = worstFit(l3,dados, qtd);   //Heuristica Worst-fit decresing
    l4 = bestFit(l4, dados, qtd);   //Heuristica Best-fit decresing

    printf("Wors-fit decreasing: %d\n", l3->tam);       //Imprime na saida padrão a quantidade de discos criados no Worst-fit decresing
    printf("Best-fit decreasing: %d\n", l4->tam);       //Imprime na saida padrão a quantidade de discos criados no Best-fit decresing
    fprintf(saida, "\t%d", l3->tam);                    //Imprime no arquivo de saida a quantidade de discos criados no Worst-fit decresing
    fprintf(saida, "\t\t%d", l4->tam);                  //Imprime no arquivo de saida a quantidade de discos criados no Best-fit decresing
    
    clock_t fim = clock();  //Pega o tempo final da execução              
    double time = (double)(fim - init)/CLOCKS_PER_SEC; //Calcula o tempo total de execução

    printf("\ntempo: %lf\n", time);         //Imprime na saida padrão o tempo de execução das heuristicas
    fprintf(saida, "\t\t%lf\n", time);      //Imprime no arquivo de saida o tempo de execução das heuristicas
    
    //Libera a memoria
    excluiLista(l);
    excluiLista(l2);
    excluiLista(l3);
    excluiLista(l4);

    //Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    //Libera os dados de entrada
    free(dados);
    
    return (EXIT_SUCCESS);
}

int comp_suf_array(const void *pa, const void * pb){
    if((*(int*)pa) < (*(int*)pb)) return 1; //Compara dois elementos
    else return 0;
}