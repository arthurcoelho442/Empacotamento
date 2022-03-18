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

struct disco{
    int* elem;
    int qtd_elem;
    int tam_rest;
    struct disco *prox;
};

typedef struct disco disco;

int worstFit(long int* dados, int qtd);
int bestFit(long int* dados, int qtd);

disco* criaDisco(int qtd);
disco* insereElement(disco* d, int dados);

#endif /* DISCO_H */

