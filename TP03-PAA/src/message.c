#include "../headers/message.h"

void initializeMessage(message *message, char **text, int totalLines, int nonEmptyLines)
{
    int position = 0;
    message->size = nonEmptyLines;
    message->phrases = (phrases *)malloc(sizeof(phrases) * nonEmptyLines);

    for (int i = 0; i < totalLines; i++)
    {

        if (strlen(text[i]) != SIZE_EMPTY_LINE)
        {
            initializePhrases(&message->phrases[position], text[i]);
            position++;
        }
    }
}

int totalLetters(message *message)
{
    int total = 0;

    for (int i = 0; i < message->size; i++)
    {
        for (int ii = 0; ii < message->phrases[i].size; ii++)
        {
            for (int iii = 0; iii < message->phrases[i].words[ii].size; iii++)
            {
                if (message->phrases[i].words[ii].letters[iii].letter != '.' && message->phrases[i].words[ii].letters[iii].letter != ',')
                {
                    total++;
                }
            }
        }
    }

    return total;
}

void printMessage(message *message)
{
    for (int i = 0; i < message->size; i++)
    {
        printPhrases(&message->phrases[i]);
        printf("\n");
    }
}