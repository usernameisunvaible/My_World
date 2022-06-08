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

int get_high_flat(int color, int old, int map_pos)
{
    if (color == 1)
        return map_pos;
    else
        return old;
}

void flat_map(map *map_s, sfSound *sound, hud_elements_t *hud,
elements_t *elements)
{
    int flat_high = 0;
    for (int i = 0; i < map_s->size.x; ++i) {
        for (int j = 0; j < map_s->size.y; ++j) {
            flat_high = get_high_flat(map_s->map_color[i][j], flat_high,
map_s->map[i][j]);
        }
    }
    for (int i = 0; i < map_s->size.x; ++i) {
        for (int j = 0; j < map_s->size.y; ++j) {
            if (elements->left && map_s->map_color[i][j] == 2 &&
!(hud->buttons[1]->infos & SHOW_F)) {
                map_s->map[i][j] = flat_high;
                play_sound(sound, hud->slide_bars[0], 0);
            }
        }
    }
}

void put_flat_circle(map *map_s, sfVector2i pos, double diameter)
{
    double temp;

    for (int i = 0; i < map_s->size.x; ++i) {
        for (int j = 0; j < map_s->size.y; ++j) {
            temp = (double) (square(pos.x - i) + square(pos.y - j));
            temp = sqrt(temp);
            if (temp <= diameter) {
                if (map_s->map[i][j] == map_s->map[pos.x][pos.y])
                    (((int)diameter - (int)temp) / 3 >= 1) ?
(map_s->map_color[i][j] = 1) : (map_s->map_color[i][j] = 0);
                else
                    (((int)diameter - (int)temp) / 3 >= 1) ?
(map_s->map_color[i][j] = 2) : (map_s->map_color[i][j] = 0);
            }
        }
    }
}
