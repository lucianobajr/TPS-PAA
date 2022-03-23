#ifndef WORD_h
#define WORD_h

#define MAX 30

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char letter;
} typeLetter;

typedef struct
{
    int size;
    int start, final;
    typeLetter *letters;
} word;

/*
 * inicializa palavra
 */
word *initializeWord(int sizeOfWord);

/*
 * imprimi palavra
 */
void printWord(word *word);

/*
 * insere uma letra
 */
void insertLetter(word *word, char *letters);

#endif