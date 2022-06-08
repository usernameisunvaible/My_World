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

void main_events(elements_t *elements, hud_elements_t *hud, map *monde)
{
    (K_UP_B_SIZE == KEY_CODE) ? (++hud->brush_size) : (0 == 0);
    (K_DOWN_B_SIZE == KEY_CODE) ? (--hud->brush_size) : (0 == 0);
    (K_LEFT == KEY_CODE) ? (move_right_left(monde, -6)) : (0 == 0);
    (K_RIGHT == KEY_CODE) ? (move_right_left(monde, 6)) : (0 == 0);
    (K_UP == KEY_CODE) ? (move_up_down(monde, -6)) : (0 == 0);
    (K_DOWN == KEY_CODE) ? (move_up_down(monde, 6)) : (0 == 0);
    (K_ZOOM == KEY_CODE) ? (zoom(monde, 1.02)) : (0 == 0);
    (K_DEZOOM == KEY_CODE) ? (zoom(monde, 1/1.02)) : (0 == 0);
    (K_ROT_LEFT == KEY_CODE) ? (rotate_x_y(monde, 1)) : (0 == 0);
    (K_ROT_RIGHT == KEY_CODE) ? (rotate_x_y(monde, -1)) : (0 == 0);
    (K_VIEW_TYPE == KEY_CODE) ? (monde->view_type =
(monde->view_type > 5) ? (monde->view_type = 1): (++monde->view_type)) : (0);
    (K_TOOL_1 == KEY_CODE) ? (hud->tool = 1) : (0 == 0);
    (K_TOOL_2 == KEY_CODE) ? (hud->tool = 2) : (0 == 0);
    (K_TOOL_3 == KEY_CODE) ? (hud->tool = 3) : (0 == 0);
}

void event_keys (elements_t *elements, hud_elements_t *hud, map *monde)
{
    while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
        if (elements->event.type == sfEvtClosed)
            sfRenderWindow_close(elements->window);
        if (elements->event.type == sfEvtKeyPressed) {
            main_events(elements, hud, monde);
            if (sfKeyA == KEY_CODE) {
                free_map(monde);
                monde = init_map("maps/test.legend");
            }
        }
        if (elements->event.mouseButton.type == sfEvtMouseButtonReleased)
            hud->single_click = 1;
    }
}

char get_keys(elements_t *elements)
{
    for (int i = 0; i < 26; ++i) {
        if (i == KEY_CODE)
            return i + 97;
    }
    if (sfKeySpace == KEY_CODE)
        return 32;
    if (56 == KEY_CODE)
        return 45;
    if (sfKeyNum8 == KEY_CODE)
        return 95;
    if (sfKeyDelete == KEY_CODE || 59 == KEY_CODE)
        return -1;
    if (58 == KEY_CODE)
        return -2;
    return 0;
}

int change_str(char *path, int *id, char key)
{
    if (key == 0)
        return 0;
    if (key == -1) {
        --*id;
        if (*id < 0)
            *id = 0;
        path[*id] = 0;
    } else {
        path[*id] = key;
        path[*id + 1] = 0;
        ++*id;
    }
    return 0;
}

int write_key (elements_t *elements, char *path, int *id)
{
    char key;
    int ret = 0;

    while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
        if (elements->event.type == sfEvtClosed)
            sfRenderWindow_close(elements->window);
        if (elements->event.type == sfEvtKeyPressed) {
            key = get_keys(elements);
            ret = (key == -2) ? (1) : (change_str(path, id, key));
        }
    }
    return ret;
}