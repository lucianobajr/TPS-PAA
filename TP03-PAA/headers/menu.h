#ifndef MENU_h
#define MENU_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./crypto.h"
#include "../headers/ocurrence.h"

#define TRUE 1
#define FALSE 0

/*
 * menu
 */
void menu(message *prophecy, frequency *languageLettersFrequency, frequency *prophecyLettersFrequency, key *prophecyKey);

/*
 * primeiro print
 */
void firstPrint();

/*
 * lê o arquivo
 */
void reader(message *prophecy);

#endif