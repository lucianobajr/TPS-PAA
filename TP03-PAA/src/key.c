#include "../headers/key.h"

key *initializeKey()
{
    key *prophecyKey = (key *)malloc(sizeof(key));

    if (prophecyKey != NULL)
    {
        prophecyKey->letter = (char *)malloc(sizeof(char) * 26);
    }

    return prophecyKey;
}

void insertKeyWithEmptySpace(key *prophecyKey)
{
    for (int i = 0; i < 26; i++)
    {
        prophecyKey->letter[i] = ' ';
    }
}

void insertKeyWithAlphabet(key *prophecyKey)
{
    for (int i = 0; i < 26; i++)
    {
        prophecyKey->letter[i] = 65 + i;
    }
}

void printKey(key *prophecyKey)
{
    for (int i = 0; i < 26; i++)
    {
        printf("%c", prophecyKey->letter[i]);
    }
    printf("\n");
}

void changeKey(key *prophecyKey)
{
    char from[1];
    char to[1];

    printf("\nInforme a letra original, seguida da letra para a qual foi mapeada:\n> ");

    scanf("%s %s", from, to);

    prophecyKey->letter[from[0] - 65] = to[0];

    printf("\nRegistrado: %c -> %c\n", from[0], to[0]);
}

void exportKey(key *prophecyKey, char *path)
{
    FILE *file;
    char finalPath[100], defautlPath[100];

    const char *basePath = "./out/";
    const char *fileName = "key.txt";

    strcat(strcpy(finalPath, path), fileName);

    file = fopen(finalPath, "w");

    if (!file)
    {

        printf("Caminho inválido, por padrão a chave será salva no diretório out/ ");

        strcat(strcpy(defautlPath, basePath), fileName);
        file = fopen(defautlPath, "w");
    }

    for (int i = 0; i < 26; i++)
    {
        fprintf(file, "%c", prophecyKey->letter[i]);
    }

    fclose(file);
}

int totalOfKeysNotFilled(key *prophecyKey)
{
    int total = 0;

    for (int i = 0; i < 26; i++)
    {
        if (prophecyKey->letter[i] == ' ')
        {
            total++;
        }
    }

    return total;
}

int positionOfLetterInKey(key *prophecyKey, char letter)
{
    int position = -1;

    for (int i = 0; i < 26; i++)
    {
        if (prophecyKey->letter[i] == letter)
        {
            position = i;
        }
    }

    return position;
}