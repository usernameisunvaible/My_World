/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/
#include "../../includes/include_engine.h"
#include "../includes/include_all.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void file_buttons(button_t **buttons)
{
    show_b(buttons[5]);
    show_b(buttons[6]);
    show_b(buttons[14]);
    show_b(buttons[15]);
    show_b(buttons[17]);
    unclick_b(buttons[13]);
}

void close_file_button(button_t **buttons)
{
    hide_b(buttons[5]);
    hide_b(buttons[6]);
    hide_b(buttons[17]);
    hide_b(buttons[15]);
    hide_b(buttons[14]);
    unclick_b(buttons[14]);
    unclick_b(buttons[6]);
}

void save_button(button_t **buttons, map *monde)
{
    hide_b(buttons[16]);
    unclick_b(buttons[16]);
    if (monde->map_path[0]) {
        show_b(buttons[14]);
        save(monde->map_path, monde->map, monde->size);
    } else {
        click_b(buttons[6]);
    }
    unclick_b(buttons[5]);
}

void open_button(button_t **buttons, elements_t *elements, hud_elements_t *hud,
map *monde)
{
    hide_b(buttons[14]);
    unclick_b(buttons[14]);
    show_b(buttons[16]);
    open_ui(monde, elements, hud);
}

void close_open_menu(button_t **buttons, elements_t *elements,
hud_elements_t *hud, map *monde)
{
    hide_b(buttons[16]);
    hide_b(buttons[5]);
    hide_b(buttons[6]);
    hide_b(buttons[17]);
    hide_b(buttons[15]);
    hide_b(buttons[14]);
    hide_b(buttons[15]);
    unclick_b(buttons[14]);
    unclick_b(buttons[6]);
    unclick_b(buttons[16]);
    hud->nb_file = 0;
}
