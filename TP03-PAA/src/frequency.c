#include "../headers/frequency.h"

frequency *initializeFrequency()
{
    frequency *newfrequency = (frequency *)malloc(sizeof(frequency));

    if (newfrequency != NULL)
    {
        newfrequency->letter = (char *)malloc(sizeof(char) * 26);
        newfrequency->value = (float *)malloc(sizeof(float) * 26);
    }

    return newfrequency;
}

void insertFrequencyValues(frequency *frequency)
{

    FILE *fileFrequency;

    char letter;
    float value;

    const char *basePathFrequency = "./language/pt-BR.txt";

    fileFrequency = fopen(basePathFrequency, "r");

    if (!fileFrequency)
    {
        printf("Erro ao ler o arquivo!\n");
        printf("\n");
    }

    char line[10];

    int pos = 0;

    while (!feof(fileFrequency))
    {
        fscanf(fileFrequency, "%f %c", &value, &letter);

        frequency->letter[pos] = letter;
        frequency->value[pos] = value;

        pos++;
    }

    fclose(fileFrequency);
}

void insertDummyValuesFrequencyProphecy(frequency *prophecyLettersFrequency)
{
    for (int i = 0; i < 26; i++)
    {
        prophecyLettersFrequency->letter[i] = 65 + i;
        prophecyLettersFrequency->value[i] = 0.000;
    }
}

void printFrequency(frequency *frequency)
{
    printf("Letra,  Freq.\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c      %5.2f%% \n", frequency->letter[i], frequency->value[i]);
    }
}

void printFrequencyProphecy(frequency *prophecyLettersFrequency, int totalLetterOfProphecy)
{
    printf("Letra,   Cont.,    Freq.\n");
    int quantity;

    for (int i = 0; i < 26; i++)
    {
        quantity = ((prophecyLettersFrequency->value[i] * totalLetterOfProphecy) / 100);
        printf("%c        %5d    %5.2f%% \n", prophecyLettersFrequency->letter[i], quantity, prophecyLettersFrequency->value[i]);
    }
}

void quickSort(frequency *frequency)
{
    order(0, 25, frequency);
}

void order(int left, int right, frequency *frequency)
{
    int i, j;
    partition(left, right, &i, &j, frequency);

    if (left < j)
        order(left, j, frequency);
    if (i < right)
        order(i, right, frequency);
}

void partition(int left, int right, int *i, int *j, frequency *frequencyLetters)
{
    *i = left;
    *j = right;

    float pivot = frequencyLetters->value[(*i + *j) / 2];

    float aux;
    char auxChar;

    do
    {
        while (pivot < frequencyLetters->value[*i])
        {
            (*i)++;
        }
        while (pivot > frequencyLetters->value[*j])
        {
            (*j)--;
        }
        if (*i <= *j)
        {
            aux = frequencyLetters->value[*i];
            frequencyLetters->value[*i] = frequencyLetters->value[*j];
            frequencyLetters->value[*j] = aux;

            auxChar = frequencyLetters->letter[*i];
            frequencyLetters->letter[*i] = frequencyLetters->letter[*j];
            frequencyLetters->letter[*j] = auxChar;

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void frequencyAnalysisPrint(frequency *prophecyLettersFrequency, frequency *languageLettersFrequency, int totalLetterOfProphecy)
{
    printf("\n=== TABELA DE FREQUÊNCIA DA PROFECIA ===   === TABELA DE FREQUÊNCIA DA LINGUA PORTUGUESA ===\n");
    printf("Letra,   Cont.,    Freq.                   Letra,  Freq.\n");
    int quantity;

    for (int i = 0; i < 26; i++)
    {
        quantity = ((prophecyLettersFrequency->value[i] * totalLetterOfProphecy) / 100);
        printf("%c        %5d    %5.2f%%                   %c      %5.2f%% \n", prophecyLettersFrequency->letter[i], quantity, prophecyLettersFrequency->value[i], languageLettersFrequency->letter[i], languageLettersFrequency->value[i]);
    }
}