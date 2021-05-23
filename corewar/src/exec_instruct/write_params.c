/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static int swap_endian_4(int val)
{
    return ((val & 0xff000000) >> 24) |
            ((val & 0x00ff0000) >> 8) |
            ((val & 0x0000ff00) << 8) |
            ((val & 0x000000ff) << 24);
}

void write_int_mem(vm_t *vm, coord_t coord, int to_write)
{
    int size = (int)sizeof(to_write);

    to_write = swap_endian_4(to_write);
    for (int adv = 0; adv < size; adv++, coord.y++) {
        if (coord.y >= IDX_MOD) {
            coord.x += (coord.y / IDX_MOD);
            coord.y %= IDX_MOD;
            coord.x %= IDX_NBR;
        }
        GET_ACT_CASE(vm, coord.x, coord.y) = (unsigned char)to_write;
        to_write >>= 8;
    }
}
