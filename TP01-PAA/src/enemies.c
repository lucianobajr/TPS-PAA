#include "../headers/enemies.h"

void makeEmptyList(Enemies *enemies)
{
    enemies->first = (Pointer)malloc(sizeof(Node));
    enemies->last = enemies->first;
    enemies->first->next = NULL;
}

int empty(Enemies enemies)
{
    return (enemies.first == enemies.last);
}

Enemie createEnemie(int p, int k, int position)
{
    Enemie enemie;
    Atrributes atrributes;

    atrributes.p = p;
    atrributes.k = k;
    atrributes.id = enemieId(position);

    enemie.atrributes = atrributes;

    return enemie;
}

void insert(Enemie enemie, Enemies *enemies)
{
    enemies->last->next = (Pointer)malloc(sizeof(Node));
    enemies->last = enemies->last->next;
    enemies->last->enemie = enemie;
    enemies->last->next = NULL;
}

void removeEnemie(Enemies *enemies)
{
    if (enemies->first == NULL)
    {
        return;
    }
    Pointer delete = enemies->first;
    enemies->first = enemies->first->next;
    free(delete);
}

void removeEnemies(Enemies *enemies)
{
    if (empty((*enemies)))
    {
        printf("Erro! A lista esta vazia!");
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            removeEnemie(enemies);
        }
    }
}

void printEnemies(Enemies *enemies)
{
    Pointer aux;
    aux = enemies->first->next;
    while (aux != NULL)
    {
        printf("%d\n", aux->enemie.atrributes.p);
        printf("%d\n", aux->enemie.atrributes.k);
        printf("%s\n", aux->enemie.atrributes.id);
        aux = aux->next;
    }
}

char *enemieId(int position)
{
    char *id;
    switch (position)
    {
    case 1:
        id = "U";
        break;
    case 2:
        id = "T";
        break;
    case 3:
        id = "S";
        break;
    case 4:
        id = "B";
        break;
    case 5:
        id = "G";
        break;
    default:
        break;
    }

    return id;
}

Enemie *findEnemie(Enemies *enemies, char id)
{
    Pointer aux;
    aux = enemies->first->next;
    while (aux != NULL)
    {
        if (aux->enemie.atrributes.id[0] == id)
        {
            return &aux->enemie;
            break;
        }
        aux = aux->next;
    }
}

int giygasPower(Enemies *enemies)
{
    return findEnemie(enemies, 'G')->atrributes.p;
}