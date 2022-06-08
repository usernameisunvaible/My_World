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

sfText **create_hud_text(elements_t *element, hud_elements_t *hud)
{
    sfText **tab = malloc(sizeof(sfText *) * NB_HUD_TEXT);

    tab[0] = text_factory(define_text_params("", "asset/akhirtathun.ttf",
define_vectorf(WIDTH - 210, 8), 27), element);
    tab[1] = text_factory(define_text_params("", "asset/akhirtathun.ttf",
define_vectorf(WIDTH - 395, 8), 27), element);
    tab[2] = text_factory(define_text_params("", "asset/akhirtathun.ttf",
define_vectorf(190, 18), 19), element);
    tab[3] = text_factory(define_text_params("", "asset/akhirtathun.ttf",
define_vectorf(190, 0), 18), element);
    return tab;
}
