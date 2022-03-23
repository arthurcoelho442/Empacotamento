#include "disco.h"


Lista* inicLista();                         //Inicia a lista de disco
Lista* insereNaLista(Lista *l, disco *e);   //Insere disco na lista de discos
Lista* ordenaLista(Lista* l);               //Organiza a lista de disco de foram decresente
disco* pegaIdeal(Lista* l, int dados);      //Pega o Menor disco que caiba o arquivo

Lista* worstFit(Lista* l, long int* dados, int qtd){

    l = inicLista(); //Inicia a lista
    
    //Pecorre a lista de arquivos
    for(int i=0; i<qtd; i++){
        //Entra no if caso a lista esteja vazia
        if(l->tam == 0){
            disco* d = criaDisco(qtd);  //Cria o disco
            l = insereNaLista(l, d);    //Insere o disco na lista
        }
        disco* aux = l->ini;
        //Verifica se o arquivo cabe no disco com maior espaço restante
        if(aux->tam_rest >= dados[i]){
            aux->tam_rest -= dados[i]; //incrementa o tamanho do arquivo no disco
        }else { //Cria o disco e insere na lista e incrementa o tamanho do arquivo no disco
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
            l->ini->tam_rest -= dados[i];
        }
        l = ordenaLista(l);
    }
    return l;//Retorna a lista de discos
}
Lista* bestFit(Lista* l, long int* dados, int qtd){

    l = inicLista(); //Inicia a lista
    
    //Percore a lista de arquivos
    for(int i=0; i<qtd; i++){
        //Entra no if caso a lista esteja vazia
        if(l->ini == NULL){
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
        }
        disco* ideal = pegaIdeal(l, dados[i]); //Pega o disco ideal para se armazenar o arquivo
        if(ideal != NULL){//Entra caso haja disco ideal
            ideal->tam_rest-=dados[i];  //Coloca o arquivo no disco
            if(ideal->tam_rest == 0){   //Verifica se o disco esta vazio e o remove
                disco* ant = ideal->ant;
                disco* prox = ideal->prox;
                
                if(ant != NULL){
                    ant->prox = prox;
                    if(prox != NULL)
                        prox->ant = ant;
                }else if (prox != NULL){
                    l->ini = prox;
                    prox->ant = NULL;
                }else{
                    l->ini = NULL;
                    l->fim = NULL;
                }
                free(ideal);
            }
        }else {                         //Entra caso não caiba o disco e cria um novo disco
                disco* d = criaDisco(qtd);
                d->tam_rest -= dados[i];
                l = insereNaLista(l, d);
        }
    }
    return l;//Retorna a lista de discos
}

disco* criaDisco(){
    disco* d = (disco*) malloc(sizeof(disco));  //Aloca o disco dinamicamente
    d->tam_rest = TAM_SIZE;                     //Inicia o disco com o tamanho de 1G
    d->ant = NULL;                              
    d->prox = NULL;
    return d;
}

/*///////////////   LISTA   ///////////////*/
Lista* inicLista(){
    Lista *l = (Lista*) malloc(sizeof (Lista));         //Lista com todos os discos
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
    
    return l;
}


//Insere os dados de uma ordenação na lista
Lista* insereNaLista(Lista *l, disco *e) {
    //Entra se a lista esta vazia e adiciona os dados
    if (l->ini == NULL) {
        l->ini = e;
        l->fim = e;
    }
     else {//Entra se a lista já possui elementos e adiciona na ultima posição
        l->ini->ant = e;
        e->prox = l->ini;
        l->ini = e;
    }
    l->tam++;
    
    return l;
}

Lista* ordenaLista(Lista* l){
    disco* atual =  l->ini;
    disco* prox = atual->prox;
    disco* ant = NULL;
    
    //Ordenação Decresente
    for(; prox!=NULL; ant = prox, prox = atual->prox){
        if(atual->tam_rest == 0){   //Verifica se o disco esta vazio 
            if (prox != NULL){      //Entra caso hajá mais discos
                l->ini = prox;
                prox->ant = NULL;
            }else{                  //Entra se ele é o ultimo disco da lista
                l->ini = NULL;
                l->fim = NULL;
            }
            free(atual);
            break;                  
        }else if(atual->tam_rest < prox->tam_rest){ //Entra caso o proximo disco seja maior e troca os discos
           if(l->ini == atual)
               l->ini = prox;
           atual->prox = prox->prox;
           prox->prox = atual;
           
           atual->ant = prox;
           prox->ant = ant;
           
           if(ant != NULL)
               ant->prox = prox;
        }else //Lista esta ordenada sai do loop
           break;
    }
    
    return l; //Retorna a lista de discos
}
disco* pegaIdeal(Lista* l, int dado){
    int ideal = TAM_SIZE + 1; //inicia o tamanho ideal como sendo 1G + 1
    disco* dIdeal = NULL;
    //Percorre a lista de discos
    for(disco* aux = l->ini; aux != NULL; aux = aux->prox)
        if(aux->tam_rest >= dado && aux->tam_rest < ideal){// Entra caso o tamanho do disco caiba o dado e se ele for menor que o tamanho encontrado até o momento
            ideal = aux->tam_rest;
            dIdeal = aux;
        }
    return dIdeal; //Retorna o tamanho do disco
}

//Libera o espaço da alocação dinamica 
void excluiLista(Lista *l) {
    //Anda pela fila leberando algoritmo por algoritmo
    for (disco *p = l->ini; p != NULL;){
        disco* t = p->prox;
        free(p);
        p = t;
    }
    free(l); //Libera a lista
}