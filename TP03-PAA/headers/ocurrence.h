#ifndef OCURRENCE_h
#define OCURRENCE_h

#include "../headers/word.h"
#include "../headers/phrase.h"
#include "../headers/message.h"
#include "../headers/key.h"

/*
 * Shift and aproximado
 */
void ShiftAndAproximado(char *text, long n, char *standard, long m, long k);

/*
 * converte o texto em uma string pra facilitar na busca
 */
char *preSearch(message *prophecy, int *size);

/*
 * converte o texto descriptografrado em uma string pra facilitar na busca
 */
char *preSearchDecrypted(message *prophecy, key *prophecyKey, int *size);

/*
 * função auxiliar retorna o maior entre dois interios
 */
int max(int a, int b);

/*
 * A função de pré-processamento para a heurística
 */
void badCharHeuristic(char *str, int size, int badchar[256]);

/*
 * Faz busca no texto criptografado com algoritmo Boyer Moore
 */
void search(char *txt, char *pat);

/*
 * Realizar casamento exato de caracteres no texto criptografado
 */
void exactMatch(message *prophecy);

/*
 * Realizar casamento aproximado de caracteres no texto parcialmente decifrado
 */
void approximateMatch(message *prophecy, key *prophecyKey);

#endif