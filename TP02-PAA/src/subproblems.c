#include "../headers/subproblems.h"

void initializeSubproblemsTable(SubproblemsTable *subproblemsTable, int width, int height)
{
    subproblemsTable->width = width;
    subproblemsTable->height = height;

    subproblemsTable->table = (Subproblem **)malloc(sizeof(Subproblem) * subproblemsTable->width);
    for (int i = 0; i < subproblemsTable->width; i++)
    {
        // alocar a quantidade de colunas de cada linha
        subproblemsTable->table[i] = (Subproblem *)malloc(sizeof(Subproblem) * subproblemsTable->height);
    }
}

void printSubproblemsTable(SubproblemsTable *subproblemsTable)
{
    for (int i = 0; i < subproblemsTable->width; i++)
    {
        for (int j = 0; j < subproblemsTable->height; j++)
        {
            printf("%d ", subproblemsTable->table[i][j].value);
        }
        printf("\n");
    }

    printf("\n");
}

Subproblem lessInitialValue(Subproblem *lines, int height)
{
    Subproblem response;
    int less = empty;

    for (int i = 0; i < height; i++)
    {
        if (less == empty && lines[i].value != invalid)
        {
            less = lines[i].value;
            response = lines[i];
        }
        else if (lines[i].value != invalid && lines[i].value < less)
        {
            less = lines[i].value;
            response = lines[i];
        }
    }

    return response;
}

int totalTime(Cave *cave, SubproblemsTable *subproblemsTable, Samus *samus)
{
    Subproblem lessTime = lessInitialValue(subproblemsTable->table[cave->width - 1], subproblemsTable->height);

    int time = 0;

    for (int i = 0; i < cave->width; i++)
    {

        time = time + samus->time + cave->cave[lessTime.line][lessTime.column];

        if (lessTime.prevLine != invalid)
        {
            lessTime = subproblemsTable->table[lessTime.prevLine][lessTime.prevColumn];
        }
    }

    return time;
}

void move(Cave *cave, SubproblemsTable *subproblemsTable, Samus *samus,int *win)
{
    int limitTime = cave->lavaTime * cave->width;
    int time = totalTime(cave, subproblemsTable, samus);

    Subproblem lessTime = lessInitialValue(subproblemsTable->table[cave->width - 1], subproblemsTable->height);

    if (lessTime.value == invalid)
    {
        printf("\nSamus falhou na missao\n");
        *win = FALSE;
    }
    else
    {
        printf("\nTEMPO GASTO: %d\nTEMPO DA LAVA: %d\n", time, limitTime);

        lessTime = lessInitialValue(subproblemsTable->table[cave->width - 1], subproblemsTable->height);

        if (time <= limitTime)
        {
            printf("\nSamus sai das cavernas em seguranca!\n\nCaminho:\n");

            for (int i = 0; i < cave->width; i++)
            {
                printf("%d %d\n", lessTime.line, lessTime.column);

                if (lessTime.prevLine != invalid)
                {
                    lessTime = subproblemsTable->table[lessTime.prevLine][lessTime.prevColumn];
                }
            }

            *win = TRUE;
        }
        else
        {
            printf("\nSamus falhou na missão\n");
            *win = FALSE;
        }
    }
}

void printPath(Cave *cave, SubproblemsTable *subproblemsTable)
{
    int **solution;

    solution = (int **)malloc(sizeof(int *) * subproblemsTable->width);
    for (int i = 0; i < subproblemsTable->width; i++)
    {
        // alocar a quantidade de colunas de cada linha
        solution[i] = (int *)malloc(sizeof(int *) * 2);
    }

    Subproblem lessTime = lessInitialValue(subproblemsTable->table[cave->width - 1], subproblemsTable->height);

    for (int i = 0; i < cave->width; i++)
    {
        solution[i][0] = lessTime.line;
        solution[i][1] = lessTime.column;

        if (lessTime.prevLine != invalid)
        {
            lessTime = subproblemsTable->table[lessTime.prevLine][lessTime.prevColumn];
        }
    }

    printf("\n\n");

    int aux = 0;
    int copy = 0;

    for (int k = cave->width - 1; k >= 0; k--)
    {
        if (copy == 1)
        {
            copy = 0;
            aux = aux + 1;
        }
        for (int i = cave->width - 1; i >= 0; i--)
        {

            for (int j = 0; j < cave->height; j++)
            {

                if (i % 2 != 0)
                {
                    if (cave->cave[i][j] == -1)
                    {
                        printf(" ### ");
                    }
                    else
                    {
                        if ((solution[aux][0] == i) && (solution[aux][1] == j))
                        {
                            printf(" ^_^ ");
                            copy = 1;
                        }
                        else
                        {
                            printf(" ... ");
                        }
                    }
                }
                else
                {
                    if (cave->cave[i][j] == -1)
                    {
                        printf("### ");
                    }
                    else
                    {
                        if ((solution[aux][0] == i) && (solution[aux][1] == j))
                        {
                            printf(" ^_^ ");
                            copy = 1;
                        }
                        else
                        {
                            printf("... ");
                        }
                    }
                }
            }

            printf("\n");
        }

        printf("\n\n");
    }
}

