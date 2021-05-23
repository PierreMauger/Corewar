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

void write_int_mem(vm_t *vm, champion_t *champion, info_size_t pos, int to_write)
{
    int size = (int)sizeof(to_write);

    if (pos.adv >= IDX_MOD) {
        pos.size_read += (pos.adv / IDX_MOD);
        pos.adv %= IDX_MOD;
        pos.size_read %= IDX_NBR;
    }
    pos.adv += pos.inf;
    to_write = swap_endian_4(to_write);
    for (int adv = 0; adv < size; adv++, pos.adv++) {
        if (pos.adv >= IDX_MOD) {
            pos.size_read += (pos.adv / IDX_MOD);
            pos.adv %= IDX_MOD;
            pos.size_read %= IDX_NBR;
        }
        GET_ACT_CASE(vm, pos.size_read, pos.adv) =
        (unsigned char)to_write;
        GET_ACT_PROCESS(vm, pos.size_read, pos.adv) = champion->id;
        to_write >>= 8;
    }
}
