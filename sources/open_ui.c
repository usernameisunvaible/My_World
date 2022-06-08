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
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <SFML/Audio.h>

char **only_legend(char **map_list, int size)
{
    char **temp = malloc(sizeof(char *) * size);
    int tmp;
    int a = 0;

    for (int i = 0; i < size; ++i) {
        tmp = my_strlen(map_list[i]);
        if (comp_string(map_list[i] + tmp - 7, ".legend")) {
            temp[a] = malloc(sizeof(char) * my_strlen(map_list[i]) + 1);
            cp_name_map(temp[a], map_list[i]);
            ++a;
        }
    }
    temp[a] = malloc(sizeof(char));
    temp[a][0] = 0;
    return temp;
}

void generate_fil_buttons(char **file_list, elements_t *elements,
hud_elements_t *hud)
{
    int a = 0;
    while (file_list[a][0])
        ++a;
    hud->file_but = malloc(sizeof(button_t *) * a);
    hud->text_file_but = malloc(sizeof(sfText *) * a);
    hud->nb_file = a;
    for (int i = 0; i < a; ++i) {
        hud->file_but[i] = init_button(elements,
        define_button_params("asset/spe.png",
        define_rect(189, 40 * i + i, 400, 40), 0, 0));
        hud->text_file_but[i] = text_factory(define_text_params(file_list[i],
        "asset/akhirtathun.ttf", define_vectorf(189, 40 * i + 7), 25),
        elements);
        show_b(hud->file_but[i]);
    }
}

void open_the_map(hud_elements_t *hud, map *monde, int j)
{
    const char *file_name = sfText_getString(hud->text_file_but[j]);
    char *str = malloc(sizeof(char) * my_strlen(file_name) + 6);
    char folder[5] = "maps/";
    int a = 5;

    for (int i = 0; i < 5; ++i)
        str[i] = folder[i];
    for (int i = 0; i < my_strlen(file_name); ++i) {
        str[i + 5] = file_name[i];
        ++a;
    }
    str[a] = 0;
    monde = init_map(str);
}

void refresh_button(elements_t *elements, hud_elements_t *hud, map *monde)
{
    for (int i = 0; i < hud->nb_file; ++i) {
        show_button(hud->file_but[i], elements);
        refresh_text(elements, hud->text_file_but[i], "\0");
        if (hud->file_but[i]->infos & CLICK_F) {
            open_the_map(hud, monde, i);
            hide_b(hud->buttons[16]);
            hide_b(hud->buttons[5]);
            hide_b(hud->buttons[6]);
            hide_b(hud->buttons[15]);
            hide_b(hud->buttons[14]);
            unclick_b(hud->buttons[14]);
            unclick_b(hud->buttons[6]);
            unclick_b(hud->buttons[16]);
            hide_b(hud->buttons[17]);
            hud->nb_file = 0;
        }
    }
}

void open_ui(map *monde, elements_t *elements, hud_elements_t *hud)
{
    DIR *dp;
    struct dirent *dirp;
    int nb = 0;
    char **map_list;

    dp = opendir("maps/");
    while ((dirp = readdir(dp)) != NULL)
        ++nb;
    closedir(dp);
    map_list = malloc(sizeof(char *) * nb + 1);
    nb = 0;
    dp = opendir("maps/");
    while ((dirp = readdir(dp)) != NULL) {
        map_list[nb] = malloc(sizeof(char) * my_strlen(dirp->d_name) + 1);
        cp_name_map(map_list[nb], dirp->d_name);
        ++nb;
    }
    closedir(dp);
    map_list = only_legend(map_list, nb);
    generate_fil_buttons(map_list, elements, hud);
}