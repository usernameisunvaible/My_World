/*
** EPITECH PROJECT, 2022
** sound
** File description:
** sound
*/

#ifndef SOUND_HANDLING_H_
    #define SOUND_HANDLING_H_
    #include "../../includes/include_engine.h"
    #include <SFML/Audio.h>

sfSound *sound_handler(void);
void play_sound(sfSound *plop, slide_bar_t *bar, float pit);

#endif