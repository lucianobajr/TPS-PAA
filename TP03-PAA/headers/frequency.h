#ifndef FREQUENCY_h
#define FREQUENCY_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char *letter;
    float *value;
} frequency;

/*
 * inicializa a tabela de frequencia
 */
frequency *initializeFrequency();

/*
 * insere os valores da tabela de frequencia da lingua desejada
 */
void insertFrequencyValues(frequency *frequency);

/*
 * insere os valores ficticios a tabela de frequencia da profecia
 */
void insertDummyValuesFrequencyProphecy(frequency *prophecyLettersFrequency);

/*
 * inicializa tabela de frequencias da lingua desejada
 */
void printFrequency(frequency *frequency);

/*
 * printa a tabela de frequencia da profecia
 */
void printFrequencyProphecy(frequency *prophecyLettersFrequency, int totalLetterOfProphecy);

/*
 * ordena a tabela de frequencia
 */
void quickSort(frequency *frequency);

/*
 * função ordena do quicksort
 */
void order(int left, int right, frequency *frequency);

/*
 * função particiona do quicksort
 */
void partition(int left, int right, int *i, int *j, frequency *frequencyLetters);

/*
 * função que printa a análise de frequencia tanto da lingua portuguesa quanto da profecia
 */
void frequencyAnalysisPrint(frequency *prophecyLettersFrequency, frequency *languageLettersFrequency, int totalLetterOfProphecy);

#endif