#include "../headers/word.h"

word *initializeWord(int sizeOfWord)
{
    word *newWord = (word *)malloc(sizeof(word));
    if (newWord != NULL)
    {
        newWord->size = sizeOfWord;
        newWord->start = 0;
        newWord->final = 0;
        newWord->letters = (typeLetter *)malloc(sizeof(typeLetter) * sizeOfWord);
    }

    return newWord;
}

void printWord(word *word)
{
    int i;
    for (i = word->start; i <= word->size + 1; i++)
    {
        printf("%c", word->letters[i].letter);
        if (i == word->size + 1)
        {
            printf(" ");
        }
    }
}

void insertLetter(word *word, char *letters)
{
    for (int i = 0; i < strlen(letters); i++)
    {
        word->letters[word->final].letter = letters[i];
        word->final++;
    }
}