#include "../headers/ocurrence.h"

void exactMatch(message *prophecy)
{
  char *standard;
  standard = (char *)malloc(sizeof(char *) * 36);
  int size;

  printf("Qual o padrão utilizado?\n> ");
  scanf("%s", standard);

  search(preSearch(prophecy, &size), standard);
}

void approximateMatch(message *prophecy, key *prophecyKey)
{
  char *standard;
  standard = (char *)malloc(sizeof(char *) * 36);
  int size, k, standardsize;

  printf("Qual o padrão e a tolerância utilizados?\n> ");
  scanf("%s %d", standard, &k);
  standardsize = strlen(standard);

  if (k >= standardsize)
  {
    printf("k é maior ou igual ao padrão.\n");
  }

  char *textAux = preSearchDecrypted(prophecy, prophecyKey, &size);

  ShiftAndAproximado(textAux, size, standard, standardsize, k);
}

void ShiftAndAproximado(char *text, long n /*tamanho do texto*/, char *standard, long m /*tamanho do padrao*/, long k /*margem de erro*/)
{
  long Masc[256], i, j, Ri, Rant, Rnovo;
  long R[10 + 1];

  int cont = 0;
  int posicaoinicial, posicaofinal;

  for (i = 0; i < 256; i++)
    Masc[i] = 0;

  for (i = 1; i <= m; i++)
  {
    Masc[standard[i - 1] + 127] |= 1 << (m - i);
  }

  R[0] = 0;
  Ri = 1 << (m - 1);

  for (j = 1; j <= k; j++)
    R[j] = (1 << (m - j)) | R[j - 1];

  for (i = 0; i < n; i++)
  {
    Rant = R[0];
    Rnovo = ((((unsigned long)Rant) >> 1) | Ri) & Masc[text[i] + 127];
    R[0] = Rnovo;

    for (j = 1; j <= k; j++)
    {

      Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[text[i] + 127]) | Rant | (((unsigned long)(Rant | Rnovo)) >> 1);
      Rant = R[j];
      R[j] = Rnovo | Ri;
    }

    if ((Rnovo & 1) != 0)
    {
      cont++;
      posicaofinal = i + 1;
      posicaoinicial = posicaofinal - strlen(standard);
    }
  }

  printf("Ocorrencias: %d\n", cont);

  if (cont != 0)
  {
    printf("@[%d %d): ", posicaoinicial, posicaofinal);
    for (int i = posicaoinicial; i <= posicaofinal; i++)
    {
      printf("%c", text[i]);
    }
  }
}

int max(int a, int b) { return (a > b) ? a : b; }

// A função de pré-processamento para a heurística
void badCharHeuristic(char *str, int size, int badchar[256])
{
  int i;

  // Inicializa todas as ocorrências como -1
  for (i = 0; i < 256; i++)
    badchar[i] = -1;

  // Preenche o valor real da última ocorrência
  // de uma letra
  for (i = 0; i < size; i++)
    badchar[(int)str[i]] = i;
}

/* Uma função de busca de padrões que usa Heurística
     de caracteres do algoritmo Boyer Moore */
void search(char *txt, char *pat)
{
  int m = strlen(pat);
  int n = strlen(txt);

  int total = 0;

  int badchar[256];

  /* Preencha a matriz de caracteres inválidos chamando
      a função de pré-processamento badCharHeuristic()
      para determinado padrão */
  badCharHeuristic(pat, m, badchar);

  int s = 0; // s é o deslocamento do padrão com
             // respeito ao texto
  while (s <= (n - m))
  {
    int j = m - 1;

    /* Continue reduzindo o índice j do padrão enquanto
        caracteres de padrão e texto são
        correspondência neste turno s */
    while (j >= 0 && pat[j] == txt[s + j])
      j--;

    /* Se o padrão estiver presente na corrente
        shift, então o índice j se tornará -1 após
        o laço acima */
    if (j < 0)
    {
      total++;

      // printf("\nocorre de padrão em = %d", s);

      /* Mude o padrão para que o próximo
          caractere no texto se alinha com o último
          ocorrência dele no padrão.
          A condição s+m < n é necessária para
          o caso em que o padrão ocorre no final
          de texto */
      s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
    }

    else
      /* Mude o padrão para que o personagem ruim
          no texto se alinha com a última ocorrência de
          isso no padrão. A função max é usada para
          certifique-se de que temos uma mudança positiva.
          Podemos obter um deslocamento negativo se o último
          ocorrência de mau caráter no padrão
          está do lado direito da corrente
          personagem. */
      s += max(1, j - badchar[txt[s + j]]);
  }

  printf("\nOcorrências: %d", total);
}

char *preSearch(message *prophecy, int *size)
{
  int totalOfLetters = totalLetters(prophecy);
  int totalSpaceWords = 0, total = 0;

  for (int i = 0; i < prophecy->size; i++)
  {
    totalSpaceWords += prophecy->phrases[i].size;
  }

  total = (totalSpaceWords - 1) + totalOfLetters;

  char *text;
  text = (char *)malloc(sizeof(char *) * total);

  int count = 0;

  for (int i = 0; i < prophecy->size; i++)
  {
    for (int ii = 0; ii < prophecy->phrases[i].size; ii++)
    {
      for (int iii = 0; iii < prophecy->phrases[i].words[ii].size; iii++)
      {
        text[count] = prophecy->phrases[i].words[ii].letters[iii].letter;
        count++;
      }
      text[count] = ' ';
      count++;
    }
  }

  *size = count;

  return text;
}

char *preSearchDecrypted(message *prophecy, key *prophecyKey, int *size)
{
  int totalOfLetters = totalLetters(prophecy);
  int totalSpaceWords = 0, total = 0;

  for (int i = 0; i < prophecy->size; i++)
  {
    totalSpaceWords += prophecy->phrases[i].size;
  }

  total = (totalSpaceWords - 1) + totalOfLetters;

  char *text;
  text = (char *)malloc(sizeof(char *) * total);

  int count = 0;

  for (int i = 0; i < prophecy->size; i++)
  {
    for (int ii = 0; ii < prophecy->phrases[i].size; ii++)
    {
      for (int iii = 0; iii < prophecy->phrases[i].words[ii].size; iii++)
      {
        if (positionOfLetterInKey(prophecyKey, prophecy->phrases[i].words[ii].letters[iii].letter) != -1)
        {
          text[count] = 65 + positionOfLetterInKey(prophecyKey, prophecy->phrases[i].words[ii].letters[iii].letter);
        }
        else
        {
          text[count] = prophecy->phrases[i].words[ii].letters[iii].letter;
        }
        count++;
      }
      text[count] = ' ';
      count++;
    }
  }

  *size = count;

  return text;
}