/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static const flag_t flag[] = {
    {"-n", 2, get_n},
    {"-a", 2, get_a},

    {NULL, 0, NULL}
};

int check_flag(char *act_case)
{
    int result = 0;

    for (; flag[result].flag; result++) {
        if (!bstrncmp(flag[result].flag, act_case, flag[result].len_flag)) {
            return result;
        }
    }
    return -1;
}

list_t *get_info_champion(char **argv)
{
    list_t *result = create_list();
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    for (size_t adv = 0; argv[adv]; adv++) {

    }
}
