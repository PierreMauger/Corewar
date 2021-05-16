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

bool get_n(char **argv, size_t adv, parsing_t *pars)
{
    ssize_t result = 0;

    if (!argv || !adv || !argv[adv + 1] || pars->arg_a != -1)
        return 1;
    if (verif_flag(argv[adv + 1]))
        return 1;
    result = atoi(argv[adv + 1]);
    if (result <= 0)
        return 1;
    pars->arg_n = result;
    return 0;
}

bool get_a(char **argv, size_t adv, parsing_t *pars)
{
    ssize_t result = 0;

    if (!argv || !adv || !argv[adv + 1] || pars->arg_a != -1)
        return 1;
    if (verif_flag(argv[adv + 1]))
        return 1;
    result = atoi(argv[adv + 1]);
    if (result < 0)
        return 1;
    pars->arg_a = result;
    return 0;
}

size_t get_dump(int argc, char **argv)
{
    if (argc <= 1 || bstrcmp(argv[1], "-dump"))
        return 0;
    return batoi(argv[2]);
}