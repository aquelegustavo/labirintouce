/**
 * ARQUIVO: lib/utils/checkMove.h
 * 
 * TÍTULO: RELATÓRIO DE TRABALHO DE LABORATÓRIO 2
 * ENVIADO POR: Gustavo Simões e Izabelle Custodia Teixeira Sebastiao.            
 *              Todo o código tem como autores Gustavo Simões e Izabelle C. T. Sebastião.
 * 
 * CURSO: Linguagem de progrmação 1 do curso de Enhenharia de Computação da UFSC
 * DATA: 04/09/21 
 * 
 *
 * PROPÓSITO:
 * Este cabeçalho (.h) tem como objetivo verificar se o movimento do jogador é valido,
 * ou seja, verifica se o movimento coincide com uma parede (*\|).
 * 
 * METÓDO GERAL:
 * Verifica se o movimento de interesse do jogado coincide com uma parede (*) ou
 * limite do mapa (|) e tem como retorno um número boleano.  
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdio.h
 * tdbool.h
 * global.h

#ifndef CHECK_MOVE_H
#define CHECK_MOVE_H

#include <stdio.h>
#include <stdbool.h>

#include "../global.h"

bool checkMove(int *possibleMove)
{

    if (possibleMove[X] == rowsNumber ||
        possibleMove[X] == -1 ||
        possibleMove[Y] == columnsNumber ||
        possibleMove[Y] == -1 ||
        map[possibleMove[X]][possibleMove[Y]] == BLOCO)
    {
        // move é inválido

        if (DEBUG_MODE)
        {
            printf("(%i, %i) É UM BLOCO! \n"
                   "Valor map: % i ",
                   playerCurrentPosition[X],
                   playerCurrentPosition[Y],
                   map[playerCurrentPosition[X]][playerCurrentPosition[Y]]);
        }

        return false;
    }
    else
    {
        return true;
    }
}

#endif
