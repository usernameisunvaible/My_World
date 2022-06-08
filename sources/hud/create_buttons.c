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

void show_b_buttons(button_t **buttons)
{
    show_b(buttons[0]);
    show_b(buttons[7]);
    show_b(buttons[8]);
    show_b(buttons[9]);
    show_b(buttons[10]);
    show_b(buttons[11]);
    show_b(buttons[12]);
    show_b(buttons[13]);
    show_b(buttons[18]);
    show_b(buttons[19]);
    show_b(buttons[20]);
    show_b(buttons[21]);
    show_b(buttons[22]);
    show_b(buttons[23]);
    show_b(buttons[24]);
    show_b(buttons[26]);
}

void create_buttons_two(button_t **buttons, elements_t *elements)
{
    buttons[17] = init_button(elements, define_button_params(
"asset/quit.png", define_rect(0, 48 * 4 + 4, 188, 48), 8, 10));
    buttons[18] = init_button(elements, define_button_params(
"asset/mini_fleche_bas.png", define_rect(WIDTH -128, 25, 48, 24), 0, 0));
    buttons[19] = init_button(elements, define_button_params(
"asset/mini_fleche_haut.png", define_rect(WIDTH -128, 0, 48, 24), 0, 0));
    buttons[20] = init_button(elements, define_button_params(
"asset/mount.png", define_rect(WIDTH / 2 - 73, 0, 48, 48), 0, 0));
    buttons[21] = init_button(elements, define_button_params(
"asset/mount_iso.png", define_rect(WIDTH / 2 - 24, 0, 48, 48), 0, 0));
    buttons[22] = init_button(elements, define_button_params(
"asset/flat.png", define_rect(WIDTH / 2 + 25, 0, 48, 48), 0, 0));
    buttons[23] = init_button(elements, define_button_params(
"asset/zoom.png", define_rect(WIDTH- 160, HEIGHT - 320, 64, 64), 0, 0));
    buttons[24] = init_button(elements, define_button_params(
"asset/dezoom.png", define_rect(WIDTH- 160, HEIGHT - 255, 64, 64), 0, 0));
    buttons[25] = init_button(elements, define_button_params(
"asset/aide.png", define_rect(WIDTH - 50, 103, 48, 48), 0, 0));
    buttons[26] = init_button(elements, define_button_params(
"asset/eye.png", define_rect(WIDTH - 450, 0, 48, 48), 0, 0));
}

void create_buttons_three(button_t **buttons, elements_t *elements)
{
    buttons[7] = init_button(elements, define_button_params(
"asset/fleches_haut.png", define_rect(128, HEIGHT - 256, 64, 64), 8, 10));
    buttons[8] = init_button(elements, define_button_params(
"asset/fleches_bas.png", define_rect(128, HEIGHT - 128, 64, 64), 8, 10));
    buttons[9] = init_button(elements, define_button_params(
"asset/fleches_droite.png", define_rect(192, HEIGHT - 192, 64, 64), 8, 10));
    buttons[10] = init_button(elements, define_button_params(
"asset/fleches_gauche.png", define_rect(64, HEIGHT - 192, 64, 64), 8, 10));
    buttons[11] = init_button(elements, define_button_params("asset/tourne_g\
auche.png", define_rect(WIDTH- 192, HEIGHT - 128, 64, 64), 1, 1));
    buttons[12] = init_button(elements, define_button_params("asset/tourner_dr\
oite.png", define_rect(WIDTH- 128, HEIGHT - 128, 64, 64), 1, 1));
    buttons[13] = init_button(elements, define_button_params(
"asset/file_button.png", define_rect(0, 0, 140, 48), 1, 1));
    buttons[14] = init_button(elements, define_button_params(
"asset/empty.png", define_rect(188, 0, WIDTH, HEIGHT), 0, 0));
    buttons[15] = init_button(elements, define_button_params(
"asset/open.png", define_rect(0, 48 * 1 + 1, 188, 48), 0, 0));
    buttons[16] = init_button(elements, define_button_params(
"asset/empty.png", define_rect(188 + 400, 0, WIDTH, HEIGHT), 0, 0));
}

void call_create(button_t **buttons, elements_t *elements)
{
    create_buttons_two(buttons, elements);
    create_buttons_three(buttons, elements);
    show_b_buttons(buttons);
}

button_t **create_buttons(elements_t *elements)
{
    button_t **buttons = malloc(sizeof(button_t *) * NB_BUTTON);

    buttons[0] = init_button(elements, define_button_params(
"asset/engrenages.png", define_rect(WIDTH - 48, 0, 48, 48), 6, 10));
    buttons[1] = init_button(elements, define_button_params(
"asset/son.png", define_rect(WIDTH - 50, 54, 48, 48), 3, 3));
    buttons[2] = init_button(elements, define_button_params(
"asset/empty.png", define_rect(0, 0, WIDTH - 56, HEIGHT), 0, 0));
    buttons[3] = init_button(elements, define_button_params(
"asset/empty.png", define_rect(0, 0, WIDTH - 56 - 256, HEIGHT), 0, 0));
    buttons[4] = init_button(elements, define_button_params(
"asset/empty.png", define_rect(WIDTH - 56 - 256, 48 + 56, 256,
HEIGHT - (48 + 56)), 0, 0));
    buttons[5] = init_button(elements, define_button_params("asset/save.png",
define_rect(0, 48 * 2 + 2, 188, 48), 8, 10));
    buttons[6] = init_button(elements, define_button_params(
"asset/save_as.png", define_rect(0, 48 * 3 + 3, 188, 48), 8, 10));
    call_create(buttons, elements);
    return buttons;
}
