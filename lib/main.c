#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "global.h"
#include "modules/printGameHeader.h"
#include "modules/createMap.h"
#include "modules/playerMove.h"
#include "modules/endOutputFile.h"

int main()
{
    // Geração de números aleatórios
    // Inicialização srand() com uma semente baseada no tempo
    srand(time(0));

    time_t startGameTime = time(NULL);

    outputFile = fopen("output.txt", "a");

    system(LIMPARTELA);

    fprintf(outputFile,
            "-----------------"
            " LABIRINTOUCE: O JOGO DO LABIRINTO "
            "-----------------\n");

    if (outputFile == NULL)
    {
        printf(RED "\nNão foi possível criar o arquivo!\n" RESET);
        exit(EXIT_FAILURE);
    }

    printGameHeader();
    createMap();

    if (playerMove() == END_GAME)
    {
        printf(GREEN "\nParabéns! Você venceu!\n" RESET);
        printf("Acesse o arquivo " YELLOW "./output.txt" RESET " para ver seu histórico no jogo.\n\n");

        fprintf(outputFile, "Jogador(a) venceu o jogo!");
    }

    // libera a memória da matriz
    for (size_t i = 0; i < rowsNumber; i++)
        free(map[i]);
    free(map);

    endOutputFile(startGameTime);

    return 0;
}
