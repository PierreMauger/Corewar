/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void increase_coord(process_t *process, ssize_t increase)
{
    ssize_t x = process->coord_pc.x;
    ssize_t y = process->coord_pc.y;

    nbr_to_coord(&x, &y, increase);
    process->coord_pc.x = x;
    process->coord_pc.y = y;
}

void nbr_to_coord(ssize_t *x, ssize_t *y, ssize_t increase)
{
    *y += increase;
    if (*y >= IDX_MOD) {
        *x += (*y / IDX_MOD);
        *y %= IDX_MOD;
        *x %= IDX_NBR;
    }
    else if (*y < 0) {
        (*x)--;
        *x += (*y / IDX_MOD);
        *y %= IDX_MOD;
        *y += IDX_MOD;
        *x %= IDX_NBR;
        for (; *x < 0; *x += IDX_NBR);
    }
}