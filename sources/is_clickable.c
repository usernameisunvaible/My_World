/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../includes/include_engine.h"
#include "includes/include_all.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Audio.h>

int mouse_on_rect_but(button_t *button, sfVector2i m_pos)
{
    if (m_pos.x >= button->pos.left && m_pos.x <= button->pos.left +
button->pos.width) {
        if (m_pos.y >= button->pos.top && m_pos.y <= button->pos.top +
button->pos.height)
            return 1;
    }
    return 0;
}

int can_i_grow(hud_elements_t *hud, elements_t *elements)
{
    for (int i = 0; i < NB_BUTTON; ++i) {
        if (hud->buttons[i]->infos & SHOW_F &&
mouse_on_rect_but(hud->buttons[i], elements->m_pos)) {
            return 1;
        }
    }
    for (int i = 0; i < hud->nb_file; ++i) {
        if (mouse_on_rect_but(hud->file_but[i], elements->m_pos))
            return 1;
    }
    return 0;
}