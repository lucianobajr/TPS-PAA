#ifndef NESS_h
#define NESS_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Ness
{
    int p, k,line,column;
} Ness;

/*
 * inicializa o Ness
 */
void initializeNess(Ness *ness, int p, int k);

/*
 * verifica se um inimigo já foi derrotado
 */
void printNess(Ness *ness);

/*
 * modifica as coordenadas inicais de Ness
 */
void changeNessCoordinates(Ness *ness, int x, int y);

/*
 * limpa os valores de ness
 */
void cleanNess(Ness *ness);

#endif