#ifndef MENU_h
#define MENU_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "../headers/subproblems.h"

/*
 * menu
 */
int menu(Cave *cave, Samus *samus, SubproblemsTable *subproblemsTable);

/*
 * primeiro print
 */
void firstPrint();

/*
 * segundo print
 */
void secondPrint();
/*
 * driver comum para chamadas do algoritmo
 */
int common(Cave *cave, Samus *samus, SubproblemsTable *subproblemsTable, char **line, char fileName[100], char path[100], FILE **file, int *lines, int *height, int *width, int *time, int *lavaTime, int *lineMap, int *resposta, int *option);

#endif