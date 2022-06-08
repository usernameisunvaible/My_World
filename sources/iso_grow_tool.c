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

sfVector2i mouse_pos_on_map(map *map_s, elements_t *elements)
{
    sfVector2i closer = define_vectori(0, 0);
    double dist_closer = 10000;
    double temp = 0;
    double last = 99999;

    for (int i = map_s->size.x * map_s->size.y; i >= 0 ; --i) {
        temp = (double)(square(elements->m_pos.x -
(int)map_s->p_vert[i].position.x) + square(elements->m_pos.y -
(int)map_s->p_vert[i].position.y));
        temp = sqrt(temp);  
        if (temp < dist_closer) {
            closer = define_vectori(i % map_s->size.x, i / map_s->size.x);
            dist_closer = temp;
        }
    }
    return closer;
}

int segment_intersect(sfVector2f a, sfVector2f b, sfVector2f c, sfVector2f d)
{
    int dir_coef_a = ((b.y - a.y)/(b.x - a.y));
    int dir_coef_b = ((d.y - c.y)/(d.x - c.y));

}
