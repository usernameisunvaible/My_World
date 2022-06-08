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

slide_bar_t **create_slide_bars(elements_t *elements)
{
    slide_bar_t **slide_bars = malloc(sizeof(slide_bar_t *) * NB_SLIDE_BAR);

    slide_bars[0] = init_slide_bar(elements, define_slide_bar_params(
"asset/barre_son.png", 200, define_vectori(52, 52), define_rect(WIDTH - 56 -
256, 48, 256, 64)));
    return slide_bars;
}
