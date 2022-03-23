#include "../headers/map.h"

void initializeData(Data *data)
{
    data->number_of_recursions = -1;
}

void initialize(Map *map, int width, int height)
{
    map->width = width;
    map->height = height;

    map->map = (char **)malloc(sizeof(char *) * width);
    for (int i = 0; i < width; i++)
    {
        // alocar a quantidade de colunas de cada linha
        map->map[i] = (char *)malloc(sizeof(char *) * height);
    }
}

void insertLine(Map *map, int position, char *line)
{
    for (int i = 0; i < map->width; i++)
    {
        for (int j = 0; j < map->height; j++)
        {
            map->map[position][j] = line[j];
        }
    }
}

void startCoordinates(Map *map, Ness *ness)
{
    for (int i = 0; i < map->width; i++)
    {
        for (int j = 0; j < map->height; j++)
        {
            if (map->map[i][j] == '@')
            {
                changeNessCoordinates(ness, i, j);
            }
        }
    }
}

int isSafe(Map *map, int x, int y)
{
    return (x >= 0 && x < map->width && y >= 0 && y < map->height && map->map[x][y] != '.');
}

int isEnemy(Map *map, int x, int y)
{
    return (map->map[x][y] == 'U' || map->map[x][y] == 'T' || map->map[x][y] == 'S' || map->map[x][y] == 'B' || map->map[x][y] == 'G');
}

int isGiygas(Map *map, int x, int y)
{
    return (map->map[x][y] == 'G');
}

int isAnEnemyAlreadyDefeated(Map *map, Queue *moviments, int x, int y)
{
    return (isInQueueWhateverDirection(moviments, x, y));
}

int isIntersection(Map *map, Ness *ness, Enemies *enemies, Queue *moviments, int x, int y)
{
    int win;
    if (!isGiygas(map, x, y) && isEnemy(map, x, y) && !isAnEnemyAlreadyDefeated(map, moviments, x, y))
    {
        win = battle(ness, findEnemie(enemies, map->map[x][y]));
        printf("Linha: %d, Coluna: %d; P: %d, K: %d;\n", x, y, ness->p, ness->k);
    }
    else
    {
        // ja batalhou e venceu
        win = TRUE;
    }

    return (map->map[x][y] == '@' || map->map[x][y] == '+') || (isEnemy(map, x, y) && win);
}

int move(Map *map, Ness *ness, Enemies *enemies, Queue *moviments, int *direction, int line, int column, int *goBack, int *opcao1, Data *data)
{
    if ((*opcao1) == 2)
    {
        data->number_of_recursions++;
    }

    printf("Linha: %d, Coluna: %d;\n", line, column);
    if (isGiygas(map, line, column))
    {
        if (ness->p >= giygasPower(enemies))
        {
            return TRUE;
        }
    }
    else if (isIntersection(map, ness, enemies, moviments, line, column))
    {
        if (goMove(map, UP, line, column) && (*direction) != DOWN)
        {
            if (!isInQueue(moviments, line, column, UP) && !isInQueue(moviments, line - 1, column, UP))
            {
                *direction = UP;
                *goBack = FALSE;
                toQueue(newItem(line, column, ness->p, ness->k, UP, map->map[line][column]), moviments);
                return move(map, ness, enemies, moviments, direction, line - 1, column, goBack, opcao1, data);
            }
        }

        if (goMove(map, DOWN, line, column) && (*direction) != UP)
        {
            if (!isInQueue(moviments, line, column, DOWN) && !isInQueue(moviments, line + 1, column, DOWN))
            {
                *direction = DOWN;
                *goBack = FALSE;
                toQueue(newItem(line, column, ness->p, ness->k, DOWN, map->map[line][column]), moviments);
                return move(map, ness, enemies, moviments, direction, line + 1, column, goBack, opcao1, data);
            }
        }

        if (goMove(map, LEFT, line, column) && (*direction) != RIGHT)
        {
            if (!isInQueue(moviments, line, column, LEFT) && !isInQueue(moviments, line, column - 1, LEFT))
            {
                *direction = LEFT;
                *goBack = FALSE;
                toQueue(newItem(line, column, ness->p, ness->k, LEFT, map->map[line][column]), moviments);
                return move(map, ness, enemies, moviments, direction, line, column - 1, goBack, opcao1, data);
            }
        }

        if (goMove(map, RIGHT, line, column) && (*direction) != LEFT)
        {
            if (!isInQueue(moviments, line, column, RIGHT) && !isInQueue(moviments, line, column + 1, RIGHT))
            {
                *direction = RIGHT;
                *goBack = FALSE;
                toQueue(newItem(line, column, ness->p, ness->k, RIGHT, map->map[line][column]), moviments);
                return move(map, ness, enemies, moviments, direction, line, column + 1, goBack, opcao1, data);
            }
        }

        // significa que ness não pode ir nem para cima, nem para baixo,
        // nem para esqueda e nem direita => não tem como movimentar
        if (line == ness->line && ness->column == column)
        {
            return FALSE;
        }

        // tenta voltar para um caminho possivel
        if (!(*goBack))
        {
            *direction = 0;
            *goBack = TRUE;

            backToLastNode(moviments, &line, &column);
            return move(map, ness, enemies, moviments, direction, line, column, goBack, opcao1, data);
        }
    }
    else
    {
        *goBack = FALSE;

        if ((*direction) == UP)
        {
            return move(map, ness, enemies, moviments, direction, line - 1, column, goBack, opcao1, data);
        }
        else if ((*direction) == LEFT)
        {
            return move(map, ness, enemies, moviments, direction, line, column - 1, goBack, opcao1, data);
        }
        else if ((*direction) == RIGHT)
        {
            return move(map, ness, enemies, moviments, direction, line, column + 1, goBack, opcao1, data);
        }
        else
        {
            return move(map, ness, enemies, moviments, direction, line + 1, column, goBack, opcao1, data);
        }
    }

    return FALSE;
}

int goMove(Map *map, int direction, int x, int y)
{
    switch (direction)
    {
    case UP:
        if (isSafe(map, x - 1, y))
        {
            return TRUE;
        }
        break;
    case DOWN:
        if (isSafe(map, x + 1, y))
        {
            return TRUE;
        }
        break;
    case LEFT:
        if (isSafe(map, x, y - 1))
        {
            return TRUE;
        }
        break;
    case RIGHT:
        if (isSafe(map, x, y + 1))
        {
            return TRUE;
        }
        break;
    default:
        return FALSE;
        break;
    }
}

int battle(Ness *ness, Enemie *enemie)
{
    // não precisa do PK Flash
    if (ness->p >= enemie->atrributes.p)
    {
        ness->p = ness->p + enemie->atrributes.k;
        return TRUE;
    }
    // PK Flash
    else if (ness->k > 0)
    {
        ness->k = ness->k - 1;
        ness->p = ness->p + enemie->atrributes.k;
        return TRUE;
    }
    // perde
    else
    {
        return FALSE;
    }
}

void printMap(Map *map)
{
    printf("width: %d; height: %d \n", map->width, map->height);
    for (int i = 0; i < map->width; i++)
    {
        for (int j = 0; j < map->height; j++)
        {
            printf("%c", map->map[i][j]);
        }
        printf("\n");
    }
}

void cleanMap(Map *map)
{
    for (int i = 0; i < map->width; i++)
        free(map->map[i]); /* libera as linhas da matriz */
    free(map->map);        /* libera a matriz */

    map->height = 0;
    map->width = 0;
}