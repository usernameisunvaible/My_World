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

void action_button_three(elements_t *elements, hud_elements_t *hud, map *monde)
{
    if (hud->buttons[13]->infos & CLICK_F)
        file_buttons(hud->buttons);
    if (hud->buttons[14]->infos & CLICK_F)
        close_file_button(hud->buttons);
    if (hud->buttons[5]->infos & CLICK_F)
        save_button(hud->buttons, monde);
    if (hud->buttons[15]->infos & CLICK_F) {
        open_button(hud->buttons, elements, hud, monde);
        unclick_b(hud->buttons[6]);
    }
    if (hud->buttons[16]->infos & CLICK_F)
        close_open_menu(hud->buttons, elements, hud, monde);
    if (hud->buttons[16]->infos & SHOW_F)
        refresh_button(elements, hud, monde);
    if (hud->buttons[6]->infos & CLICK_F) {
        show_b(hud->buttons[14]);
        hide_b(hud->buttons[16]);
        unclick_b(hud->buttons[16]);
    }
}

void action_button_two(elements_t *elements, hud_elements_t *hud, map *monde)
{
    if (hud->buttons[0]->infos & CLICK_F)
        params_button(hud->buttons, hud->sprites[0], elements);
    if (hud->buttons[1]->infos & CLICK_F)
        sound_bar(hud->buttons, hud->slide_bars[0]);
    if (hud->buttons[2]->infos & CLICK_F)
        close_params(hud->buttons);
    if (hud->buttons[3]->infos & CLICK_F || hud->buttons[4]->infos & CLICK_F)
        close_sound_bar(hud->buttons, hud->slide_bars[0]);
    if (hud->buttons[7]->infos & CLICK_F)
        move_up_down(monde, -6);
    if (hud->buttons[8]->infos & CLICK_F)
        move_up_down(monde, 6);
    if (hud->buttons[9]->infos & CLICK_F)
        move_right_left(monde, 6);
    if (hud->buttons[10]->infos & CLICK_F)
        move_right_left(monde, -6);
    if (hud->buttons[11]->infos & CLICK_F)
        rotate_x_y(monde, 1);
    if (hud->buttons[12]->infos & CLICK_F)
        rotate_x_y(monde, -1);
}

void action_button_four(elements_t *elements, hud_elements_t *hud, map *monde)
{
    if (hud->buttons[24]->infos & CLICK_F)
        zoom(monde, 1/1.02);
    if (hud->buttons[17]->infos & CLICK_F)
        sfRenderWindow_close(elements->window);
    unclick_b(hud->buttons[7]);
    unclick_b(hud->buttons[8]);
    unclick_b(hud->buttons[9]);
    unclick_b(hud->buttons[10]);
    unclick_b(hud->buttons[11]);
    unclick_b(hud->buttons[12]);
    unclick_b(hud->buttons[15]);
    unclick_b(hud->buttons[18]);
    unclick_b(hud->buttons[19]);
    unclick_b(hud->buttons[20]);
    unclick_b(hud->buttons[21]);
    unclick_b(hud->buttons[22]);
    unclick_b(hud->buttons[23]);
    unclick_b(hud->buttons[24]);
    unclick_b(hud->buttons[26]);
}

void action_button(elements_t *elements, hud_elements_t *hud, map *monde)
{
    action_button_two(elements, hud, monde);
    action_button_three(elements, hud, monde);
    if (hud->buttons[18]->infos & CLICK_F)
        --hud->brush_size;
    if (hud->buttons[19]->infos & CLICK_F)
        ++hud->brush_size;
    if (hud->buttons[20]->infos & CLICK_F)
        hud->tool = 1;
    if (hud->buttons[21]->infos & CLICK_F)
        hud->tool = 2;
    if (hud->buttons[22]->infos & CLICK_F)
        hud->tool = 3;
    if (hud->buttons[23]->infos & CLICK_F)
        zoom(monde, 1.02);
    if (hud->buttons[26]->infos & CLICK_F && hud->single_click == 1) {
        (monde->view_type > 5) ? (monde->view_type = 1): (++monde->view_type);
        hud->single_click = 0;
    }
    action_button_four(elements, hud, monde);
}


