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

size_t fill_parseur(char **argv, size_t adv, parsing_t *pars_temp)
{
    int act_flag = 0;

    for (int max = 0; argv[adv] && max < 3; max++) {
        act_flag = check_flag(argv[adv]);
        if (act_flag == -1) {
            pars_temp->name = bstrdup(argv[adv]);
            return adv;
        }
        else {
            if (flag[act_flag].get_flag(argv, adv, pars_temp))
                return 0;
            adv += 2;
        }
    }
    if (!pars_temp->name)
        return 0;
    return adv;
}

list_t *get_info_champion(char **argv, bool dump)
{
    list_t *result = create_list();
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    for (size_t adv = 1 + dump * 2; argv[adv]; adv++) {
        pars_temp = create_parsing(NULL, -1, -1);
        adv = fill_parseur(argv, adv, pars_temp);
        if (!adv)
            return NULL;
        node_temp = create_node((void *)pars_temp);
        if (!node_temp)
            return NULL;
        add_node(result, node_temp);
    }
    return result;
}
