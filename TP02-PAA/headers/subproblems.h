#ifndef SUBPROBLEMS_h
#define SUBPROBLEMS_h

#include <stdio.h>
#include <stdlib.h>

#include "../headers/cave.h"

typedef struct Subproblem
{
    int line, column, prevLine, prevColumn, value;
} Subproblem;

typedef struct SubproblemsTable
{
    Subproblem **table;
    int width, height;
} SubproblemsTable;

/*
 * inicializa a estrutura de dados
 */
void initializeSubproblemsTable(SubproblemsTable *subproblemsTable, int width, int height);

/*
 * printa valores da tabela
 */
void printSubproblemsTable(SubproblemsTable *subproblemsTable);

/*
 * retorna o menor caminho possível
 */
Subproblem lessInitialValue(Subproblem *lines, int height);

/*
 * samus caminha no menor caminho
 */
void move(Cave *cave, SubproblemsTable *subproblemsTable,Samus *samus,int *win);

/*
 * encontra os caminhos (programação dinâmica)
 */
void solver(Cave *cave, SubproblemsTable *subproblemsTable);

/*
 * retorna o tempo total para o menor caminho
 */
int totalTime(Cave *cave, SubproblemsTable *subproblemsTable, Samus *samus);

/*
 * printa passo do melhor caminho
 */
void printPath(Cave *cave, SubproblemsTable *subproblemsTable);

#endif