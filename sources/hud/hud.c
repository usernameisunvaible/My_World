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

hud_elements_t *init_hud_elements(elements_t *elements)
{
    hud_elements_t *hud = malloc(sizeof(hud_elements_t));

    hud->buttons = create_buttons(elements);
    hud->sprites = create_hud(elements);
    hud->slide_bars = create_slide_bars(elements);
    hud->brush_size = 20;
    hud->text_hud = create_hud_text(elements, hud);
    hud->tool = 1;
    hud->single_click = 1;
    hud->nb_file = 0;
    return hud;
}

void refresh_hud(hud_elements_t *hud, elements_t *elements, map *monde)
{
    action_button(elements, hud, monde);
    show_buttons(hud->buttons, hud->sprites, elements, hud);
    show_slide_bar(hud->slide_bars[0], elements);
    refresh_text(elements, hud->text_hud[0], int_into_str(hud->brush_size));
    refresh_text(elements, hud->text_hud[1], "brush size:");
    if (hud->buttons[6]->infos & CLICK_F) {
        refresh_text(elements, hud->text_hud[2], monde->path_temp);
        refresh_text(elements, hud->text_hud[3], "Name ?");
    }
}
