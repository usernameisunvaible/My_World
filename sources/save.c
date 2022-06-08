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

void save(char *path, int **map, sfVector2i map_size)
{

    FILE *map_file;
    int tmp;

    map_file = fopen(path, "w");
    fwrite(&map_size.x, sizeof(int), 1, map_file);
    fwrite(&map_size.y, sizeof(int), 1, map_file);
    for (int i = 0; i != map_size.y; ++i) {
        for (int j = 0; j != map_size.x; ++j)
            fwrite(&map[i][j], sizeof(int), 1, map_file);
    }
    fclose(map_file);
}
