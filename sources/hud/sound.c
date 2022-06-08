/*
** EPITECH PROJECT, 2022
** sound
** File description:
** sound
*/

#include "../../includes/include_engine.h"
#include "../includes/include_all.h"
#include <SFML/Audio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

sfSound *sound_handler(void)
{
    sfSound *plop = sfSound_create();
    sfSoundBuffer *ploup = sfSoundBuffer_createFromFile("asset/pop_sound.ogg");
    sfSound_setBuffer(plop, ploup);
    return plop;
}

void play_sound(sfSound *plop, slide_bar_t *bar, float pit)
{
    sfSound_setVolume(plop, (bar->pos / 2));
    sfSound_setPitch(plop, 1.0 + pit);
    sfSound_play(plop);
}
