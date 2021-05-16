/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool verif_flag(char *flag)
{
    for (size_t adv = 0; flag[adv]; adv++) {
        if (flag[adv] < '0' || flag[adv] > '9') {
            return 1;
        }
    }
    return 0;
}

ssize_t get_n(char **argv, size_t adv)
{
    ssize_t result = 0;

    if (!argv || !adv || !argv[adv + 1])
        return -1;
    if (verif_flag(argv[adv + 1]))
        return -1;
    result = atoi(argv[adv + 1]);
    if (result <= 0)
        return -1;
    return result;
}

ssize_t get_a(char **argv, size_t adv)
{
    ssize_t result = 0;

    if (!argv || !adv || !argv[adv + 1])
        return -1;
    if (verif_flag(argv[adv + 1]))
        return -1;
    result = atoi(argv[adv + 1]);
    if (result < 0)
        return -1;
    return result;
}
