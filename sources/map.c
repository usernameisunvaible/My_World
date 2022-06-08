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

void copy_string(char *out, const char *in)
{
    int i = 0;
    for (; in[i] && i < 300; ++i) {
        out[i] = in[i];
    }
    out[i] = 0;
}

void init_map_two(map *map_s, const char *path, int a)
{
    map_s->map_path = malloc(sizeof(char) * 300);
    map_s->path_temp = malloc(sizeof(char) * 300);
    map_s->path_temp[0] = 0;
    map_s->temp_path_index = 0;
    if (path[0] == 'f') {
        map_s->size = define_vectori(250, 250);
        map_s->map = create_map_color( map_s->size);
        map_s->map_path[0] = 0;
    } else {
        open_file(path, map_s);
        copy_string(map_s->map_path, path);
    }
    map_s->centre.x = map_s->size.x / 2;
    map_s->centre.y = map_s->size.y / 2;
    map_s->height_pos = 0;
    map_s->width_pos = 0;
    map_s->zoom = 1;
    map_s->flat_map = create_map_color(map_s->size);
    map_s->rotat = 0;
}

void init_map_three(map *map_s, const char *path, int a)
{
    map_s->view_type = 1;
    map_s->flat_map_pos = malloc(sizeof(sfVector2f) * map_s->size.x *
map_s->size.y);
    for (int i = -map_s->centre.y; i < map_s->size.y -
map_s->centre.y ; ++i) {
        for (int j = -map_s->centre.x; j < map_s->size.x -
map_s->centre.x; ++j) {
            map_s->flat_map_pos[a] = give_point_pos( define_vectortf(i,
j, map_s->map[j + map_s->centre.x][i + map_s->centre.y]), 75, map_s->size,
map_s->rotat);
            map_s->flat_map_pos[a].x *= (float) 900 / map_s->size.x;
            map_s->flat_map_pos[a].y *= (float) 900 / map_s->size.y;
            map_s->flat_map_pos[a].x += (float) WIDTH / 2;
            map_s->flat_map_pos[a].y += (float)(HEIGHT / 5) * 3;
            ++a;
        }
    }
    map_s->map_color = create_map_color(map_s->size);
    map_s->p_vert = malloc(sizeof(sfVertex) * map_s->size.x * map_s->size.y);
}

map *init_map(const char *path)
{
    map *map_s = malloc(sizeof(map));
    int a = 0;

    init_map_two(map_s, path, a);
    init_map_three(map_s, path, a);
    map_s->vertex_ar_tab = malloc(sizeof(sfVertexArray *) * map_s->size.x *
map_s->size.y);
    a = 0;
    for (int i = 0; i < map_s->size.x * map_s->size.y - map_s->size.x; ++i) {
        if ((i + 1) % (map_s->size.x) != 0) {
            map_s->vertex_ar_tab[a] = sfVertexArray_create();
            sfVertexArray_setPrimitiveType(map_s->vertex_ar_tab[a], sfQuads);
            ++a;
        }
    }
    return map_s;
}

void free_map(map *monde)
{
    free(monde->path_temp);
    free(monde->map_path);
    free(monde->flat_map_pos);
    free(monde->p_vert);
    free(monde->vertex_ar_tab);
    for (int i = 0; i < monde->size.x; ++i) {
        free(monde->flat_map[i]);
    }
    free(monde->flat_map);
    for (int i = 0; i < monde->size.x; ++i) {
        free(monde->map_color[i]);
    }
    free(monde->map_color);
    free(monde);
}