/**
 * ARQUIVO: lib/utils/drawMap.h
 * 
 * TÍTULO: RELATÓRIO DE TRABALHO DE LABORATÓRIO 2
 * ENVIADO POR: Gustavo Simões e Izabelle Custodia Teixeira Sebastiao.            
 *              Todo o código tem como autores Gustavo Simões e Izabelle C. T. Sebastião.
 * 
 * CURSO: Linguagem de progrmação 1 do curso de Enhenharia de Computação da UFSC
 * DATA: 04/09/21 
 * 
 * PROPÓSITO:
 * Este codigo tem como objetivo desenhar mapa do jogo.
 * 
 * METÓDO GERAL:
 * Imprime na tela o caracter referente ao valor da posição (x, y) 
 * na matriz global.
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdib.h
 * global.h
 */
#ifndef DRAW_MAP_H
#define DRAW_MAP_H

#include <stdio.h>

#include "../global.h"

void drawMap()
{
    for (size_t row = 0; row < rowsNumber; row++)
    {
        printf("|");
        for (size_t column = 0; column < columnsNumber; column++)
        {
            if (DEBUG_MODE)
            {
                printf(GREEN " | %zux%zu (%i) " RESET, row, column, map[row][column]);
            }

            if (playerCurrentPosition[X] == row && playerCurrentPosition[Y] == column)
            {
                printf(YELLOW "@" RESET);
            }
            else
            {
                switch (map[row][column])
                {
                    // case PLAYER:
                    //   printf(YELLOW "@" RESET);
                    // break;
                case LIVRE:
                    printf(" ");
                    break;
                case BLOCO:
                    printf("*");
                    break;

                case DEBUG:
                    printf(RED "#" RESET);
                    break;
                default:
                    printf(RED "ERRO!" RESET);
                    break;
                }
            }
        }
        printf("|\n");
    }
}

#endif
