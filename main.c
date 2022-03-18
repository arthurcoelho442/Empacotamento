#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct lista {
    ordenacao *ini, *fim;
} Lista;

void insereNaLista(Lista *l, ordenacao *e);
void excluiLista(Lista *l);
int comp_suf_array(const void *pa, const void * pb);
int main(int argc, char** argv) {
    Lista *lista = (Lista*) malloc(sizeof (lista));         //Lista com todas as ordenações executadas
    FILE* entrada;                                          //Arquivo de entrada para o sistema
    FILE* saida;                                            //Arquivo de saida

    //Abre o arquivo de Entrada e o de Saida
    entrada = fopen(argv[3], "r+");
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

    qsort((void*)dados, qtd, sizeof(int*), comp_suf_array);

    fclose(entrada);
    fclose(saida);
    
    return (EXIT_SUCCESS);
}

//Insere os dados de uma ordenação na lista
void insereNaLista(Lista *l, ordenacao *e) {
    //Entra se a lista esta vazia e adiciona os dados
    if (l->ini == NULL) {
        l->ini = e;
        l->fim = e;
    } else {//Entra se a lista já possui elementos e adiciona na ultima posição
        l->fim->prox = e;
        l->fim = e;
    }
}

//Libera o espaço da alocação dinamica 
void excluiLista(Lista *l) {
    //Anda pela fila leberando algoritmo por algoritmo
    for (ordenacao *p = l->ini; p != NULL;){
        ordenacao* t = p->prox;
        libera(p);
        p = t;
    }
    
    free(l); //Libera a lista
}

int comp_suf_array(const void *pa, const void * pb){
    if((*(int*)pa) < (*(int*)pb)) return 1;
    else return 0;
}