#ifndef MESSAGE_h
#define MESSAGE_h

#include "../headers/phrase.h"

#define SIZE_EMPTY_LINE 1

typedef struct
{
    int size;
    phrases *phrases;
} message;

/*
 * inicializa frases
 */
void initializeMessage(message *message, char **text, int totalLines, int nonEmptyLines);

/*
 * insere uma frase
 */
int insertPhrase(message *message, phrases phrases);

/*
 * printa frases
 */
void printMessage(message *message);

/*
 * retorna o total de letras da mensagem
 */
int totalLetters(message *message);

#endif