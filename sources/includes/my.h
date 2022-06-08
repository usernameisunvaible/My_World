/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef MY_H_
    #define MY_H_

button_t **create_buttons(elements_t *elements);
void action_button(elements_t *elements, hud_elements_t *hud, map *monde);
sprite_sheet_t **create_hud(elements_t *elements);
void show_buttons(button_t **buttons, sprite_sheet_t **hud_sprite,
elements_t *elements, hud_elements_t *hud);
slide_bar_t **create_slide_bars(elements_t *elements);
sfVector2f give_point_pos(sfVector3f vec, int angle, sfVector2i size,
int rotat);
char *int_into_str(const int nbr);
int square(int n);
void event_keys (elements_t *elements, hud_elements_t *hud, map *monde);
int write_key (elements_t *elements, char *path, int *id);
int save_as(char *path, map *monde, hud_elements_t *hud);
void open_ui(map *monde, elements_t *elements, hud_elements_t *hud);
void refresh_button(elements_t *elements, hud_elements_t *hud, map *monde);
void free_file_buttons(hud_elements_t *hud);
void cp_name_map(char *out, char *in);
int comp_string(char *a, char *b);
int **create_map_color(sfVector2i size);

#endif //MY_H_