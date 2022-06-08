/*
** EPITECH PROJECT, 2022
** vertex color
** File description:
** vertex
*/

#include "../includes/include_engine.h"
#include "includes/include_all.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sfColor shades_of_green(int v)
{
    int temp_g;
    int low_g = 155;
    int high_g = 100;
    float dif_c_g = low_g - high_g;
    float dif_b_g = STONE_LAYER - WATER_LAYER;
    float mult_g = dif_c_g/dif_b_g;

    v += -WATER_LAYER;
    temp_g = low_g - ((float)(v - WATER_LAYER) * mult_g);
    return sfColor_fromRGB(3, temp_g, 0);
}

sfColor shades_of_grey(int v)
{
    int temp;
    int low = 160;
    int high = 80;
    float dif_c = low - high;
    float dif_b = SNOW_LAYER - STONE_LAYER;
    float mult = dif_c/dif_b;

    temp = low - ((float)(v - STONE_LAYER) * mult);
    return sfColor_fromRGB(temp, temp, temp);
}

sfColor generate_v_color(int height_p, int map_color, hud_elements_t *hud)
{
    if (map_color >= 1 && hud->tool == 2)
        return sfRed;
    if (map_color >= 1 && hud->tool == 3) {
        if (map_color == 1)
            return sfBlue;
        if (map_color == 2)
            return sfRed;
    }
    if (map_color == 0 || height_p != 0) {
        if (height_p >= SNOW_LAYER)
            return sfWhite;
        if (height_p > STONE_LAYER && height_p < SNOW_LAYER)
            return shades_of_grey(height_p);
        if (height_p <= STONE_LAYER && height_p > WATER_LAYER)
            return shades_of_green(height_p);
        if (height_p <= WATER_LAYER)
            return sfColor_fromRGB(19, 57, 133);
    }
    if (map_color >= 1 && height_p == 0 && hud->tool == 1)
        return sfRed;
}

void cloud_map_two(framebuffer_t *fbr, map *map_s, int a, int i)
{
    if (map_s->view_type == 6) {
        if (a < map_s->size.y * map_s->size.x - 1 && (a + 1) %
        map_s->size.y != 0)
            draw_line(fbr, map_s->p_vert[a].position,
            map_s->p_vert[a + 1].position, sfWhite);
        if (a < map_s->size.y * map_s->size.x - (map_s->size.x))
            draw_line(fbr, map_s->p_vert[a].position,
            map_s->p_vert[a + map_s->size.x].position, sfWhite);
    }
}

void cloud_map(framebuffer_t *fbr, map *map_s, int a, int i)
{
    if (map_s->view_type == 3)
        put_pixel(fbr, map_s->p_vert[a].position.x,
        map_s->p_vert[a].position.y,
        map_s->p_vert[a].color);
    if (map_s->view_type == 4)
        put_pixel(fbr, map_s->p_vert[a].position.x,
        map_s->p_vert[a].position.y,
        sfWhite);
    if (map_s->view_type == 5) {
        if (a < map_s->size.y * map_s->size.x - 1 && (a + 1) %
        map_s->size.y != 0)
            draw_line(fbr, map_s->p_vert[a].position,
            map_s->p_vert[a + 1].position, map_s->p_vert[a].color);
        if (a < map_s->size.y * map_s->size.x - (map_s->size.x))
            draw_line(fbr, map_s->p_vert[a].position,
            map_s->p_vert[a + map_s->size.x].position, map_s->p_vert[a].color);
    }
    cloud_map_two(fbr, map_s, a, i);
}
