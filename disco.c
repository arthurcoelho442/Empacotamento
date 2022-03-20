#include "disco.h"

typedef struct lista {
    disco *ini, *fim;
    int tam;
}Lista;

Lista* inicLista();
Lista* insereNaLista(Lista *l, disco *e);
Lista* ordenaLista(Lista* l);
disco* pegaIdeal(Lista* l, int dados);
void excluiLista(Lista *l);

int worstFit(long int* dados, int qtd){
    Lista* l = inicLista();
    
    for(int i=0; i<qtd; i++){
        if(l->tam == 0){
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
        }
        disco* aux = l->ini;
        if(aux->tam_rest >= dados[i]){
            aux->tam_rest -= dados[i];
        }else {
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
            l->ini->tam_rest -= dados[i];
        }
        l = ordenaLista(l);
    }
    int tam = l->tam;
    excluiLista(l);
    return tam;
}
int bestFit(long int* dados, int qtd){
    Lista* l = inicLista();
    
    for(int i=0; i<qtd; i++){
        if(l->tam == 0){
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
        }
        disco* ideal = pegaIdeal(l, dados[i]);
        if(ideal != NULL){
            ideal->tam_rest-=dados[i];
            if(ideal->tam_rest == 0){
                disco* ant = ideal->ant;
                disco* prox = ideal->prox;
                
                if(ant != NULL){
                    ant->prox = prox;
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
        }else {
                disco* d = criaDisco(qtd);
                d->tam_rest -= dados[i];
                l = insereNaLista(l, d);
        }
    }
    int tam = l->tam;
    excluiLista(l);
    return tam;
}

disco* criaDisco(int qtd){
    disco* d = (disco*) malloc(sizeof(disco));
    d->tam_rest = TAM_SIZE;
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
        if(atual->tam_rest == 0){
            l->ini = prox;
            free(atual);
            break;
        }else if(atual->tam_rest < prox->tam_rest){
           if(l->ini == atual)
               l->ini = prox;
           atual->prox = prox->prox;
           prox->prox = atual;
           
           atual->ant = prox;
           prox->ant = ant;
           
           if(ant != NULL)
               ant->prox = prox;
        }else
            break;
    }
    
    return l;
}
disco* pegaIdeal(Lista* l, int dado){
    int ideal = TAM_SIZE + 1;
    disco* dIdeal = NULL;
    for(disco* aux = l->ini; aux != NULL; aux = aux->prox)
        if(aux->tam_rest >= dado && aux->tam_rest < ideal){
            ideal = aux->tam_rest;
            dIdeal = aux;
        }
    return dIdeal;
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