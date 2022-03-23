#include "../headers/quadro.h"

//malloc para iniciar um quadro
char **inicioQuadro(int Linha, int Coluna)
{
    int i, j;
    char **Quadro = (char **)malloc(Linha * sizeof(char *));
    for (i = 0; i < Linha; i++)
    {
        Quadro[i] = (char *)malloc(Coluna * sizeof(char));

        for (j = 0; j < Coluna; j++)
        {
            Quadro[i][j] = ' ';
        }
    }
    return Quadro;
}

//função para criar um quadro em branco usando a função inicoQuadro
char **CriaQuadro()
{
    int Linha = 20, Coluna = 80, i, j;
    char **Quadro = inicioQuadro(Linha, Coluna);
    for (i = 0; i < Linha; i++)
    {
        for (j = 0; j < Coluna; j++)
        {
            if (i == 0 || i == (Linha - 1))
            { //primeira e última linha recebendo '-'
                Quadro[i][j] = '-';
            }
            //primeira e última coluna recbendo '|'
            else if (j == 0 || j == (Coluna - 1))
            {
                Quadro[i][j] = '|';
            }
            else
            {
                Quadro[i][j] = ' ';
            }
        }
    }
    return Quadro;
}

void print_frame(char **frame)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            printf("%c", frame[i][j]);
        }
        printf("\n");
    }
}

int verificaEntrada(int tam)
{
    if (tam > 100)
    {
        return 100;
    }
    else if (tam <= 0)
    {
        return rand() % 99;
    }
    else
    {
        return tam;
    }
}

void Asterisco(char **matriz, int quantidade)
{

    int x, y;

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {

            x = 1 + rand() % 18;
            y = 1 + rand() % 78;

            if (matriz[x][y] == ' ')
            {
                break;
            }
        }
        matriz[x][y] = '*';
    }
}

void somaComAsterisco(char **matriz, int qtdFiguras)
{
    int x, y;

    for (int i = 0; i < qtdFiguras; i++)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;
            if (matriz[x][y] == ' ' && matriz[x + 1][y] == ' ' && matriz[x - 1][y] == ' ' && matriz[x][y + 1] == ' ' && matriz[x][y - 1] == ' ')
                break;
        }
        matriz[x][y] = '*';
        matriz[x + 1][y] = '*';
        matriz[x - 1][y] = '*';
        matriz[x][y + 1] = '*';
        matriz[x][y - 1] = '*';
    }
}

void LetraX(char **matriz, int quantidade)
{
    int x, y;

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (matriz[x][y] == ' ' && matriz[x + 1][y + 1] == ' ' && matriz[x - 1][y - 1] == ' ' && matriz[x + 1][y - 1] == ' ' && matriz[x - 1][y + 1] == ' ')
            {
                break;
            }
        }
        matriz[x][y] = '*';
        matriz[x + 1][y + 1] = '*';
        matriz[x - 1][y - 1] = '*';
        matriz[x - 1][y + 1] = '*';
        matriz[x + 1][y - 1] = '*';
    }
}

void randomico(char **matriz, int quantidade)
{
    srand(time(0));
    int sizes[3], options[3];
    do
    {
        options[0] = rand() % 3;
        options[1] = rand() % 3;
        options[2] = rand() % 3;

    } while (options[0] == options[1] || options[0] == options[2] || options[1] == options[2]);

    sizes[0] = rand() % quantidade;
    sizes[1] = rand() % (quantidade - sizes[0]);
    sizes[2] = quantidade - (sizes[0] + sizes[1]);

    switch (options[0])
    {
    case 0:
        Asterisco(matriz, sizes[0]);
        if (options[1] == 1)
        {
            somaComAsterisco(matriz, sizes[1]);
            LetraX(matriz, sizes[2]);
        }
        else
        {
            LetraX(matriz, sizes[1]);
            somaComAsterisco(matriz, sizes[2]);
        }
        break;
    case 1:
        somaComAsterisco(matriz, sizes[0]);
        if (options[1] == 0)
        {
            Asterisco(matriz, sizes[1]);
            LetraX(matriz, sizes[2]);
        }
        else
        {
            LetraX(matriz, sizes[1]);
            Asterisco(matriz, sizes[2]);
        }
        break;
    case 2:
        LetraX(matriz, sizes[0]);
        if (options[1] == 0)
        {
            Asterisco(matriz, sizes[1]);
            somaComAsterisco(matriz, sizes[2]);
        }
        else
        {
            somaComAsterisco(matriz, sizes[1]);
            Asterisco(matriz, sizes[2]);
        }
        break;
    default:
        break;
    }
}

