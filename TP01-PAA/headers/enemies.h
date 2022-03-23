#ifndef ENEMIES_h
#define ENEMIES_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Atrributes
{
    int p, k;
    char *id;
} Atrributes;

typedef struct Enemie
{
    Atrributes atrributes;
} Enemie;

typedef struct Node *Pointer;

typedef struct Node
{
    Enemie enemie;
    Pointer next;
} Node;

typedef struct
{
    Pointer first, last;
} Enemies;

/*
 * faz uma lista vazia de inimigos
 */
void makeEmptyList(Enemies *enemies);

/*
 * verifica se a lista esta vazia
 */
int empty(Enemies enemies);

/*
 * cria um novo inimigo
 */
Enemie createEnemie(int p, int k, int position);

/*
 * insere um novo inimigo na lista de inimigos
 */
void insert(Enemie enemie, Enemies *enemies);

/*
 * remove um inimigo na lista de inimigos
 */
void removeEnemie(Enemies *enemies);

/*
 * remove os inimigos da lista
 */
void removeEnemies(Enemies *enemies);

/*
 * printa a lista de inimigos
 */
void printEnemies(Enemies *enemies);

/*
 * gera o ID para o inimigo pela posição da entrada (arquivo)
 */
char *enemieId(int position);

/*
 * encontra um inimigo pelo ID
 */
Enemie *findEnemie(Enemies *enemies, char id);

/*
 * retorna o poder de giygas
 */
int giygasPower(Enemies *enemies);

#endif