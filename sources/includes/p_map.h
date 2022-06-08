/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef P_MAP_H_
    #define P_MAP_H_

map *init_map(const char *path);
void move_up_down(map *map_s, float move);
void move_right_left(map *map_s, float move);
void zoom(map *map_s, float move);
void rotate_x_y(map *map_s, float move);
void save(char *path, int **map, sfVector2i map_size);
void open_file(const char *path, map *monde);
void free_map(map *monde);

#endif //P_MAP_H_