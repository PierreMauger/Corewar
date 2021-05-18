/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

size_t get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    size_t result = 0;

    for (size_t adv = 0; adv < size_to_get; adv++) {
        if (y >= IDX_MOD) {
            y %= IDX_MOD;
            x++;
            x %= IDX_NBR;
        }
        result |= GET_ACT_CASE(vm, x, y);
        if (adv + 1 != size_to_get)
            result <<= 8;
        y++;
    }
    return result;
}
