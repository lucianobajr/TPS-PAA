#include "generate.h"

char ***createMap(int height, int width)
{
    char ***map;

    map = (char ***)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++)
    {
        // alocar a quantidade de colunas de cada linha
        map[i] = (char **)malloc(sizeof(char *) * width);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = (char *)malloc(sizeof(char *) * 3);
        }
    }

    return map;
}

int genereteInt(int level)
{
    int value;

    switch (level)
    {
    case LEVEL_1:
        value = rand() % (50);
        break;

    case LEVEL_2:
        value = 51 + rand() % (150);
        break;

    case LEVEL_3:
        value = 151 + rand() % (300);
        break;

    case LEVEL_4:
        value = 301 + rand() % (550);
        break;

    case LEVEL_5:
        value = 551 + rand() % (999);
        break;

    default:
        value = rand() % (50);
        break;
    }

    return value;
}

void fillMap(char ***map, int height, int width, int level)
{
    srand(time(NULL));
    int samusTime, lavaTime;

    samusTime = rand() % (genereteInt(level));
    lavaTime = rand() % (genereteInt(level));

    for (int i = 0; i < height; i++)
    {

        if (i % 2 != 0)
        {
            strcpy(map[i][0], "  ");
        }

        for (int j = 0; j < width; j++)
        {

            strcat(map[i][j], generateString(level));
            if (j != width - 1)
            {
                strcat(map[i][j], " ");
            }
        }
    }

    createFile(map, height, width, lavaTime, samusTime, level);
}

char *generateString(int level)
{
    int option = rand() % 3;
    if (option == 0 || option == 2)
        return intToString(genereteInt(level));
    else
        return "###";
}

char *intToString(int value)
{
    int unit = value % 10;
    int ten = ((value - unit) / 10) % 10;
    int hundred = ((value - unit) / 10 - ten) / 10;

    char *string = (char *)malloc(10 * sizeof(char));
    string[0] = hundred + '0';
    string[1] = ten + '0';
    string[2] = unit + '0';

    return string;
}

char *convertIntToString(int value)
{
    char *newString = (char *)malloc(sizeof(char *) * 30);

    sprintf(newString, "%d", value);

    return newString;
}

void createFile(char ***map, int height, int width, int lavaTime, int samusTime, int level)
{
    char *path = (char *)malloc(sizeof(char *) * 30);
    char *auxFileName = (char *)malloc(sizeof(char *) * 10);
    char *fileName = (char *)malloc(sizeof(char *) * 30);

    strcat(path, "data/");
    auxFileName = convertIntToString(height);
    strcat(fileName, auxFileName);
    strcat(fileName, "x");
    auxFileName = convertIntToString(width);
    strcat(fileName, auxFileName);
    strcat(fileName, "nvl");
    auxFileName = convertIntToString(level);
    strcat(fileName, auxFileName);
    strcat(fileName, ".txt");
    strcat(path, fileName);

    FILE *file;
    file = fopen(path, "w");

    if (!file)
    {
        printf("Erro ao ler o arquivo!\n");
        printf("\n");
    }
    else
    {
        char *newString = (char *)malloc(sizeof(char *) * 30);
        newString = convertIntToString(height);
        fputs(newString, file);
        fputs(" ", file);

        newString = convertIntToString(width);
        fputs(newString, file);
        fputs(" ", file);

        newString = convertIntToString(samusTime);
        fputs(newString, file);
        fputs(" ", file);

        newString = convertIntToString(lavaTime);
        fputs(newString, file);
        fputs("\n", file);

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                fputs(map[i][j], file);
            }
            if (i != height - 1)
            {
                fputs("\n", file);
            }
        }
    }

    fclose(file);
}

/*
    ------NÍVEIS------
    - 1 => 0 a 50    -
    - 2 => 51 a 150  -
    - 3 => 151 a 300 -
    - 4 => 301 a 550 -
    - 5 => 551 a 999 -
    ------NÍVEIS------
*/

void main()
{
    int width, height, level;

    printf("Altura do mapa: ");
    scanf("%d", &height);

    printf("Largura do mapa: ");
    scanf("%d", &width);

    do
    {
        printf("Nível de dificultade (1 a 5): ");
        scanf("%d", &level);
    } while (level != 1 && level != 2 && level != 3 && level != 4 && level != 5);

    char ***map = createMap(height, width);

    fillMap(map, height, width, level);
}