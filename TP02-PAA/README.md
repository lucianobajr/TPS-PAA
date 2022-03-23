# TP2-PAA

Trabalho Prático 2 - Projeto e Análise de Algoritmos

## A estruturação do projeto segue o esquema a seguir:

    ├── docs                       # documentação
    ├── data                       # arquivos de entrada
    ├── dist                       # output
    ├── generator                  # gera mapas
    │   ├── generate.h
    │   ├── generate.c    
    ├── headers                    # Headers
    │   ├── menu.h
    │   ├── cave.h
    │   ├── samus.h
    │   ├── subproblems.h
    ├── src                       # Source
    │   ├── main.c                # Arquivo Principal
    │   ├── menu.c
    │   ├── cave.c
    │   ├── samus.c
    │   ├── subproblems.c
    ├── Makefile                  # Build Scripts
    │

## Compilar Trabalho

```sh
$   make
```

## Executar

```sh
$   make run
```

## Compilar Gerador de Mapas

```sh
$   make generate
```

## Executar Gerador de Mapas

```sh
$   make generate_run
```

## Excluir executável

```sh
$   make clean
```

## Excluir .exe

```sh
$   make clean_exec
```


## Lógica

- um algoritmo capaz de escolher um caminho que permita que Samus saia das cavernas em segurança no menor tempo possíve

- O mapa da caverna segue o padrão acima, sendo as áreas em amarelo as partes passáveis, e as áreas em marrom bloqueadas por rochas. As células com números indicam a presença de algum monstro. As setas ilustram caminhos possíveis.

- Samus se encontra no fundo da caverna (linha mais abaixo no desenho), e deve sempre se mover para cima, seja para a esquerda ou para direita. Ela pode começar a subir a partir de qualquer uma das células inferiores, e ela pode sair da caverna por qualquer uma das células superiores 

- A cada movimento que Samus realiza, ela gasta t unidades de tempo

- Cada vez que Samus encontra um monstro, representado por um número t' no mapa da caverna, ela gasta não apenas o tempo de se mover, mas também o tempo para enfrentar esse monstro (ou seja, t + t' ). 

- Por fim, a lava vai subindo na caverna nível a nível, ao longo de t L unidades de tempo, portanto, para saber se Samus vai chegar sã e salva por algum dos caminhos, é preciso saber se o tempo total T gasto para subir a caverna é igual ou inferior ao tempo que a lava gasta para preenchê-la, ou seja, T ≤ t L × h , sendo h a altura da caverna.

- O arquivo terá um formato padronizado, sendo que na primeira linha do arquivo temos, separados por espaços: a altura h da caverna, a largura w de cada nível da caverna, o tempo t que Samus gasta para realizar cada movimento, e o tempo que a lava gasta para subir cada nível da caverna, t<sub>L</sub>.