#include "../headers/crypto.h"

void preCrypto(frequency *prophecyLettersFrequency, frequency *languageLettersFrequency)
{
    insertFrequencyValues(languageLettersFrequency);
    quickSort(languageLettersFrequency);

    insertDummyValuesFrequencyProphecy(prophecyLettersFrequency);
}

void frequencyAnalysis(message *prophecy, frequency *prophecyLettersFrequency)
{
    float totalLetterOfProphecy = totalLetters(prophecy);
    float totalNumberOfTheLetter = 0;
    float letterFrequency;

    for (int frequency = 0; frequency < 26; frequency++)
    {
        for (int i = 0; i < prophecy->size; i++)
        {
            for (int ii = 0; ii < prophecy->phrases[i].size; ii++)
            {
                for (int iii = 0; iii < prophecy->phrases[i].words[ii].size; iii++)
                {
                    if (prophecyLettersFrequency->letter[frequency] == prophecy->phrases[i].words[ii].letters[iii].letter)
                    {
                        totalNumberOfTheLetter++;
                    }
                }
            }
        }

        letterFrequency = (totalNumberOfTheLetter * 100) / totalLetterOfProphecy;

        prophecyLettersFrequency->value[frequency] = letterFrequency;

        totalNumberOfTheLetter = 0;
    }

    // retorna a tabela já com valores ordenados
    quickSort(prophecyLettersFrequency);
}

void crypto(message *prophecy, frequency *prophecyLettersFrequency, frequency *languageLettersFrequency, key *alphabetKey, key *prophecyKey)
{
    printf("\n=== Texto criptografado ===\n");
    printMessage(prophecy);

    printf("\n=== Chave ===\n");
    printKey(alphabetKey);
    printKey(prophecyKey);

    printf("\n=== Texto parcialmente decifrado ===\n");
    decrypt(prophecy, prophecyKey);
}

void decrypt(message *prophecy, key *prophecyKey)
{
    for (int i = 0; i < prophecy->size; i++)
    {
        for (int ii = 0; ii < prophecy->phrases[i].size; ii++)
        {
            for (int iii = 0; iii < prophecy->phrases[i].words[ii].size; iii++)
            {
                if (prophecy->phrases[i].words[ii].letters[iii].letter > 91 || prophecy->phrases[i].words[ii].letters[iii].letter < 65)
                {
                    printf("\033[38;5;148m");

                    printf("%c", prophecy->phrases[i].words[ii].letters[iii].letter);
                    reset();
                }
                else
                {
                    if (positionOfLetterInKey(prophecyKey, prophecy->phrases[i].words[ii].letters[iii].letter) != -1)
                    {
                        printLetterWithColor(65 + positionOfLetterInKey(prophecyKey, prophecy->phrases[i].words[ii].letters[iii].letter));
                    }
                    else
                    {
                        printf("%c", prophecy->phrases[i].words[ii].letters[iii].letter);
                    }
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

void exportProfecy(message *prophecy, key *prophecyKey, char *path)
{

    FILE *file;
    char finalPath[100], defautlPath[100];

    const char *basePath = "./out/";
    const char *fileName = "prophecy.txt";

    strcat(strcpy(finalPath, path), fileName);

    file = fopen(finalPath, "w");

    if (!file)
    {
        strcat(strcpy(defautlPath, basePath), fileName);
        printf("Caminho inválido, por padrão a chave será salva no diretório out/ ");

        file = fopen(defautlPath, "w");
    }

    for (int i = 0; i < prophecy->size; i++)
    {
        for (int ii = 0; ii < prophecy->phrases[i].size; ii++)
        {
            for (int iii = 0; iii < prophecy->phrases[i].words[ii].size; iii++)
            {
                if (positionOfLetterInKey(prophecyKey, prophecy->phrases[i].words[ii].letters[iii].letter) != -1)
                {
                    fprintf(file, "%c", 65 + positionOfLetterInKey(prophecyKey, prophecy->phrases[i].words[ii].letters[iii].letter));
                }
                else
                {
                    fprintf(file, "%c", prophecy->phrases[i].words[ii].letters[iii].letter);
                }
            }
            fprintf(file, " ");
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void exportResults(message *prophecy, key *prophecyKey)
{
    char pathProphecy[36];
    char pathKey[36];

    printf("\nInforme o caminho do texto decifrado:\n> ");
    scanf("%s", pathProphecy);

    printf("\nInforme o caminho da chave:\n> ");
    scanf("%s", pathKey);

    exportKey(prophecyKey, pathKey);
    exportProfecy(prophecy, prophecyKey, pathProphecy);
}

void reset()
{
    printf("\033[0m");
}

void printLetterWithColor(char letter)
{
    switch (letter)
    {
    case 65:
        printf("\033[38;5;1m");
        printf("A");
        reset();
        break;
    case 66:
        printf("\033[38;5;2m");
        printf("B");
        reset();
        break;
    case 67:
        printf("\033[38;5;3m");
        printf("C");
        reset();
        break;
    case 68:
        printf("\033[38;5;4m");
        printf("D");
        reset();
        break;
    case 69:
        printf("\033[38;5;5m");
        printf("E");
        reset();
        break;
    case 70:
        printf("\033[38;5;6m");
        printf("F");
        reset();
        break;
    case 71:
        printf("\033[38;5;49m");
        printf("G");
        reset();
        break;
    case 72:
        printf("\033[38;5;196m");
        printf("H");
        reset();
        break;
    case 73:
        printf("\033[38;5;198m");
        printf("I");
        reset();
        break;
    case 74:
        printf("\033[38;5;202m");
        printf("J");
        reset();
        break;
    case 75:
        printf("\033[38;5;204m");
        printf("K");
        reset();
        break;
    case 76:
        printf("\033[38;5;208m");
        printf("L");
        reset();
        break;
    case 77:
        printf("\033[38;5;216m");
        printf("M");
        reset();
        break;
    case 78:
        printf("\033[38;5;219m");
        printf("N");
        reset();
        break;
    case 79:
        printf("\033[38;5;142m");
        printf("O");
        reset();
        break;
    case 80:
        printf("\033[38;5;164m");
        printf("P");
        reset();
        break;
    case 81:
        printf("\033[38;5;68m");
        printf("Q");
        reset();
        break;
    case 82:
        printf("\033[38;5;52m");
        printf("R");
        reset();
        break;
    case 83:
        printf("\033[38;5;193m");
        printf("S");
        reset();
        break;
    case 84:
        printf("\033[38;5;28m");
        printf("T");
        reset();
        break;
    case 85:
        printf("\033[38;5;94m");
        printf("U");
        reset();
        break;
    case 86:
        printf("\033[38;5;132m");
        printf("V");
        reset();
        break;
    case 87:
        printf("\033[38;5;122m");
        printf("W");
        reset();
        break;
    case 88:
        printf("\033[38;5;61m");
        printf("X");
        reset();
        break;
    case 89:
        printf("\033[38;5;225m");
        printf("Y");
        reset();
        break;
    case 90:
        printf("\033[38;5;88m");
        printf("Z");
        reset();
        break;
    default:
        break;
    }
}
