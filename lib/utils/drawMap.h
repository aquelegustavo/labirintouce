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