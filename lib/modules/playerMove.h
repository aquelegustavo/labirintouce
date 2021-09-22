#ifndef PLAYER_MOVE_H
#define PLAYER_MOVE_H

typedef int bool;

#include <stdio.h>
#include "../global.h"
#include "../utils/checkMove.h"
#include "../utils/drawMap.h"

struct possibleMoves
{
    int w[2], s[2], d[2], a[2];
};
struct possibleMoves possibleMove;

int playerMove()
{

    char move;
    while ((move != 'x') && (move != 'X'))
    {

        system(LIMPARTELA);
        drawMap();

        if (playerCurrentPosition[X] == (rowsNumber - 1))
        {
            return END_GAME;
        }

        // Mostrar direções
        printf("\n\n  (W)\n(A)+(D)\n  (S)\n\n");

        if (DEBUG_MODE)
        {
            printf(GREEN "Posição do player: (%i, %i)\n\n" RESET, playerCurrentPosition[X], playerCurrentPosition[Y]);
        }

        possibleMove.w[X] = (playerCurrentPosition[X] - 1);
        possibleMove.w[Y] = playerCurrentPosition[Y];

        possibleMove.s[X] = (playerCurrentPosition[X] + 1);
        possibleMove.s[Y] = playerCurrentPosition[Y];

        possibleMove.d[X] = playerCurrentPosition[X];
        possibleMove.d[Y] = (playerCurrentPosition[Y] + 1);

        possibleMove.a[X] = playerCurrentPosition[X];
        possibleMove.a[Y] = (playerCurrentPosition[Y] - 1);

        if ((scanf("%c", &move)) == 0)
        {
            printf("mensagem de erro..\n");
            getchar();
            getchar();
        }
        if ((move == 'w') || (move == 'W'))
        {
            if (checkMove(possibleMove.w))
            {
                playerCurrentPosition[X] = (playerCurrentPosition[X] - 1);
            }
            else
            {
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }
        if ((move == 's') || (move == 'S'))
        {

            if (checkMove(possibleMove.s))
            {
                playerCurrentPosition[X] = playerCurrentPosition[X] + 1;
            }
            else
            {
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }
        if ((move == 'd') || (move == 'D'))
        {

            if (checkMove(possibleMove.d))
            {
                playerCurrentPosition[Y] = playerCurrentPosition[Y] + 1;
            }
            else
            {
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }
        if ((move == 'a') || (move == 'A'))
        {

            if (checkMove(possibleMove.a))
            {
                playerCurrentPosition[Y] = playerCurrentPosition[Y] - 1;
            }
            else
            {
                printf("\n\nups.. ali não =)\n");
                getchar();
                getchar();
            }
        }

        //map[playerCurrentPosition[X]][playerCurrentPosition[Y]] = PLAYER;
    }
    return OK;
}

#endif
