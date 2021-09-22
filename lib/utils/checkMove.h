#ifndef CHECK_MOVE_H
#define CHECK_MOVE_H

#include <stdio.h>

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