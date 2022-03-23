#include "../headers/menu.h"

int menu(Cave *cave, Samus *samus, SubproblemsTable *subproblemsTable)
{
    FILE *file;

    int opcao = 1;
    int opcao1 = 0;

    firstPrint();

    do
    {
        const char *basePath = "./data/";
        char *line, fileName[100], path[100];
        int height, width, time, lavaTime, resposta, fileNotFound;
        int lines = 0, lineMap = 0;
        double tempo;
        clock_t fim, inicio;
        int win;

        win = common(cave, samus, subproblemsTable, &line, fileName, path, &file, &lines, &time, &lavaTime, &height, &width, &lineMap, &resposta, &opcao);

        if (win == TRUE)
        {
            secondPrint();
            printf("Opção: ");
            scanf("%d", &opcao1);

            if (opcao1 == 1)
            {
                inicio = clock();
                move(cave, subproblemsTable, samus, &win);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nEu Avancei no tempo, pra ver outros futuros\ne acessar os possíveis resultados desse conflito, vamos gastar = %lfs\n", tempo);
            }
            else if (opcao1 == 2)
            {
                printPath(cave, subproblemsTable);
            }
        }

        printf("\nDeseja executar novamente? (Sim: 1, Não: 0)\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao != 1)
        {
            printf("\nSinto que vamos nos ver em breve! Até logo.\n");
        }

    } while (opcao == 1);
}

int common(Cave *cave, Samus *samus, SubproblemsTable *subproblemsTable, char **line, char fileName[100], char path[100], FILE **file, int *lines, int *height, int *width, int *time, int *lavaTime, int *lineMap, int *resposta, int *option)
{
    int **table;
    const char *basePath = "./data/";
    printf("Digite o nome do arquivo (com .txt): ");
    scanf("%s", fileName);

    strcat(strcpy(path, basePath), fileName);

    (*file) = fopen(path, "r");

    while (!(*file))
    {
        printf("Erro ao ler o arquivo!\n");
        printf("\n");

        printf("Digite o nome do arquivo novamente: ");
        scanf("%s", fileName);

        strcat(strcpy(path, basePath), fileName);

        (*file) = fopen(path, "r");
    }

    while (!feof((*file)))
    {
        if ((*lines) == 0)
        {
            // altura e largura cada nível da caverna, tempo e o tempo da lava
            fscanf((*file), "%d %d %d %d", &(*height), &(*width), &(*time), &(*lavaTime));

            initializeCave(cave, (*width), (*height), (*lavaTime));
            initializeSubproblemsTable(subproblemsTable, (*height), (*width));
            initializeSamus(samus, (*time));

            int lineSize = (*width) * 3 + ((*width) - 1);

            (*line) = (char *)malloc(sizeof(char *) * lineSize);
        }
        else if ((*lines) >= 1 && (*lines) <= 1 + (*height))
        {
            // verifica se não está alinhado a esquerda
            //  já que por definição não se começa,
            //  as linhas ímpares entrarão sempre nesta condição
            if ((*lineMap) % 2 == 1)
            {
                for (int j = 0; j < (*width); j++)
                {
                    // caverna
                    fscanf((*file), "%s", (*line));
                    insertNode(cave, (*lineMap), j, (*line));
                }
            }
            else
            {
                for (int j = 0; j < (*width); j++)
                {
                    // caverna
                    fscanf((*file), "  %s", (*line));
                    insertNode(cave, (*lineMap), j, (*line));
                }
            }
            (*lineMap)++;
        }
        else
        {
            fclose((*file));
            break;
        }

        (*lines)++;
    }

    int win;

    printf("\nEste é o mapa do nosso desafio, para o alto e avante!\n\n");
    printCave(cave);
    printf("\n");

    solver(cave, subproblemsTable);
    move(cave, subproblemsTable, samus, &win);

    return win;
}

void firstPrint()
{
    printf("\n");
    printf("|----------------Trabalho Pratico 02----------------|\n");
    printf("|                                                   |\n");
    printf("|     Projeto e Analise de Algoritmos - CCF 330     |\n");
    printf("|                                                   |\n");
    printf("|---------------------------------------------------|\n");
}

void secondPrint()
{
    printf("\n");
    printf("|----------------Trabalho Pratico 02----------------|\n");
    printf("|                                                   |\n");
    printf("|        (1) Ver o tempo gasto para execução        |\n");
    printf("|    (2) Mostrar o melhor caminho graficamente      |\n");
    printf("|                                                   |\n");
    printf("|---------------------------------------------------|\n");
}