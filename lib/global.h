/**
 * ARQUIVO: lib/global.h
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
 * Esse código tem como objetivo deglarar globalmente variáveis e valores,
 * de modo que possam ser usados por todos os componentes do programas.
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdbool.h
 * getRandom.h
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdbool.h>
#include "utils/getRandom.h"

#define DEBUG_MODE false
#define DEBUG 7

#define OK 0
#define ERRO 1
#define END_GAME 2

#define NORTE 0
#define SUL 2
#define LESTE 1
#define OESTE 3

#define LIVRE 0
#define BLOCO 1
//#define PAREDE 2
#define PLAYER 3

#define X 0
#define Y 1

#define MAX_NUMBER (DEBUG_MODE ? 10 : 30)
#define MIN_NUMBER (DEBUG_MODE ? 5 : 10)

#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */
#define SPACE "      "

/* Usuarios de Windows, troquem "clear" por "cls" */
#define LIMPARTELA "clear"

// Declaração do número de linhas e colunas do mapa

int rowsNumber,
    columnsNumber;

// Declaração do mapa
int **map;

int playerCurrentPosition[2] = {0, 0};

int invalidMovesCounter = 0;

FILE *outputFile;

#endif