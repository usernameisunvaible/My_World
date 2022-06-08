/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef HUD_H_
    #define HUD_H_

typedef struct hud_elements_s {
    button_t **file_but;
    sfText **text_file_but;
    int nb_file;
    button_t **buttons;
    sprite_sheet_t **sprites;
    slide_bar_t **slide_bars;
    sfText **text_hud;
    int brush_size;
    int tool;
    int single_click;
}hud_elements_t;

#endif // HUD_H_