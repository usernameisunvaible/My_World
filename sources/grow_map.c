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

void grow_map(map *map_s, sfSound *plop, hud_elements_t *hud,
elements_t *elements)
{
    for (int i = 0; i < map_s->size.x; ++i) {
        for (int j = 0; j < map_s->size.y; ++j) {
            if (elements->left && map_s->map_color[i][j] >= 1 &&
!(hud->buttons[1]->infos & SHOW_F)) {
                map_s->map[i][j] += map_s->map_color[i][j];
                play_sound(plop, hud->slide_bars[0], 0.2);
            }
            if (elements->right && map_s->map_color[i][j] >= 1 &&
!(hud->buttons[1]->infos & SHOW_F)) {
                map_s->map[i][j] -= map_s->map_color[i][j];
                play_sound(plop, hud->slide_bars[0], -0.2);
            }
        }
    }
}