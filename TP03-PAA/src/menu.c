#include "../headers/menu.h"

void menu(message *prophecy, frequency *languageLettersFrequency, frequency *prophecyLettersFrequency, key *prophecyKey)
{
    int options;

    reader(prophecy);

    languageLettersFrequency = initializeFrequency();
    prophecyLettersFrequency = initializeFrequency();

    prophecyKey = initializeKey();

    key *alphabetKey = initializeKey();

    insertKeyWithEmptySpace(prophecyKey);
    insertKeyWithAlphabet(alphabetKey);

    preCrypto(prophecyLettersFrequency, languageLettersFrequency);
    frequencyAnalysis(prophecy, prophecyLettersFrequency);

    do
    {
        firstPrint();
        printf("Opção: ");
        scanf("%d", &options);

        switch (options)
        {
        case 1:
            crypto(prophecy, prophecyLettersFrequency, languageLettersFrequency, alphabetKey, prophecyKey);
            break;
        case 2:
            frequencyAnalysisPrint(prophecyLettersFrequency, languageLettersFrequency, totalLetters(prophecy));
            break;
        case 3:
            exactMatch(prophecy);
            break;
        case 4:
            approximateMatch(prophecy, prophecyKey);
            break;
        case 5:
            changeKey(prophecyKey);
            break;
        default:
            if (options != 6)
            {
                printf("\033[38;5;196m");
                printf("\nOPÇÃO INVÁLIDA!\n");
                reset();
            }
            break;
        }

    } while (options != 6);

    exportResults(prophecy, prophecyKey);
}

void reader(message *prophecy)
{
    FILE *file;
    char fileName[100], path[100];
    const char *basePath = "./data/";

    printf("Digite o nome do arquivo (com .txt): ");
    scanf("%s", fileName);

    strcat(strcpy(path, basePath), fileName);

    file = fopen(path, "r");

    while (!file)
    {
        printf("Erro ao ler o arquivo!\n");
        printf("\n");

        printf("Digite o nome do arquivo novamente: ");
        scanf("%s", fileName);

        strcat(strcpy(path, basePath), fileName);

        file = fopen(path, "r");
    }

    char **tmpMessage;

    // alocação do texto temporário
    tmpMessage = (char **)malloc(sizeof(char *) * 1024);
    for (int i = 0; i < 1024; i++)
    {
        tmpMessage[i] = (char *)malloc(sizeof(char *) * 1024);
    }

    int nonEmptyLines = 0;
    int totalLines = 0;

    while (fgets(tmpMessage[totalLines], 1024, file) != NULL)
    {
        if (strlen(tmpMessage[totalLines]) != SIZE_EMPTY_LINE)
        {
            nonEmptyLines++;
        }
        totalLines++;
    }

    initializeMessage(prophecy, tmpMessage, totalLines, nonEmptyLines);

    fclose(file);

    for (int i = 0; i < 1024; i++)
    {
        free(tmpMessage[i]);
    }

    free(tmpMessage);
}

void firstPrint()
{
    printf("\n");
    printf("|----------------- Trabalho Pratico 03 -----------------|\n");
    printf("|                                                       |\n");
    printf("|      (1) Apresentar o estado atual da criptoanálise   |\n");
    printf("|                                                       |\n");
    printf("|      (2) Fazer análise de frequência no texto         |\n");
    printf("|          criptografado                                |\n");
    printf("|                                                       |\n");
    printf("|      (3) Realizar casamento exato de caracteres no    |\n");
    printf("|          texto criptografado                          |\n");
    printf("|                                                       |\n");
    printf("|      (4) Realizar casamento aproximado de caracteres  |\n");
    printf("|          no texto parcialmente decifrado              |\n");
    printf("|                                                       |\n");
    printf("|      (5) Alterar chave de criptografia;               |\n");
    printf("|                                                       |\n");
    printf("|      (6) Exportar resultado e encerrar o programa.    |\n");
    printf("|                                                       |\n");
    printf("|-------------------------------------------------------|\n");
    printf("\n");
}