void solver(Cave *cave, SubproblemsTable *subproblemsTable)
{
    for (int i = 0; i < cave->width; i++)
    {
        for (int j = 0; j < cave->height; j++)
        {
            if (cave->cave[i][j] != invalid)
            {

                Subproblem subproblem;
                subproblem.line = i;
                subproblem.column = j;

                // verifica alinhamento das linhas
                // por padrão as linhas pares (0,2,4...) não tem
                if (i % 2 == 0)
                {
                    if (i - 1 >= 0)
                    {
                        // não é possível ir nem pra esquerda nem pra direita
                        if (((j - 1 < 0) || subproblemsTable->table[i - 1][j - 1].value == invalid) == TRUE && (subproblemsTable->table[i - 1][j].value == invalid) == TRUE)
                        {
                            subproblem.value = invalid;
                            subproblem.prevLine = invalid;
                            subproblem.prevColumn = invalid;
                        }
                        else
                        {
                            // é possível ir para esquerda e para direita
                            if ((j - 1 >= 0 && subproblemsTable->table[i - 1][j - 1].value != invalid) == TRUE && (subproblemsTable->table[i - 1][j].value != invalid) == TRUE)
                            {

                                int left = subproblemsTable->table[i - 1][j - 1].value;
                                int right = subproblemsTable->table[i - 1][j].value;

                                // esquerda > direita? direita : esquerda
                                if (left > right)
                                {
                                    subproblem.value = cave->cave[i][j] + right;
                                    subproblem.prevLine = i - 1;
                                    subproblem.prevColumn = j;
                                }
                                else
                                {
                                    subproblem.value = cave->cave[i][j] + left;
                                    subproblem.prevLine = i - 1;
                                    subproblem.prevColumn = j - 1;
                                }
                            }
                            else if ((j - 1 >= 0 && subproblemsTable->table[i - 1][j - 1].value != invalid) == TRUE && (subproblemsTable->table[i - 1][j].value != invalid) == FALSE)
                            {
                                // é possível ir somente para esquerda
                                subproblem.value = cave->cave[i][j] + subproblemsTable->table[i - 1][j - 1].value;
                                subproblem.prevLine = i - 1;
                                subproblem.prevColumn = j - 1;
                            }
                            else if ((j - 1 >= 0 && subproblemsTable->table[i - 1][j - 1].value != invalid) == FALSE && (subproblemsTable->table[i - 1][j].value != invalid) == TRUE)
                            {
                                // é possível ir somente para direita
                                subproblem.value = cave->cave[i][j] + subproblemsTable->table[i - 1][j].value;
                                subproblem.prevLine = i - 1;
                                subproblem.prevColumn = j;
                            }
                        }
                    }
                    else
                    {
                        // fora da caverna
                        subproblem.value = cave->cave[i][j];
                        subproblem.prevLine = invalid;
                        subproblem.prevColumn = invalid;
                    }
                }
                // linhas ímpares
                else
                {
                    // não é possível ir nem pra esquerda nem pra direita
                    if ((subproblemsTable->table[i - 1][j].value == invalid) == TRUE && ((j + 1 > cave->height) || subproblemsTable->table[i - 1][j + 1].value == invalid) == TRUE)
                    {
                        subproblem.value = invalid;
                        subproblem.prevLine = invalid;
                        subproblem.prevColumn = invalid;
                    }
                    else
                    {
                        // é possível ir para esquerda e para direita
                        if ((subproblemsTable->table[i - 1][j].value != invalid) == TRUE && ((j + 1 < cave->height) && subproblemsTable->table[i - 1][j + 1].value != invalid) == TRUE)
                        {
                            int left = subproblemsTable->table[i - 1][j].value;
                            int right = subproblemsTable->table[i - 1][j + 1].value;

                            // esquerda > direita? direita : esquerda
                            if (left > right)
                            {
                                subproblem.value = cave->cave[i][j] + right;
                                subproblem.prevLine = i - 1;
                                subproblem.prevColumn = j + 1;
                            }
                            else
                            {
                                subproblem.value = cave->cave[i][j] + left;
                                subproblem.prevLine = i - 1;
                                subproblem.prevColumn = j;
                            }
                        }
                        else if ((subproblemsTable->table[i - 1][j].value != invalid) == TRUE && ((j + 1 < cave->height) && subproblemsTable->table[i - 1][j + 1].value != invalid) == FALSE)
                        {
                            //é possível ir somente para esquerda
                            subproblem.value = cave->cave[i][j] + subproblemsTable->table[i - 1][j].value;
                            subproblem.prevLine = i - 1;
                            subproblem.prevColumn = j;
                        }
                        else if ((subproblemsTable->table[i - 1][j].value != invalid) == FALSE && ((j + 1 < cave->height) && subproblemsTable->table[i - 1][j + 1].value != invalid) == TRUE)
                        {
                            //é possível ir somente para direita
                            subproblem.value = cave->cave[i][j] + subproblemsTable->table[i - 1][j + 1].value;
                            subproblem.prevLine = i - 1;
                            subproblem.prevColumn = j + 1;
                        }
                    }
                }

                subproblemsTable->table[i][j] = subproblem;
            }
            else
            {
                Subproblem subproblem;
                subproblem.line = i;
                subproblem.column = j;
                subproblem.value = invalid;

                subproblem.prevLine = invalid;
                subproblem.prevColumn = invalid;

                subproblemsTable->table[i][j] = subproblem;
            }
        }
    }
}