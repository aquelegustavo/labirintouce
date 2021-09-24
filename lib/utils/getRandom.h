/**
 * ARQUIVO: lib/utils/getRandom.h
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
 * Código retorna um valor aleatório entre n e m,
 * sendo n e m inteiros.
 * 
 * METÓDO GERAL:
 * Função getRandom() retorna um valor aleatório.
 * 
 * ARQUIVOS INCLUÍDOS:
 * stdlib.h
 */

#ifndef GET_RANDOM_H
#define GET_RANDOM_H
#include <stdlib.h>

// Função retorna um número inteiro aleatório
// entre o intervalo [min, max], sendo
// min e max pertencentes aos inteiros.
int getRandom(int min, int max)
{
    int num = (min + rand() % (max + 1 - min));
    return num;
}

#endif