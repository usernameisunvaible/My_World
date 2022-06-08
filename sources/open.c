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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void free_file_buttons(hud_elements_t *hud)
{
    for (int i = 0; i < hud->nb_file; ++i) {
        free_button(hud->file_but[i]);
    }
}

void cp_name_map(char *out, char *in)
{
    int i = 0;
    for (; in[i]; ++i) {
        out[i] = in[i];
    }
    out[i] = 0;
}

int comp_string(char *a, char *b)
{
    if (my_strlen(a) != my_strlen(b))
        return 0;
    for (int i = 0; a[i]; ++i) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void open_file(const char *path, map *monde)
{
    FILE *open_map;
    int x;
    int y;

    open_map = fopen(path, "r");
    fread(&x, sizeof(int), 1, open_map);
    fread(&y, sizeof(int), 1, open_map);
    int **pas = malloc(sizeof(int *) * y);
    for (int i = 0; i < y; ++i) {
        pas[i] = malloc(sizeof(int) * x);
        for (int j = 0; j < x; ++j)
            fread(&pas[i][j], sizeof(int), 1, open_map);
    }
    fclose(open_map);
    monde->map = pas;
    monde->size = define_vectori(x, y);
}
