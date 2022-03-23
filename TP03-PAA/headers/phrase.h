#ifndef PHRASES_h
#define PHRASES_h

#define MAX_PHRASES 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/word.h"

typedef struct
{
    int size;
    int start, final;
    word *words;
} phrases;

/*
 * inicializa frases
 */
void initializePhrases(phrases *phrases,char line[1024]);

/*
 * insere uma palavra
 */
int insertWord(phrases *phrases, word word);

/*
 * printa frases
 */
void printPhrases(phrases *phrases);

#endif