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

sfVector2i mouse_pos_on_flat_map(map *map_s, elements_t *elements)
{
    sfVector2i closer;
    double dist_closer = 10000;
    double temp = 0;

    for (int i = 0; i < map_s->size.x * map_s->size.y; ++i) {
        temp = (double)(square(elements->m_pos.x - map_s->flat_map_pos[i].x)
+ square(elements->m_pos.y - map_s->flat_map_pos[i].y));
        temp = sqrt(temp);
        if (temp < dist_closer) {
            closer = define_vectori(i % map_s->size.x, i / map_s->size.x);
            dist_closer = temp;
        }
    }
    return closer;
}
