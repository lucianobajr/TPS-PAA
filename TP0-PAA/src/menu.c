#include "../headers/menu.h"
#include "../headers/quadro.h"

void menu()
{
    int resp = 1;
    int size;
    char **frame;

    while (resp != 0)
    {
        frame = CriaQuadro();
        print_menu1();
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &size);
            Asterisco(frame, verificaEntrada(size));
            print_frame(frame);
            break;
        case 2:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &size);
            somaComAsterisco(frame, verificaEntrada(size));
            print_frame(frame);
            break;
        case 3:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &size);
            LetraX(frame, verificaEntrada(size));
            print_frame(frame);
            break;
        case 4:
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
            scanf("%d", &size);
            randomico(frame, verificaEntrada(size));
            print_frame(frame);
            break;
        case 5:
            srand(time(0));
            obraDeArteStatic(frame, verificaEntrada(rand() % 99));
            print_frame(frame);
            break;
        default:
            break;
        }
    }
}

void print_menu1()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 80; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 24; i++)
    {
        fputs(" ", stdout);
    }
    printf("PROGRAMA GERADOR DE OBRA DE ARTE");
    for (i = 0; i < 24; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 80; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:");
    for (i = 0; i < 13; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("1 - asterisco simples.");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("2 - simbolo de soma com asteriscos.");
    for (i = 0; i < 40; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("3 - letra X com asteriscos.");
    for (i = 0; i < 48; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("4 - figuras aleatorias.");
    for (i = 0; i < 52; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 5; i++)
    {
        fputs(" ", stdout);
    }
    printf("5 - obra de arte.");
    for (i = 0; i < 58; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|           ");
    for (i = 0; i < 69; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");

    printf("|");
    for (i = 0; i < 80; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}