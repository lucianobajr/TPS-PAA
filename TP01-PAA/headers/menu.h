#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../headers/map.h"

int menu(Ness *ness, Enemies *enemies, Map *map, Queue *moviments, Data *data);
void clean(Ness *ness, Enemies *enemies, Map *map, Queue *moviments, int *direction, int *goBack, int *lines, int *lineMap);
void firstPrint();
void secondPrint();
void common(Ness *ness, Enemies *enemies, Map *map, Queue *moviments, char **line, char fileName[100], char path[100], FILE **file, int *lines, int *p, int *k, int *height, int *width, int *lineMap, int *resposta, Data *data, int *option);

#endif // MENU_H