/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

size_t verif_id(list_t *coord, ssize_t id)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;
    size_t nbr_time = 0;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        if (pars_temp->arg_n == id)
            nbr_time++;
    }
    return nbr_time;
}

bool verif_all_id(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        if (verif_id(coord, pars_temp->arg_n) > 1)
            return 1;
    }
    return 0;
}
