/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   disco.h
 * Author: arthur
 *
 * Created on 18 de Março de 2022, 14:59
 */

#ifndef DISCO_H
#define DISCO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho do disco de dados
#define TAM_SIZE 1000000.0

//Struct disco
struct disco{
    int tam_rest;       //Tamanho restante do disco
    struct disco *ant;  //Ponteiro para o disco anterior
    struct disco *prox; //Ponteiro para o proximo disco
};

typedef struct disco disco; 

//Struct para criação da lista de discos
struct lista {
    disco *ini, *fim;
    int tam;
}; 

typedef struct lista Lista;

//Heuristica Wors-Fit
Lista* worstFit(Lista* l, long int* dados, int qtd);
//Heuristica Best-Fit
Lista* bestFit(Lista* l,long int* dados, int qtd);

//Cria um disco inicialmente vario
disco* criaDisco();

//Exclui toda a lista de disco e libera a memoria alocada pelos mesmos
void excluiLista(Lista *l);

#endif /* DISCO_H */

