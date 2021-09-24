/**
 * ARQUIVO: lib/modules/playerMove.h
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
 * Esse código tem como objetivo executar toda a movimentação do(a) jogador(a).
 * 
 * MÉTODO GERAL:
 * Código observa a insersão do usuário via teclado, verifica se o movimento é 
 * válido e, então, reescreve o mapa com a nova posição do usuário.
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdio.h
 * global.h
 * checkMove.h
 * drawMap.h
 * invalidMove.h
 */

#ifndef PLAYER_MOVE_H
#define PLAYER_MOVE_H

#include <stdio.h>

#include "../global.h"
#include "../utils/checkMove.h"
#include "../utils/drawMap.h"
#include "../utils/invalidMove.h"

struct possibleMoves
{
    int w[2], s[2], d[2], a[2];
};
struct possibleMoves possibleMove;

int playerMove()
{
    fprintf(outputFile, "\n>> Histórico de jogadas:\n\n");

    char move;
    // Enquanto o usuário não vencer o jogo ou
    // pressionar 'X' este módulo segue em execução.
    while ((move != 'x') && (move != 'X'))
    {

        system(LIMPARTELA);
        drawMap();

        if (playerCurrentPosition[X] == (rowsNumber - 1))
        {
            return END_GAME;
        }

        // Mostrar direções
        printf(YELLOW "\n\n  (W)\n(A)+(D)\n  (S)\n\n" RESET);

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
                fprintf(outputFile, "Jogador(a) foi para cima (W)\n");
            }
            else
            {
                invalidMove();
                getchar();
                getchar();
            }
        }
        if ((move == 's') || (move == 'S'))
        {

            if (checkMove(possibleMove.s))
            {
                playerCurrentPosition[X] = playerCurrentPosition[X] + 1;
                fprintf(outputFile, "Jogador(a) foi para baixo (S)\n");
            }
            else
            {
                invalidMove();
                getchar();
                getchar();
            }
        }
        if ((move == 'd') || (move == 'D'))
        {

            if (checkMove(possibleMove.d))
            {
                playerCurrentPosition[Y] = playerCurrentPosition[Y] + 1;
                fprintf(outputFile, "Jogador(a) foi para a direita (D)\n");
            }
            else
            {
                invalidMove();
                getchar();
                getchar();
            }
        }
        if ((move == 'a') || (move == 'A'))
        {

            if (checkMove(possibleMove.a))
            {
                playerCurrentPosition[Y] = playerCurrentPosition[Y] - 1;
                fprintf(outputFile, "Jogador(a) foi para a esquerda <3 (A)\n");
            }
            else
            {
                invalidMove();
                getchar();
                getchar();
            }
        }
    }
    return OK;
}

#endif
