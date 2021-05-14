/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

unsigned int get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    unsigned int nbr_mem = 0;
    size_t coord_act = y;

    for (size_t i = 0; i < size_to_get; i++) {
        coord_act++;
        if (coord_act >= IDX_MOD) {
            coord_act %= IDX_MOD;
            x++;
            x %= IDX_NBR;
        }
        nbr_mem |= GET_ACT_CASE(vm, x, coord_act);
    }
    return nbr_mem;
}
