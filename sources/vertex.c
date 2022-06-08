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

void vertex_pop_order(map *map_s, int i, int a)
{
    if (map_s->view_type == 1) {
        sfVertexArray_append(map_s->vertex_ar_tab[a], map_s->p_vert[i]);
        sfVertexArray_append(map_s->vertex_ar_tab[a],
        define_vertex(map_s->p_vert[i + 1].position, map_s->p_vert[i].color));
        sfVertexArray_append(map_s->vertex_ar_tab[a],
        define_vertex(map_s->p_vert[i + map_s->size.x + 1].position,
        map_s->p_vert[i].color));
        sfVertexArray_append(map_s->vertex_ar_tab[a],
        define_vertex(map_s->p_vert[i + map_s->size.x].position,
        map_s->p_vert[i].color));
    }
    if (map_s->view_type == 2) {
        sfVertexArray_append(map_s->vertex_ar_tab[a], map_s->p_vert[i]);
        sfVertexArray_append(map_s->vertex_ar_tab[a], map_s->p_vert[i + 1]);
        sfVertexArray_append(map_s->vertex_ar_tab[a],
        map_s->p_vert[i + map_s->size.x + 1]);
        sfVertexArray_append(map_s->vertex_ar_tab[a],
        map_s->p_vert[i + map_s->size.x]);
    }
}

int generate_array_three(map *map_s, hud_elements_t *hud, framebuffer_t *fbr,
int a)
{
    int b = 0;
    b = a;
    a = 0;
    for (int i = 0; i < map_s->size.x * map_s->size.y - map_s->size.x; ++i) {
        if ((i + 1) % (map_s->size.x) != 0 && (map_s->view_type >= 1 ||
        map_s->view_type <= 2)) {
            vertex_pop_order(map_s, i, a);
            ++a;
        }
    }
    return a;
}

map *generate_array_two(map *map_s, int a)
{
    map_s->p_vert[a].position.x *= (float) 900 / map_s->size.x;
    map_s->p_vert[a].position.y *= (float) 900 / map_s->size.y;
    map_s->p_vert[a].position.x *= (float) map_s->zoom;
    map_s->p_vert[a].position.y *= (float) map_s->zoom;
    map_s->p_vert[a].position.y += (float) map_s->height_pos;
    map_s->p_vert[a].position.x += (float) map_s->width_pos;
    map_s->p_vert[a].position.x += (float) WIDTH / 2;
    map_s->p_vert[a].position.y += (float)(HEIGHT / 5) * 3;

    return map_s;
}

void generate_array (map *map_s, hud_elements_t *hud, framebuffer_t *fbr)
{
    int a = 0;
    int b = 0;
    for (int i = -map_s->centre.y; i < map_s->size.y - map_s->centre.y ; ++i) {
        for (int j = -map_s->centre.x; j < map_s->size.x - map_s->centre.x;
        ++j) {
            map_s->p_vert[a].position = give_point_pos(define_vectortf(i, j,
            map_s->map[j + map_s->centre.x][i + map_s->centre.y]), 75,
            map_s->size, map_s->rotat);
            map_s = generate_array_two(map_s, a);
            map_s->p_vert[a].color = generate_v_color(map_s->map[j +
            map_s->centre.x][i + map_s->centre.y],
            map_s->map_color[j + map_s->centre.x][i + map_s->centre.y], hud);
            map_s->map_color[j + map_s->centre.x][i + map_s->centre.y] = 0;
            cloud_map(fbr, map_s, a, i);
            ++a;
        }
    }
    a = generate_array_three(map_s, hud, fbr, a);
    map_s->array_nb = a;
}

void refresh_vertex_array(map *map_s, elements_t *elements,
hud_elements_t *hud)
{
    for (int i = 0; i < map_s->array_nb; ++i) {
        sfRenderWindow_drawVertexArray(elements->window,
        map_s->vertex_ar_tab[i], NULL);
        sfVertexArray_clear(map_s->vertex_ar_tab[i]);
    }
}
