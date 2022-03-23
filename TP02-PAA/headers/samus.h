#ifndef SAMUS_h
#define SAMUS_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Samus
{
    int time;
} Samus;

/*
 * inicializa a estrutura de dados
 */
void initializeSamus(Samus *samus, int time);

/*
 * printa a Samus
 */
void printSamus(Samus *samus);

/*
 * limpa Samus
 */
void cleanSamus(Samus *samus);

#endif