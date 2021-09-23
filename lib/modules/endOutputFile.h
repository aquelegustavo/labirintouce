#ifndef END_OUTPUT_FILE_H
#define END_OUTPUT_FILE_H

#include <stdio.h>
#include <time.h>

#include "../global.h"

void endOutputFile(time_t startGameTime)
{

    fprintf(outputFile, "\n\n\n>> Informações gerais:\n\n");

    fprintf(outputFile, "Labirinto formado por %i linhas e %i colunas\n", rowsNumber, columnsNumber);
    fprintf(outputFile, "Jogador(a) bateu %i vez(es) na parede!\n", invalidMovesCounter);

    fprintf(outputFile, "\n");

    struct tm sgt = *localtime(&startGameTime);

    fprintf(outputFile, "Início do jogo: %02d/%02d/%d %02d:%02d:%02d\n",
            sgt.tm_mday,
            sgt.tm_mon + 1,
            sgt.tm_year + 1900,
            sgt.tm_hour,
            sgt.tm_min,
            sgt.tm_sec);

    time_t endGameTime = time(NULL);
    struct tm egt = *localtime(&endGameTime);

    fprintf(outputFile, "Fim do jogo: %02d/%02d/%d %02d:%02d:%02d\n",
            egt.tm_mday,
            egt.tm_mon + 1,
            egt.tm_year + 1900,
            egt.tm_hour,
            egt.tm_min,
            egt.tm_sec);

    fprintf(outputFile, "\n\n");
    fprintf(outputFile, "[FIM]");
    fprintf(outputFile, "\n\n\n\n");
}

#endif