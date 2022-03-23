#ifndef KEY_h
#define KEY_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char *letter;
} key;

/*
 * inicializa chave de criptografia
 */
key *initializeKey();

/*
 * preenche chave com letras vazias
 */
void insertKeyWithEmptySpace(key *prophecyKey);

/*
 * preenche chave com alfabeto
 */
void insertKeyWithAlphabet(key *prophecyKey);

/*
 * printa chave de criptografia
 */
void printKey(key *prophecyKey);

/*
 * muda a chave de criptografia
 */
void changeKey(key *prophecyKey);

/*
 * função para exportar a chave de criptografia
 */
void exportKey(key *prophecyKey, char *path);

/*
 * retorna o total de chaves que ainda não foram preenchidas
 */
int totalOfKeysNotFilled(key *prophecyKey);

/*
 * retorna a posição da letra na chave, com a ideia de 
 * poder fazer a transformação de qual seria na lingua portuguesa
 */
int positionOfLetterInKey(key *prophecyKey, char letter);

#endif