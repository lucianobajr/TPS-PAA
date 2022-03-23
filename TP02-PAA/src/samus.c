#include "../headers/samus.h"

void initializeSamus(Samus *samus, int time)
{
    samus->time = time;
}

void printSamus(Samus *samus)
{
    printf("Time: %d\n", samus->time);
}


void cleanSamus(Samus *samus)
{
    samus->time = 0;
}