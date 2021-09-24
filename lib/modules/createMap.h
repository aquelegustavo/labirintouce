/**
 * ARQUIVO: lib/modules/createMap.h
 * 
 * TÍTULO: RELATÓRIO DE TRABALHO DE LABORATÓRIO 2
 * ENVIADO POR: Gustavo Simões e Izabelle Custodia Teixeira Sebastiao.            
 *              Todo o código tem como autores Gustavo Simões e Izabelle C. T. Sebastião.
 * 
 * CURSO: Linguagem de progrmação 1 do curso de Enhenharia de Computação da UFSC
 * DATA: 04/09/21 
 * 
 * PROPÓSITO:
 * A crição de um mapa aleatorio em cada partida do jogo, sempre havendo um caminho 
 * possivel para chegar no fim do labirinto.
 *
 * METÓDO GERAL:
 * Criação de uma matriz com valores aleatórios que consiste no mapa do jogo. 
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdio.h
 * global.h
 */
#ifndef CREATE_MAP_H
#define CREATE_MAP_H

#include <stdio.h>

#include "../global.h"

int *getNextBoardPosition(int lastBoard[]);
void createMap()
{
    rowsNumber = getRandom(MIN_NUMBER, MAX_NUMBER);
    columnsNumber = getRandom(MIN_NUMBER, MAX_NUMBER);

    // aloca um vetor de LIN ponteiros para linhas
    map = malloc(rowsNumber * sizeof(int *));

    // aloca cada uma das linhas (vetores de COL inteiros)
    for (size_t i = 0; i < rowsNumber; i++)
    {
        map[i] = malloc(columnsNumber * sizeof(int));
    }

    if (DEBUG_MODE)
    {
        printf("Número de linhas: %i \nNúmero de colunas: %i\n\n\n", rowsNumber, columnsNumber);
    }
    // Para cada linha no mapa
    for (size_t row = 0; row < rowsNumber; row++)
    {
        // Para cada coluna no mapa
        for (size_t column = 0; column < columnsNumber; column++)
        {
            // A casa atual (linha, coluna) recebe um valor entre 0 e 1
            // 0 ---> livre
            // 1 ---> parede
            map[row][column] = getRandom(0, 1);
        }
    }

    int firstColumn = getRandom(0, (columnsNumber - 1));

    playerCurrentPosition[Y] = firstColumn;

    int *lastBoard;
    int *currentBoard;

    lastBoard = (int[]){0, firstColumn};
    currentBoard = (int[]){0, firstColumn};

    while (currentBoard[X] < rowsNumber)
    {
        currentBoard = getNextBoardPosition(lastBoard);

        if (!(currentBoard[X] == rowsNumber))
        {

            if (DEBUG_MODE)
            {
                printf("X: %i, Y: %i\n", currentBoard[X], currentBoard[Y]);
            }

            map[currentBoard[X]][currentBoard[Y]] = DEBUG_MODE ? DEBUG : LIVRE;
        }

        lastBoard = currentBoard;
    }
}
int *getNextBoardPosition(int lastBoard[])
{

    int *p;

    if (lastBoard[X] == 0)
    {

        if (lastBoard[Y] == 0)
        {
            p = (int[]){/*length:*/ 2, /*values:*/ LESTE, SUL};
        }
        else if (lastBoard[Y] == columnsNumber)
        {
            p = (int[]){/*length:*/ 2, /*values:*/ OESTE, SUL};
        }
        else
        {
            p = (int[]){/*length:*/ 3, /*values:*/ LESTE, OESTE, SUL};
        }
    }
    else if (lastBoard[X] == rowsNumber)
    {
        // Ultima linha
    }
    else if (lastBoard[Y] == 0)
    {
        p = (int[]){/*length:*/ 2, /*values:*/ LESTE, SUL};
    }
    else if (lastBoard[Y] == (columnsNumber - 1))
    {
        p = (int[]){/*length:*/ 2, /*values:*/ OESTE, SUL};
    }
    else
    {
        p = (int[]){/*length:*/ 3, /*values:*/ LESTE, OESTE, SUL};
    }

    int *nextBoard;

    if (DEBUG_MODE)
    {
        printf("ESCOLHA: %i\n", getRandom(1, p[0]));
    }
    switch (p[getRandom(1, p[0])])
    {

    case LESTE:
        nextBoard = (int[]){lastBoard[X], (lastBoard[Y] + 1)};
        break;
    case SUL:
        nextBoard = (int[]){(lastBoard[X] + 1), lastBoard[Y]};
        break;
    case OESTE:
        nextBoard = (int[]){lastBoard[X], (lastBoard[Y] - 1)};
        break;
    }

    return nextBoard;
}

#endif