void obraDeArte(char **frame, int quantidade)
{
    srand(time(0));
    int sizes[3], options[3];
    do
    {
        options[0] = rand() % 3;
        options[1] = rand() % 3;
        options[2] = rand() % 3;

    } while (options[0] == options[1] || options[0] == options[2] || options[1] == options[2]);

    sizes[0] = rand() % quantidade;
    sizes[1] = rand() % (quantidade - sizes[0]);
    sizes[2] = quantidade - (sizes[0] + sizes[1]);

    switch (options[0])
    {
    case 0:
        emotionOne(frame, sizes[0]);
        if (options[1] == 1)
        {
            emotionTwo(frame, sizes[1]);
            emotionThree(frame, sizes[2]);
        }
        else
        {
            emotionThree(frame, sizes[1]);
            emotionTwo(frame, sizes[2]);
        }
        break;
    case 1:
        emotionTwo(frame, sizes[0]);
        if (options[1] == 0)
        {
            emotionOne(frame, sizes[1]);
            emotionThree(frame, sizes[2]);
        }
        else
        {
            emotionThree(frame, sizes[1]);
            emotionOne(frame, sizes[2]);
        }
        break;
    case 2:
        emotionThree(frame, sizes[0]);
        if (options[1] == 0)
        {
            emotionOne(frame, sizes[1]);
            emotionTwo(frame, sizes[2]);
        }
        else
        {
            emotionTwo(frame, sizes[1]);
            emotionOne(frame, sizes[2]);
        }
        break;
    default:
        break;
    }
}

//30*13
void emotionOne(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ')
            {
                break;
            }
        }
        insertEmotionOne(frame, x, y);
    }
}

void insertEmotionOne(char **frame, int x, int y)
{

    /*~(^-^)~*/
    frame[x][y] = '~';
    frame[x][y + 1] = '(';
    frame[x][y + 2] = '^';
    frame[x][y + 3] = '-';
    frame[x][y + 4] = '^';
    frame[x][y + 5] = ')';
    frame[x][y + 6] = '~';
};

void emotionTwo(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ')
            {
                break;
            }
        }
        insertEmotionTwo(frame, x, y);
    }
}

void insertEmotionTwo(char **frame, int x, int y)
{

    /*（ ^_^）*/
    frame[x][y] = '(';
    frame[x][y + 1] = ' ';
    frame[x][y + 2] = '^';
    frame[x][y + 3] = '_';
    frame[x][y + 4] = '^';
    frame[x][y + 5] = ')';
}

void emotionThree(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ' && frame[x][y + 7] == ' ' && frame[x][y + 8] == ' ')
            {
                break;
            }
        }
        insertEmotionThree(frame, x, y);
    }
}

void insertEmotionThree(char **frame, int x, int y)
{
    /*<( ^.^ )>*/
    frame[x][y] = '<';
    frame[x][y + 1] = '(';
    frame[x][y + 2] = ' ';
    frame[x][y + 3] = '^';
    frame[x][y + 4] = '.';
    frame[x][y + 5] = '^';
    frame[x][y + 6] = ' ';
    frame[x][y + 7] = ')';
    frame[x][y + 8] = '>';
}

void emotionFour(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ')
            {
                break;
            }
        }
        insertEmotionFour(frame, x, y);
    }
}

void insertEmotionFour(char **frame, int x, int y)
{
    /*0_o*/
    frame[x][y] = '0';
    frame[x][y + 1] = '_';
    frame[x][y + 2] = 'o';
}

void emotionFive(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ')
            {
                break;
            }
        }
        insertEmotionFive(frame, x, y);
    }
}

void insertEmotionFive(char **frame, int x, int y)
{
    /*<(^^<)*/
    frame[x][y] = '<';
    frame[x][y + 1] = '(';
    frame[x][y + 2] = '^';
    frame[x][y + 3] = '^';
    frame[x][y + 4] = '<';
    frame[x][y + 5] = ')';
}

void emotionSix(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ')
            {
                break;
            }
        }
        insertEmotionSix(frame, x, y);
    }
}

void insertEmotionSix(char **frame, int x, int y)
{
    /*<(o_o<)*/
    frame[x][y] = '<';
    frame[x][y + 1] = '(';
    frame[x][y + 2] = 'o';
    frame[x][y + 3] = '_';
    frame[x][y + 4] = 'o';
    frame[x][y + 5] = '<';
    frame[x][y + 6] = ')';
}

void emotionSeven(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ' && frame[x][y + 7] == ' ' && frame[x][y + 8] == ' ' && frame[x][y + 9] == ' ' && frame[x][y + 10] == ' ')
            {
                break;
            }
        }
        insertEmotionSeven(frame, x, y);
    }
}

void insertEmotionSeven(char **frame, int x, int y)
{
    /*<( -'.'- )>*/
    frame[x][y] = '<';
    frame[x][y + 1] = '(';
    frame[x][y + 2] = ' ';
    frame[x][y + 3] = '-';
    frame[x][y + 4] = '\'';
    frame[x][y + 5] = '.';
    frame[x][y + 6] = '\'';
    frame[x][y + 7] = '-';
    frame[x][y + 8] = ' ';
    frame[x][y + 9] = ')';
    frame[x][y + 10] = '>';
}

void emotionEight(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ' && frame[x][y + 7] == ' ')
            {
                break;
            }
        }
        insertEmotionEight(frame, x, y);
    }
}

