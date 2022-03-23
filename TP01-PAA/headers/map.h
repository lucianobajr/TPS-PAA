#ifndef MAP_h
#define MAP_h

#include <stdio.h>
#include <stdlib.h>

#include "../headers/ness.h"
#include "../headers/enemies.h"
#include "../headers/moviments.h"

#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7
#define TRUE 1
#define FALSE 0

typedef struct Map
{
    int width, height;
    char **map;
} Map;

typedef struct Data
{
    int number_of_recursions;
} Data;


/*
 * inicializa a estrutura de dados
 */
void initializeData(Data *data);

/*
 * inicializa a estrutura
 */
void initialize(Map *map, int width, int height);

/*
 * printa o mapa
 */
void print(Map *map);

/*
 * insere uma nova linha do mapa
 */
void insertLine(Map *map, int position, char *line);

/*
 * insere as coordenadas iniciais de Ness
 */
void startCoordinates(Map *map, Ness *ness);

/*
 * insere as coordenadas de Giygas
 */
void endCoordinates(Map *map, int *coordinates);

/*
 * backtracking
 */
int move(Map *map, Ness *ness, Enemies *enemies, Queue *moviments, int *direction, int line, int column, int *goBack, int *opcao1,Data *data);

/*
 * batalha com inimigo
 */
int battle(Ness *ness, Enemie *enemie);

/*
 * verifica se uma posição do mapa é possível de ir
 * não ultrapassa os limites do mapa e não é um ponto
 */
int isSafe(Map *map, int x, int y);

/*
 * verifica se é um inimigo
 */
int isEnemy(Map *map, int x, int y);

/*
 * verifica se é o Giygas
 */
int isGiygas(Map *map, int x, int y);

/*
 * verifica se um cruzamento
 */
int isIntersection(Map *map, Ness *ness, Enemies *enemies, Queue *moviments, int x, int y);

/*
 * verifica se um inimigo já foi derrotado
 */
int isAnEnemyAlreadyDefeated(Map *map, Queue *moviments, int x, int y);

/*
 * movimenta no mapa
 */
int goMove(Map *map, int direction, int x, int y);

/*
 * limpa o mapa
 */
void cleanMap(Map *map);

/*
 * printa o mapa
 */
void printMap(Map *map);
#endif