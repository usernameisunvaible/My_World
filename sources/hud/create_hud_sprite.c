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

sprite_sheet_t **create_hud(elements_t *elements)
{
    sprite_sheet_t **sprite_tab = malloc(sizeof(sprite_sheet_t *) *
NB_HUD_SPRITE);

    sprite_tab[0] = sprite_factory(elements, define_sprite_param(
"asset/panneau_droit.png", 0, 0, define_rect(0, 0, 56, 216)));
    sfSprite_setPosition(sprite_tab[0]->sprite,
define_vectorf(WIDTH - 56, 48));
    return sprite_tab;
}
