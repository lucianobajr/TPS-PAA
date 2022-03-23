# TP01-PAA

Trabalho Prático 1 - Projeto e Análise de Algoritmos

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Lógica

- Inicia com nível de força `P` ⇒ localização inicial `@`
- Códigos ⇒ `-` (caminho horizontal), `|` caminho certical, `+` cruzamento, `.` não pode passar
- Cada caminho só pode ser percorrido uma única vez
- Os cruzamentos, no entanto, podem ser visitados mais de uma vez, desde que o caminho tomado em seguida seja diferente
- Os espaços onde se encontram inimigos ou o espaço inicial de Ness podem ser
  considerados cruzamentos.
- Inimigos ⇒ `U`,`T`,`S`,`B` ou `G`
- Cada inimigo tem força `P’`
- Quando ness vence a batalha ganha `X’`
- Só usa _PK Flash_ se sua força não pode derrotar o inimigo, além disse podemos usá-la `K` vezes

  ```c
  if(ness.p < enemies.atributes.p
  		&& ness.k > 0
  		&& strcmp(enemies.atributes.id, "G") == 0)
  )
  ```

- Entrada

  ![TP01-PAA](https://user-images.githubusercontent.com/45442173/153578541-cf187ec2-b9c2-4fbe-ba53-ecc2d2e96fee.png)

## A estruturação do projeto segue o esquema a seguir:

    ├── docs                       # documentação
    ├── dist                       # output
    ├── headers                    # Headers
    │   ├── menu.h
    │   ├── tst.h
    ├── src                       # Source
    │   ├── main.c                # Arquivo Principal
    │   ├── menu.c
    │   ├── tst.c
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
