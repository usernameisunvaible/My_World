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

void tools(map *monde, elements_t *elements, hud_elements_t *hud,
sfSound *plop)
{
    if (can_i_grow(hud, elements) == 0) {
        if (hud->tool == 1) {
            put_circle_arround_mouse(monde,
            mouse_pos_on_flat_map(monde, elements), hud->brush_size);
            grow_map(monde, plop, hud, elements);
        }
        if (hud->tool == 2) {
            put_circle_arround_mouse(monde, mouse_pos_on_map(monde, elements),
            hud->brush_size);
            grow_map(monde, plop, hud, elements);
        }
        if (hud->tool == 3) {
            put_flat_circle(monde, mouse_pos_on_map(monde, elements),
            hud->brush_size);
            flat_map(monde, plop, hud, elements);
        }
    }
}