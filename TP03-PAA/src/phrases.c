#include "../headers/phrase.h"

void initializePhrases(phrases *phrases, char line[1024])
{
    int totalWords = 0;

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == ' ')
        {
            totalWords++;
        }
    }

    totalWords++;

    phrases->words = (word *)malloc(sizeof(word) * totalWords);
    phrases->start = 0;
    phrases->final = 0;
    phrases->size = totalWords;

    char *wordAux;

    wordAux = strtok(line, " ");
    while (wordAux != NULL)
    {
        word *newWord = initializeWord(strlen(wordAux));

        insertLetter(newWord, wordAux);
        insertWord(phrases, *newWord);

        wordAux = strtok(NULL, " ");
    }
}

void printPhrases(phrases *phrases)
{
    int i;
    for (i = 0; i < phrases->size; i++)
    {
        printWord(&phrases->words[i]);
    }
}

int insertWord(phrases *phrases, word word)
{
    phrases->words[phrases->final] = word;
    phrases->final++;
}