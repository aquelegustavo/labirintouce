/**
 * ARQUIVO: lib/utils/invalidMove.h
 * 
 * TÍTULO: RELATÓRIO DE TRABALHO DE LABORATÓRIO 2
 * ENVIADO POR: Gustavo Simões e Izabelle Custodia Teixeira Sebastiao.            
 *              Todo o código tem como autores Gustavo Simões e Izabelle C. T. Sebastião.
 * 
 * CURSO: Linguagem de progrmação 1 do curso de Enhenharia de Computação da UFSC
 * DATA: 04/09/21 
 * 
 * PROPÓSITO:
 * Avisar ao usuario caso tenha obstaculo, ou seja, uma parede (*) ou um bloco(|).
 * 
 * METÓDO GERAL:
 * Imprimir na tela uma mensagem de erro e incrementa em 1 a variável 
 * global "invalidMovesCounter'
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdio.h
 * global.h
 * getRandom.h
 */
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
