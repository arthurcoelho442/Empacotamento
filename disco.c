#include "disco.h"

typedef struct lista {
    disco *ini, *fim;
    int tam;
}Lista;

Lista* inicLista();
Lista* insereNaLista(Lista *l, disco *e);
Lista* ordenaLista(Lista* l);
void excluiLista(Lista *l);

int worstFit(long int* dados, int qtd){
    Lista* l = inicLista();
    
    for(int i=0; i<qtd; i++){
        if(l->tam == 0){
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
        }
        for(disco* aux = l->ini; aux != NULL; aux = aux->prox){
            if(aux->tam_rest >= dados[i]){
                aux = insereElement(aux, dados[i]);
                aux->tam_rest -= dados[i];
                break;
            }else if(aux->prox == NULL){
                disco* d = criaDisco(qtd);
                l = insereNaLista(l, d);
            }
        }
        l = ordenaLista(l);
        printf("\n\n%ld\n", dados[i]);
        for(disco* aux = l->ini; aux != NULL; aux = aux->prox){
            printf("[ ");
            for(int i=0; i<aux->qtd_elem; i++)
                printf("%d ", aux->elem[i]);
            printf("]\n");
        }
    }
    
    printf("\n############################\n");
    for(disco* aux = l->ini; aux != NULL; aux = aux->prox){
        printf("[ ");
        for(int i=0; i<aux->qtd_elem; i++)
            printf("%d ", aux->elem[i]);
        printf("]\n");
    }
    
    return l->tam;
}
int bestFit(long int* dados, int qtd){
    Lista* l = inicLista();
    
    for(int i=0; i<qtd; i++){
        if(l->tam == 0){
            disco* d = criaDisco(qtd);
            l = insereNaLista(l, d);
        }
        int id=0;
        for(disco* aux = l->ini; aux != NULL; aux = aux->prox){
            if(aux->tam_rest >= dados[i]){
                aux = insereElement(aux, dados[i]);
                aux->tam_rest -= dados[i];
                break;
            }else if(aux->prox == NULL){
                disco* d = criaDisco(qtd);
                l = insereNaLista(l, d);
            }
        }
    }
    
    
    for(disco* aux = l->ini; aux != NULL; aux = aux->prox){
        printf("[ ");
        for(int i=0; i<aux->qtd_elem; i++)
            printf("%d ", aux->elem[i]);
        printf("]\n");
    }
    
    return l->tam;
}

disco* criaDisco(int qtd){
    disco* d = (disco*) malloc(sizeof(disco));
    d->elem = (int*) malloc(sizeof(int)*qtd);
    d->qtd_elem = 0;
    d->tam_rest = 1000000;
    d->prox = NULL;
    return d;
}

disco* insereElement(disco* d, int dados){
    d->elem[d->qtd_elem] = dados;
    d->qtd_elem++;
    
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
    } else {//Entra se a lista já possui elementos e adiciona na ultima posição
        l->fim->prox = e;
        l->fim = e;
    }
    l->tam++;
    
    return l;
}

Lista* ordenaLista(Lista* l){
    disco* atual =  l->ini;
    disco* prox = atual->prox;
    disco* ant = NULL;
    
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
    
    return l;
}

//Libera o espaço da alocação dinamica 
void excluiLista(Lista *l) {
    //Anda pela fila leberando algoritmo por algoritmo
    for (disco *p = l->ini; p != NULL;){
        disco* t = p->prox;
        //libera(p);
        p = t;
    }
    free(l); //Libera a lista
}