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

#define TAM_SIZE 1000000.0

struct disco{
    int tam_rest;
    struct disco *ant;
    struct disco *prox;
};

typedef struct disco disco;

struct lista {
    disco *ini, *fim;
    int tam;
}; 

typedef struct lista Lista;

Lista* worstFit(Lista* l, long int* dados, int qtd);
Lista* bestFit(Lista* l,long int* dados, int qtd);

disco* criaDisco(int qtd);
void excluiLista(Lista *l);

#endif /* DISCO_H */
