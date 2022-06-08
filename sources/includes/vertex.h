/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef VERTEX_H_
    #define VERTEX_H_

    #include "map.h"
    #include "../../includes/include_engine.h"

void generate_array (map *map_s, hud_elements_t *hud, framebuffer_t *fbr);
void refresh_vertex_array(map *map_s, elements_t *elements,
hud_elements_t *hud);
sfColor shades_of_green(int v);
sfColor shades_of_grey(int v);
sfColor generate_v_color(int height_p, int map_color, hud_elements_t *hud);
void cloud_map_two(framebuffer_t *fbr, map *map_s, int a, int i);
void cloud_map(framebuffer_t *fbr, map *map_s, int a, int i);
#endif //VERTEX_H_