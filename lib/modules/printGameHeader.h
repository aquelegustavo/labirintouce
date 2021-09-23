#ifndef PRINT_GAME_HEADER_H
#define PRINT_GAME_HEADER_H

#include <stdio.h>
#include "../global.h"

void printGameHeader()
{

  printf(YELLOW "************************"
                "\n--> Labirintouce <--\n"
                "************************\n\n" RESET);

  printf("Esse é um joguinho de labirinto totalmente escrito na linguagem C.\n");
  printf("Disponível em " BLUE "https://github.com/aquelegustavo/labirintouce \n" RESET);

  printf("\n\nPara jogar é fácil! Basta seguir estas orientações:");
  printf(YELLOW "\n\n  (W)" SPACE SPACE
                "  (CIMA)"
                "\n(A)+(D)" SPACE
                "(ESQUERDA)+(DIREITA)\n  (S)" SPACE SPACE
                "  (BAIXO)" RESET);

  printf(YELLOW "\n\nPressione " RED "X" YELLOW " para parar o jogo.\n\n" RESET);

  printf(MAGENTA "\n\n\n>> Pressione " CYAN
                 "ENTER" MAGENTA
                 " para começar o jogo! <<\n" RESET);
  getchar();
}

#endif