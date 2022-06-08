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

char *int_into_str(const int nbr)
{
    char *buf;
    int cp = nbr;
    int len = 0;

    while (cp > 0) {
        cp = cp / 10;
        ++len;
    }
    cp = nbr;
    buf = malloc(sizeof(char) * len + 1);
    for (int i = 0; i < len; ++i) {
        buf[len - i - 1] = cp % 10 + 48;
        cp = cp / 10;
    }
    buf[len] = 0;
    return buf;
}