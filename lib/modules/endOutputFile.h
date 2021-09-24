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
 * Finaliza o relatório que é disponibilizado ao usuário no final do jogo.
 * 
 * METÓDO GERAL:
 * Adiciona ao arquivo output.txt o horário de início e termino da partida 
 * e a quantidade de vezes que o usuário realizou movimentos inválidos.
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdio.h
 * time.h
 * global.h
 */
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
