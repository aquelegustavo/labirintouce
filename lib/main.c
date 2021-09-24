/**
 * ARQUIVO: lib/main.c
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
 * Este trabalho tem como propósito criar um jogo do labirinto, em que o usuário, 
 * por meio de comandos via teclado, controla um personagem que deve sair do 
 * começo do labirinto até o final, encostado o mínimo de vezes possíveis nas
 * paredes do mapa (*).
 * 
 * METÓDO GERAL:
 * Criação dinâmica do mapa;
 * Jogabilidade;
 * Geração do relatório do jogo (saída de jogo);
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdio.h
 * time.h
 * stdlib.h
 * global.h
 * modules/printGameHeader.h
 * modules/createMap.h
 * modules/playerMove.h
 * modules/endOutputFile.h
 * 
 */

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

    // libera a memória da matriz map
    for (size_t i = 0; i < rowsNumber; i++)
        free(map[i]);
    free(map);

    endOutputFile(startGameTime);

    return 0;
}
