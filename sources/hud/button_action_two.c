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

void show_buttons(button_t **buttons, sprite_sheet_t **hud_sprite,
elements_t *elements, hud_elements_t *hud)
{
    for (int i = 0; i < NB_BUTTON; ++i)
        show_button(buttons[i], elements);
    if (buttons[2]->infos & SHOW_F)
        refresh_sprite(hud_sprite[0], elements);
    if (buttons[3]->infos & SHOW_F)
        refresh_sprite(hud_sprite[0], elements);
}

void params_button(button_t **buttons, sprite_sheet_t *params,
elements_t *elements)
{
    show_b(buttons[1]);
    show_b(buttons[2]);
    show_b(buttons[25]);
    unclick_b(buttons[0]);
}

void close_params(button_t **buttons)
{
    hide_b(buttons[1]);
    hide_b(buttons[2]);
    hide_b(buttons[25]);
    unclick_b(buttons[1]);
    unclick_b(buttons[2]);
    unclick_b(buttons[25]);
}

void sound_bar(button_t **buttons, slide_bar_t *bar)
{
    hide_b(buttons[2]);
    unclick_b(buttons[1]);
    unclick_b(buttons[2]);
    show_s(bar);
    show_b(buttons[3]);
    show_b(buttons[4]);
}

void close_sound_bar(button_t **buttons, slide_bar_t *bar)
{
    hide_b(buttons[3]);
    hide_b(buttons[4]);
    hide_b(buttons[1]);
    hide_b(buttons[25]);
    hide_s(bar);
    unclick_b(buttons[1]);
    unclick_b(buttons[2]);
    unclick_b(buttons[3]);
    unclick_b(buttons[4]);
    unclick_b(buttons[25]);
}
