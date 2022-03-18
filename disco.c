#include "disco.h"

typedef struct lista {
    disco *ini, *fim;
    int tam;
}Lista;

Lista* inicLista();
Lista* insereNaLista(Lista *l, disco *e);
Lista* ordenaLista(Lista* l, int tipo);
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
        l = ordenaLista(l, 1);
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
        for(disco* aux = l->ini; aux != NULL; aux=aux->prox){
            if(aux->tam_rest >= dados[i]){
                aux->tam_rest -= dados[i];
                break;
            }else if(aux->prox == NULL){
                disco* d = criaDisco(qtd);
                l = insereNaLista(l, d);
                aux = l->ini;
                aux->tam_rest -= dados[i];
                break;
            }
        }
        l = ordenaLista(l, 2);
    }
        
    int tam = l->tam;
    excluiLista(l);
    return tam;
}

disco* criaDisco(int qtd){
    disco* d = (disco*) malloc(sizeof(disco));
    d->tam_rest = 1000000;
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
        e->prox = l->ini;
        l->ini = e;
    }
    l->tam++;
    
    return l;
}

Lista* ordenaLista(Lista* l, int tipo){
    disco* atual =  l->ini;
    disco* prox = atual->prox;
    disco* ant = NULL;
    
    //Ordenação Decresente
    if(tipo == 1){
        for(int i=0; prox!=NULL; i++, ant = atual, atual = prox, prox = prox->prox){
           if(atual->tam_rest < prox->tam_rest){
               if(l->ini == atual)
                   l->ini = prox;
               disco* aux = atual;
               atual->prox = prox->prox;
               prox->prox = aux;
               if(ant != NULL)
                   ant->prox = prox;
           }
        }
    }
    //Ordenação Cresente
    if(tipo == 2){
        for(int i=0; prox!=NULL; i++, ant = atual, atual = prox, prox = prox->prox){
           if(atual->tam_rest > prox->tam_rest){
               if(l->ini == atual)
                   l->ini = prox;
               disco* aux = atual;
               atual->prox = prox->prox;
               prox->prox = aux;
               if(ant != NULL)
                   ant->prox = prox;
           }
        }
    }
    
    return l;
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