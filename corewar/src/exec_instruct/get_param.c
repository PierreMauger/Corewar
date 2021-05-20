/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool verif_nbr_param(unsigned char indicator, int nbr_param)
{
    if ((unsigned char)(indicator << (nbr_param * 2)) != 0)
        return 1;
    return 0;
}

bool verif_act_param(unsigned char indicator, int pos, int info)
{
    if (((indicator << (pos * 2)) & I_INFO) == info)
        return 1;
    return 0;
}

void write_int_mem(vm_t *vm, size_t x, size_t y, int to_write)
{
    int size = (int)sizeof(to_write);

    for (int adv = 0; adv < size; adv++) {
        GET_ACT_CASE(vm, x, (y + adv) % IDX_MOD) = (unsigned char)to_write;
        to_write >>= 8;
    }
}

size_t get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    size_t result = 0;

    for (size_t adv = 0; adv < size_to_get; adv++) {
        if (y >= IDX_MOD) {
            x += ((y / IDX_MOD) - x);
            y %= IDX_MOD;
            x %= IDX_NBR;
        }
        result |= GET_ACT_CASE(vm, x, y);
        if (adv + 1 != size_to_get)
            result <<= 8;
        y++;
    }
    return result;
}
