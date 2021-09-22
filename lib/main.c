typedef int bool;

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "global.h"

#include "modules/createMap.h"
#include "modules/playerMove.h"

int main()
{
    // Inicialização srand() com uma semente baseada no tempo
    // Geração de números aleatórios
    srand(time(0));

    createMap();

    if (playerMove() == END_GAME)
    {
        printf("Você venceu!");
    }

    // libera a memória da matriz
    for (size_t i = 0; i < rowsNumber; i++)
        free(map[i]);
    free(map);

    // map[playerCurrentPosition[X]][playerCurrentPosition[Y]] = LIVRE;

    return 0;
}