void insertEmotionEight(char **frame, int x, int y)
{
    /*<('.'-^)*/
    frame[x][y] = '<';
    frame[x][y + 1] = '(';
    frame[x][y + 2] = '\'';
    frame[x][y + 3] = '.';
    frame[x][y + 4] = '\'';
    frame[x][y + 5] = '-';
    frame[x][y + 6] = '^';
    frame[x][y + 7] = ')';
}

void emotionNine(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ' && frame[x][y + 7] == ' ' && frame[x][y + 8] == ' ')
            {
                break;
            }
        }
        insertEmotionNine(frame, x, y);
    }
}

void insertEmotionNine(char **frame, int x, int y)
{
    /*(>';..;')>*/
    frame[x][y] = '(';
    frame[x][y + 1] = '>';
    frame[x][y + 2] = '\'';
    frame[x][y + 3] = ';';
    frame[x][y + 4] = '.';
    frame[x][y + 5] = '.';
    frame[x][y + 6] = ';';
    frame[x][y + 7] = ')';
    frame[x][y + 8] = '>';
}

void emotionTen(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ')
            {
                break;
            }
        }
        insertEmotionTen(frame, x, y);
    }
}

void insertEmotionTen(char **frame, int x, int y)
{
    /*(-_-;)*/
    frame[x][y] = '(';
    frame[x][y + 1] = '-';
    frame[x][y + 2] = '_';
    frame[x][y + 3] = '-';
    frame[x][y + 4] = ';';
    frame[x][y + 5] = ')';
}

void emotionEleven(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ')
            {
                break;
            }
        }
        insertEmotionEleven(frame, x, y);
    }
}

void insertEmotionEleven(char **frame, int x, int y)
{
    /*(^o^;*/
    frame[x][y] = '(';
    frame[x][y + 1] = '^';
    frame[x][y + 2] = 'o';
    frame[x][y + 3] = '^';
    frame[x][y + 4] = ';';
}

void emotionTwelve(char **frame, int quantidade)
{
    int x, y;
    srand(time(0));

    for (int i = 0; i < quantidade; ++i)
    {
        while (1)
        {
            x = 1 + rand() % 17;
            y = 1 + rand() % 77;

            if (frame[x][y] == ' ' && frame[x][y + 1] == ' ' && frame[x][y + 2] == ' ' && frame[x][y + 3] == ' ' && frame[x][y + 4] == ' ' && frame[x][y + 5] == ' ' && frame[x][y + 6] == ' ')
            {
                break;
            }
        }
        insertEmotionTwelve(frame, x, y);
    }
}

void insertEmotionTwelve(char **frame, int x, int y)
{
    /*(#^.^#)*/
    frame[x][y] = '(';
    frame[x][y + 1] = '#';
    frame[x][y + 2] = '^';
    frame[x][y + 3] = '.';
    frame[x][y + 4] = '^';
    frame[x][y + 5] = '#';
    frame[x][y + 6] = ')';
}

void obraDeArteStatic(char **frame, int quantidade)
{
    srand(time(0));
    int sizes[4], options[4];
    do
    {
        options[0] = rand() % 10;
        options[1] = rand() % 10;
        options[2] = rand() % 10;
        options[3] = rand() % 10;
    } while (options[0] == options[1] || options[0] == options[2] || options[0] == options[3] || options[1] == options[2] || options[1] == options[3] || options[2] == options[3]);

    sizes[0] = rand() % quantidade;
    sizes[1] = rand() % (quantidade - sizes[0]);
    sizes[2] = rand() % (quantidade - (sizes[0] + sizes[1]));
    sizes[3] = quantidade - (sizes[0] + sizes[1] + sizes[2]);

    for (int i = 0; i < 4; i++)
    {
        switch (options[i])
        {
        case 0:
            emotionOne(frame, sizes[i]);
            break;
        case 1:
            emotionTwo(frame, sizes[i]);
            break;
        case 2:
            emotionThree(frame, sizes[i]);
            break;
        case 3:
            emotionFour(frame, sizes[i]);
            break;
        case 4:
            emotionFive(frame, sizes[i]);
            break;
        case 5:
            emotionSix(frame, sizes[i]);
            break;
        case 6:
            emotionSeven(frame, sizes[i]);
            break;
        case 7:
            emotionEight(frame, sizes[i]);
            break;
        case 8:
            emotionNine(frame, sizes[i]);
            break;
        case 9:
            emotionTen(frame, sizes[i]);
            break;
        case 10:
            emotionEleven(frame, sizes[i]);
            break;
        case 11:
            emotionTwelve(frame, sizes[i]);
            break;
        default:
            break;
        }
    }
}

/*

    ~(^-^)~
    （ ^_^）
    <( ^.^ )>
    0_o
    <(^^<)
    <(o_o<)
    <( -'.'- )>
    <('.'-^)
    (>';..;')>
    (-_-;)
    (^o^;
    (#^.^#)
    
*/