/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef TOOLS_H_
    #define TOOLS_H_

typedef struct {
    int size;
    char infos;
}simple_view_brush;

void tools(map *monde, elements_t *elements, hud_elements_t *hud,
sfSound *plop);
void put_flat_circle(map *map_s, sfVector2i pos, double diameter);
sfVector2i mouse_pos_on_flat_map(map *map_s, elements_t *elements);
void put_circle_arround_mouse(map *map_s, sfVector2i pos, double diameter);
void grow_map(map *map_s, sfSound *plop, hud_elements_t *hud,
elements_t *elements);
sfVector2i mouse_pos_on_map(map *map_s, elements_t *elements);
void flat_map(map *map_s, sfSound *plop, hud_elements_t *hud,
elements_t *elements);

#endif //TOOLS_H_