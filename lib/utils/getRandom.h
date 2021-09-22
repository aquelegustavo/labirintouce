#ifndef GET_RANDOM_H
#define GET_RANDOM_H
#include <stdlib.h>

int getRandom(int min, int max)
{
    int num = (min + rand() % (max + 1 - min));
    return num;
}

#endif