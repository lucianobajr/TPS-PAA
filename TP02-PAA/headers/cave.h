#ifndef CAVE_h
#define CAVE_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/samus.h"

#define invalid -1
#define empty -2
#define TRUE 1
#define FALSE 0

typedef struct Cave
{
    int height, width, lavaTime;
    int **cave;
} Cave;

/*
 * inicializa a estrutura de dados
 */
void initializeCave(Cave *cave, int height, int width, int lavaTime);

/*
 * inicializa a estrutura de dados da tabela de soluções
 */
int **initilizeTable(int width, int height);

/*
 * inicializa a estrutura de dados da caminhos de soluções
 */
int *initilizePaths(int width);
/*
 * printa a caverna
 */
void printCave(Cave *cave);

/*
 * insere uma nova célula
 */
void insertNode(Cave *cave, int position, int j, char *line);

/*
 * limpa o mapa
 */
void cleanCave(Cave *cave);

/*
 * concatena os valores
 */
unsigned concatenate(char a, char b, char c);

#endif