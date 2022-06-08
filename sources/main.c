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

sfVector2f give_point_pos(sfVector3f vec, int angle, sfVector2i size,
int rotat)
{
    sfVector2f point;

    int temp[2] = {};
    float tmp;
    float rad = rotat * (3.14159265359/180);

    tmp = (vec.x * cos(rad)) + (vec.y * -sin(rad));
    temp[0] = (int)tmp;
    tmp = (vec.x * sin(rad)) + (vec.y * cos(rad));
    temp[1] = (int)tmp;
    vec.x = temp[0];
    vec.y = temp[1];
    point.x = (float)cos(angle/180.0) * vec.x - cos(angle/180.0) * vec.y ;
    point.y = (float)sin(angle/180.0) * vec.y + sin(angle/180.0) * vec.x -
vec.z ;
    return point;
}

elements_t *all_textures_paths(void)
{
    char *texture_path_list[] = {"asset/save_as.png", "asset/save.png",
"asset/engrenages.png", "asset/son.png", "asset/panneau_droit.png",
"asset/empty.png", "asset/barre_son.png", "asset/fleches_haut.png",
"asset/fleches_bas.png", "asset/fleches_droite.png",
"asset/fleches_gauche.png", "asset/tourne_gauche.png",
"asset/tourner_droite.png", "asset/file_button.png", "asset/open.png",
"asset/spe.png", "asset/quit.png", "asset/mini_fleche_bas.png",
"asset/mini_fleche_haut.png", "asset/mount.png", "asset/mount_iso.png",
"asset/flat.png", "asset/zoom.png", "asset/dezoom.png", "asset/aide.png",
"asset/eye.png", "\0"};
    char *font_path_list[] = {"asset/akhirtathun.ttf", "\0"};

    return init_elements(texture_path_list, font_path_list);
}

void events_launch(elements_t *elements, map *monde, hud_elements_t *hud)
{
    if (hud->buttons[6]->infos & CLICK_F)
        (write_key(elements, monde->path_temp, &monde->temp_path_index) ==
1) ? (save_as(monde->path_temp, monde, hud)) : (0 == 0);
    else {
        monde->path_temp[0] = 0;
        monde->temp_path_index = 0;
        event_keys(elements, hud, monde);
    }
}

void refresh_all(hud_elements_t *hud, framebuffer_t *fbr,
elements_t *elements, map *monde)
{
    refresh_framebuffer(fbr, elements);
    refresh_vertex_array(monde, elements, hud);
    refresh_hud(hud, elements, monde);
    refresh_elements(elements);
}

int main(int ac, char **av)
{
    elements_t *elements = all_textures_paths();
    framebuffer_t *fbr = init_framebuffer(define_vectori(WIDTH, HEIGHT));
    hud_elements_t *hud = init_hud_elements(elements);
    int ind = 0;
    char *path = malloc(sizeof(char) * 300);
    map *monde = init_map((ac == 2) ? (av[1]) : ("f"));
    sfSound *plop = sound_handler();
    while (sfRenderWindow_isOpen(elements->window)) {
        sfRenderWindow_clear(elements->window, sfBlack);
        draw_rect(fbr, define_rect(0, 0, WIDTH, HEIGHT), sfBlack);
        events_launch(elements, monde, hud);
        generate_array(monde, hud, fbr) ;
        tools(monde, elements, hud, plop);
        refresh_all(hud, fbr, elements, monde);
    }
    free_map(monde);
    close_elements(elements);
    return 0;
}