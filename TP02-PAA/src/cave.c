#include "../headers/cave.h"

void initializeCave(Cave *cave, int height, int width, int lavaTime)
{
    cave->width = width;
    cave->height = height;
    cave->lavaTime = lavaTime;

    cave->cave = (int **)malloc(sizeof(int *) * cave->width);
    for (int i = 0; i < cave->width; i++)
    {
        // alocar a quantidade de colunas de cada linha
        cave->cave[i] = (int *)malloc(sizeof(int *) * cave->height);
    }
}

int **initilizeTable(int width, int height)
{
    int **table;
    table = (int **)malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++)
    {
        // alocar a quantidade de colunas de cada linha
        table[i] = (int *)malloc(sizeof(int *) * height);
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            table[i][j] = empty;
        }
    }

    return table;
}

int *initilizePaths(int width)
{
    int *paths;

    paths = (int *)malloc(sizeof(int *) * width);

    for (int i = 0; i < width; i++)
    {

        paths[i] = 0;
    }

    return paths;
}

void printCave(Cave *cave)
{
    //printf("height: %d; width: %d; lava-time: %d\n", cave->height, cave->width, cave->lavaTime);

    for (int i = 0; i < cave->width; i++)
    {
        for (int j = 0; j < cave->height; j++)
        {
            printf("%d ", cave->cave[i][j]);
        }
        printf("\n");
    }
}

void insertNode(Cave *cave, int position, int j, char *line)
{

    if (strcmp("###", line) == 0)
    {
        cave->cave[position][j] = invalid;
    }
    else
    {
        // se passamos "106" , a = '1', b = '0', c = '6'
        cave->cave[position][j] = concatenate(line[0], line[1], line[2]);
    }
}

void cleanCave(Cave *cave)
{
    for (int i = 0; i < cave->width; i++)
    {
        free(cave->cave[i]); /* libera as linhas da matriz */
    }

    free(cave->cave); /* libera a matriz */

    cave->height = 0;
    cave->width = 0;
    cave->lavaTime = 0;
}

unsigned concatenate(char a, char b, char c)
{
    int x = (int)a - (int)48; // centena
    int y = (int)b - (int)48; // dezena
    int z = (int)c - (int)48; // unidade

    return (x * 100) + (y * 10) + z;
}