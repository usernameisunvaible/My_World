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

hud_elements_t *save_as_two(hud_elements_t *hud, char *temp)
{
    hide_b(hud->buttons[5]);
    hide_b(hud->buttons[6]);
    hide_b(hud->buttons[17]);
    hide_b(hud->buttons[14]);
    unclick_b(hud->buttons[14]);
    unclick_b(hud->buttons[6]);
    hide_b(hud->buttons[16]);
    unclick_b(hud->buttons[16]);
    hide_b(hud->buttons[15]);
    hud->nb_file = 0;
}

int save_as(char *path, map *monde, hud_elements_t *hud)
{
    char *temp = malloc(sizeof(char) * 313);
    char ext[7] = ".legend";
    char folder[5] = "maps/";
    int i = 0;
    int a = 0;
    int j = 0;
    for (; j < 5; ++j)
        temp[j] = folder[j];
    for (; path[i]; ++i)
        temp[i + j] = path[i];
    for (; a < 7; ++a)
        temp[a + my_strlen(path) + j] = ext[a];
    temp[i + a + j] = 0;
    for (int i = 0; i < my_strlen(temp); ++i)
        monde->map_path[i] = temp[i];
    monde->map_path[my_strlen(temp)] = 0;
    save(temp, monde->map, monde->size);
    hud = save_as_two(hud, temp);

    free(temp);
}