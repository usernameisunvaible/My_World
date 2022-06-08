/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef P_HUD_H_
    #define P_HUD_H_

hud_elements_t *init_hud_elements(elements_t *elements);
void refresh_hud(hud_elements_t *hud, elements_t *elements, map *monde);
void save(char *path, int **map, sfVector2i map_size);
sfText **create_hud_text(elements_t *element, hud_elements_t *hud);
int can_i_grow(hud_elements_t *hud, elements_t *elements);
void file_buttons(button_t **buttons);
void close_file_button(button_t **buttons);
void save_button(button_t **buttons, map *monde);
void open_button(button_t **buttons, elements_t *elements, hud_elements_t *hud,
map *monde);
void close_open_menu(button_t **buttons, elements_t *elements,
hud_elements_t *hud, map *monde);
void show_buttons(button_t **buttons, sprite_sheet_t **hud_sprite,
elements_t *elements, hud_elements_t *hud);
void params_button(button_t **buttons, sprite_sheet_t *params,
elements_t *elements);
void close_params(button_t **buttons);
void sound_bar(button_t **buttons, slide_bar_t *bar);
void close_sound_bar(button_t **buttons, slide_bar_t *bar);

#endif // P_HUD_H_
