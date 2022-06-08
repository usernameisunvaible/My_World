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
#include <SFML/Audio.h>

void put_circle_arround_mouse(map *map_s, sfVector2i pos, double diameter)
{
    double temp;

    for (int i = 0; i < map_s->size.x; ++i) {
        for (int j = 0; j < map_s->size.y; ++j) {
            temp = (double) (square(pos.x - i) + square(pos.y - j));
            temp = sqrt(temp);
            if (temp <= diameter)
                map_s->map_color[i][j] = ((int)diameter - (int)temp) / 3;
        }
    }
}
