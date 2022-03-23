# TP3-PAA

Trabalho Prático 3 - Projeto e Análise de Algoritmos

## A estruturação do projeto segue o esquema a seguir:

    ├── colors                     # gera 256 cores diferentes
    ├── docs                       # documentação
    ├── data                       # arquivos de entrada
    ├── dist                       # output
    ├── language                   # arquivos .txt com tabelas de frequencia
    │   ├── en-US.txt
    │   ├── pt-BR.txt
    ├── headers                    # Headers
    │   ├── crypto.h
    │   ├── key.h
    │   ├── frequency.h
    │   ├── menu.h
    │   ├── message.h
    │   ├── ocurrence.h
    │   ├── phrase.h
    │   ├── word.h
    ├── out                       # arquivos .txt de saida com texto descriptografado e chave
    │   ├── key.txt
    │   ├── prophecy.txt
    ├── src                       # Source
    │   ├── crypto.c
    │   ├── frequency.c
    │   ├── key.h
    │   ├── main.c                # Arquivo Principal
    │   ├── menu.c
    │   ├── message.c
    │   ├── ocurrence.c
    │   ├── phrase.c
    │   ├── word.c
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

## Excluir executável

```sh
$   make clean
```

## Excluir .exe

```sh
$   make clean_exec
```