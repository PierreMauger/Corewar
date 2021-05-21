/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void write_int_mem(vm_t *vm, size_t x, size_t y, int to_write)
{
    int size = (int)sizeof(to_write);

    for (int adv = 0; adv < size; adv++) {
        GET_ACT_CASE(vm, x, (y + adv) % IDX_MOD) = (unsigned char)to_write;
        to_write >>= 8;
    }
}
