#include <stdio.h>

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

void main()
{
    for (int i = 0; i < 256; i++)
    {
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("\033[38;5;%dm %3d\033[m", i, i);
    }
    printf("\n");
    printf("\n");

    for (int i = 0; i < 26; i++)
    {
        printLetterWithColor('A' + i);
    }

    printf("\n");
}
