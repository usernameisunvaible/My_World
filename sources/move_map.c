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

void generate_flap_map(map *map_s)
{
    int a = 0;
    for (int i = -map_s->centre.y; i < map_s->size.y - map_s->centre.y ;
++i) {
        for (int j = -map_s->centre.x; j < map_s->size.x - map_s->centre.x;
++j) {
            map_s->flat_map_pos[a] = give_point_pos(define_vectortf(i, j,
map_s->map[j + map_s->centre.x][i + map_s->centre.y]), 75, map_s->size,
map_s->rotat);
            map_s->flat_map_pos[a].x *= (float) 900 / map_s->size.x;
            map_s->flat_map_pos[a].y *= (float) 900 / map_s->size.y;
            map_s->flat_map_pos[a].x *= map_s->zoom;
            map_s->flat_map_pos[a].y *= map_s->zoom;
            map_s->flat_map_pos[a].x += map_s->width_pos;
            map_s->flat_map_pos[a].y += map_s->height_pos;
            map_s->flat_map_pos[a].x += (float) WIDTH / 2;
            map_s->flat_map_pos[a].y += (float) (HEIGHT / 5) * 3;
            ++a;
        }
    }
}

void rotate_x_y(map *map_s, float move)
{
    map_s->rotat += move;
    generate_flap_map(map_s);
}

void move_up_down(map *map_s, float move)
{
    for (int i = 0; i < map_s->size.x * map_s->size.y; ++i) {
        map_s->flat_map_pos[i].y += move;
    }
    map_s->height_pos += move;
}

void move_right_left(map *map_s, float move)
{
    for (int i = 0; i < map_s->size.x * map_s->size.y; ++i) {
        map_s->flat_map_pos[i].x += move;
    }
    map_s->width_pos += move;
}

void zoom(map *map_s, float move)
{
    map_s->zoom *= move;
    generate_flap_map(map_s);
}