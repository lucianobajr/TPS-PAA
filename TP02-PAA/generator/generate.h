#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3
#define LEVEL_4 4
#define LEVEL_5 5

/*
* cria um mapa vazio, com as dimenões desejadas, 
* sendo cada célula uma string de tamanho 3
*/
char ***createMap(int width, int height);

/*
* gera inteiros aleatórios a partir do nível 
*/
int genereteInt(int level);

/*
* preenche a matriz com o mapa
*/
void fillMap(char ***map, int width, int height,int level);

/*
* gera uma string aleatória ou ###
*/
char *generateString(int level);

/*
* converte valor aleatório gerado para string
*/
char *intToString(int value);

/*
* converte um inteiro para string
*/
char *convertIntToString(int value);

/*
* cria o arquivo com o mapa gerado
*/
void createFile(char ***map, int width, int height, int lavaTime, int samusTime,int level);