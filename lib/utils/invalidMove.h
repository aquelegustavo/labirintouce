#ifndef INVALID_MOVE_H
#define INVALID_MOVE_H

#include <stdio.h>
#include "../global.h"
#include "getRandom.h"

void invalidMove()
{
    fprintf(outputFile, "Jogador(a) bateu na parede!\n");
    invalidMovesCounter++;

    switch (getRandom(0, 3))
    {
    case 0:
        printf(RED "\n\nOps.. ali não =)\n" RESET);
        break;
    case 1:
        printf(RED "\n\nIhhh bateu na parede!\n" RESET);
        break;
    case 2:
        printf(RED "\n\nPOWWW (você não pode ir por ai)\n" RESET);
        break;
    case 3:
        printf(RED "\n\nEi!! Tentre outro caminho, esse é uma parede!\n" RESET);
        break;
    }
}

#endif