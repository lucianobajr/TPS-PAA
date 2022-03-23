#ifndef QUADRO_H
#define QUADRO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

char **inicioQuadro(int Linha, int Coluna); 
char **CriaQuadro();                       
void print_frame(char **frame);             

void Asterisco(char **matriz, int quantidade);
void somaComAsterisco(char **matriz,int qtdFiguras);
void LetraX(char **matriz, int quantidade);
void randomico(char **matriz, int quantidade);
void obraDeArte(char **frame, int quantidade);

void obraDeArteStatic(char **frame, int quantidade);

int verificaEntrada(int tam);
void emotionOne(char **frame, int quantidade);
void emotionTwo(char **frame, int quantidade);
void emotionThree(char **frame, int quantidade);
void emotionFour(char **frame, int quantidade);
void emotionFive(char **frame, int quantidade);
void emotionSix(char **frame, int quantidade);
void emotionSeven(char **frame, int quantidade);
void emotionEight(char **frame, int quantidade);
void emotionNine(char **frame, int quantidade);
void emotionTen(char **frame, int quantidade);
void emotionEleven(char **frame, int quantidade);
void emotionTwelve(char **frame, int quantidade);

void insertEmotionOne(char **frame, int x, int y);
void insertEmotionTwo(char **frame, int x, int y);
void insertEmotionThree(char **frame, int x, int y);
void insertEmotionFour(char **frame, int x, int y);
void insertEmotionFive(char **frame, int x, int y);
void insertEmotionSix(char **frame, int x, int y);
void insertEmotionSeven(char **frame, int x, int y);
void insertEmotionEight(char **frame, int x, int y);
void insertEmotionNine(char **frame, int x, int y);
void insertEmotionTen(char **frame, int x, int y);
void insertEmotionEleven(char **frame, int x, int y);
void insertEmotionTwelve(char **frame, int x, int y);

#endif //QUADRO_H