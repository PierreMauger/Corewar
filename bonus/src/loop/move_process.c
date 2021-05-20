/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void increase_coord(process_t *process, size_t increase)
{
    process->coord_pc.y += increase;
    if (process->coord_pc.y >= IDX_MOD) {
        process->coord_pc.y %= IDX_MOD;
        process->coord_pc.x++;
        process->coord_pc.x %= IDX_NBR;
    }
}