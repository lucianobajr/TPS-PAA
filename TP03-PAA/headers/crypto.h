#ifndef CRYPTO_h
#define CRYPTO_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./message.h"
#include "./frequency.h"
#include "./key.h"

/*
 * operações pré criptoanalise
 */
void preCrypto(frequency *prophecyLettersFrequency, frequency *languageLettersFrequency);

/*
 * criptoanalise
 */
void crypto(message *prophecy, frequency *prophecyLettersFrequency, frequency *languageLettersFrequency, key *alphabetKey, key *prophecyKey);

/*
 * análise de frequencia das letras da profecia
 */
void frequencyAnalysis(message *prophecy, frequency *prophecyLettersFrequency);

/*
 * descriptografa a profecia
 */
void decrypt(message *prophecy,  key *prophecyKey);

/*
 * retorna o total de letras da mensagem
 */
void exportProfecy(message *prophecy, key *prophecyKey, char *path);

/*
 * exporta os resultados (chave e texto descriptografado)
 */
void exportResults(message *prophecy, key *prophecyKey);

/*
 * printa cada letra com uma cor diferente
 */
void printLetterWithColor(char letter);

/*
 * reseta as cores
 */
void reset();

#endif