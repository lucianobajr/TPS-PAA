#include "../headers/ness.h"

void initializeNess(Ness *ness, int p, int k)
{
    ness->p = p;
    ness->k = k;
    ness->line = -1;
    ness->column = -1;
}

void changeNessCoordinates(Ness *ness, int x, int y)
{
    ness->line = x;
    ness->column = y;
}

void printNess(Ness *ness)
{
    printf("P: %d\n", ness->p);
    printf("k: %d\n", ness->k);
}

void cleanNess(Ness *ness)
{
    ness->p = -1;
    ness->k = -1;
    ness->line = -1;
    ness->column = -1;
}