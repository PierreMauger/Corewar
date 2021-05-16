/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static const flag_t flag[] = {
    {"-n", get_n},
    {"-a", get_a},

    {NULL, NULL}
};

list_t *get_info_champion(char **argv)
{
    list_t *result = create_list();
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    for (size_t adv = 0; argv[adv]; adv++) {

    }
}
