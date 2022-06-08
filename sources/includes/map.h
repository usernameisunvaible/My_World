/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>


typedef struct
{
    sfVector2i size;
    sfVector2i centre;
    int **flat_map;
    sfVector2f *flat_map_pos;
    int **map;
    int **map_color;
    sfVertexArray **vertex_ar_tab;
    sfVertex *p_vert;
    int array_nb;
    int height_pos;
    int width_pos;
    float zoom;
    int rotat;
    int view_type;
    char *map_path;
    char *path_temp;
    int temp_path_index;
}map;

#endif //MAP_H_