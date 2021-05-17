/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

size_t adv_to_next(size_t adv, unsigned char *buffer, size_t max)
{
    for (; adv < max && buffer[adv] == '\0'; adv++);
    if (adv == max)
        return 0;
    return adv;
}

size_t get_n_bytes(size_t adv, unsigned char *buffer, size_t max, int n)
{
    size_t result = 0;

    if (adv + n > max || n > 8)
        return 0;
    for (int act = 0; act < n; act++) {
        result |= buffer[adv + act];
        if (act + 1 != n)
            result <<= 8;
    }
    return result;
}

void write_mem(unsigned char **memory, unsigned char *champion,
    size_t adress, size_t len_champion)
{
    size_t x = 0;
    size_t y = 0;

    for (size_t adv = 0; adv < len_champion; adv++) {
        x = adress / IDX_MOD;
        y = adress % IDX_MOD;
        memory[x][y] = champion[adv];
    }
}
