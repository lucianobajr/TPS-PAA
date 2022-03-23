#include "../headers/menu.h"

int menu(Ness *ness, Enemies *enemies, Map *map, Queue *moviments, Data *data)
{
    FILE *file;

    int opcao;

    firstPrint();

    while (opcao != 3)
    {
        const char *basePath = "./data/";
        char *line, fileName[100], path[100];
        int p, k, width, height, resposta, fileNotFound;
        int lines = 0, lineMap = 0;

        makeEmptyList(enemies);
        makeEmptyQueue(moviments);

        secondPrint();
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            common(ness, enemies, map, moviments, &line, fileName, path, &file, &lines, &p, &k, &height, &width, &lineMap, &resposta, data, &opcao);
            break;

        case 2:
            initializeData(data);
            common(ness, enemies, map, moviments, &line, fileName, path, &file, &lines, &p, &k, &height, &width, &lineMap, &resposta, data, &opcao);
            printf("Número total de chamadas recursivas: %d\n", data->number_of_recursions);
            break;
        case 3:
            break;
        }
    }
}

void clean(Ness *ness, Enemies *enemies, Map *map, Queue *moviments, int *direction, int *goBack, int *lines, int *lineMap)
{

    (*direction) = 0;
    (*goBack) = FALSE;
    (*lines) = 0;
    (*lineMap) = 0;

    removeEnemies(enemies);
    cleanQueue(moviments);
    cleanNess(ness);
    cleanMap(map);
}

void firstPrint()
{
    printf("\n");
    printf("|----------------Trabalho Pratico 01----------------|\n");
    printf("|                                                   |\n");
    printf("|     Projeto e Analise de Algoritmos - CCF 330     |\n");
    printf("|                                                   |\n");
    printf("|---------------------------------------------------|\n");
}

void secondPrint()
{
    printf("\n");
    printf("|---------------------------------------------------|\n");
    printf("|          Insira o numero da opcao desejada:       |\n");
    printf("|                                                   |\n");
    printf("|     [1] - Ler arquivo de entrada                  |\n");
    printf("|     [2] - Modo de Analise                         |\n");
    printf("|     [3] - Sair do programa                        |\n");
    printf("|---------------------------------------------------|\n");
}

void common(Ness *ness, Enemies *enemies, Map *map, Queue *moviments, char **line, char fileName[100], char path[100], FILE **file, int *lines, int *p, int *k, int *height, int *width, int *lineMap, int *resposta, Data *data, int *option)
{
    const char *basePath = "./data/";
    printf("Digite o nome do arquivo (com .txt): ");
    scanf("%s", fileName);

    strcat(strcpy(path, basePath), fileName);
    printf("%s\n", path);

    (*file) = fopen(path, "r");

    while (!(*file))
    {
        printf("Erro ao ler o arquivo!\n");
        printf("\n");

        printf("Inisra o nome do arquivo novamente: ");
        scanf("%s", fileName);

        strcat(strcpy(path, basePath), fileName);

        (*file) = fopen(path, "r");
    }

    while (!feof((*file)))
    {
        if ((*lines) == 0)
        {
            // ness
            fscanf((*file), "%d %d", &(*p), &(*k));
            initializeNess(ness, (*p), (*k));
        }
        else if ((*lines) >= 1 && (*lines) <= 5)
        {
            // enemies
            fscanf((*file), "%d %d", &(*p), &(*k));
            insert(createEnemie((*p), (*k), (*lines)), enemies);
        }
        else if ((*lines) == 6)
        {
            // dimensiones map
            fscanf((*file), "%d %d", &(*height), &(*width));
            initialize(map, (*height), (*width));

            (*line) = (char *)calloc((*width), sizeof(char));
        }
        else if ((*lines) > 6 && (*lines) <= 6 + (*height))
        {
            // map
            fscanf((*file), "%s", (*line));
            insertLine(map, (*lineMap), (*line));
            (*lineMap)++;
        }
        else
        {
            break;
        }

        (*lines)++;
    }

    printf("Arquivo carregado com sucesso!\n");
    printf("\n");

    fclose((*file));

    startCoordinates(map, ness);

    int direction = 0;
    int goBack = FALSE;

    printf("Linha: %d, Coluna: %d; P: %d, K: %d\n", ness->line, ness->column, ness->p, ness->k);
    (*resposta) = move(map, ness, enemies, moviments, &direction, ness->line, ness->column, &goBack, option, data);

    if ((*resposta) == 0)
    {
        printf("Apesar de todas as tentativas, Ness falha em derrotar Giygas!\n");
    }
    else
    {
        printf("Ness derrota Giygas! Ainda bem estavamos com pressa!\n");
    }
}
