/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../includes/include_engine.h"
#include "includes/include_all.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int **create_map_color(sfVector2i size)
{
    int **pas = malloc(sizeof(int *) * size.x);

    for (int i = 0; i < size.x; ++i) {
        pas[i] = malloc(sizeof(int) * size.y);
        for (int j = 0; j < size.y; ++j) {
            pas[i][j] = 0;
        }
    }
    return pas;
}
