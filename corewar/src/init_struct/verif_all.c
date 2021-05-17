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

bool verif_file_name(parsing_t *pars_temp)
{
    size_t end = 0;

    for (size_t adv = 0; pars_temp && pars_temp->name[adv]; adv++) {
        if (!bstrncmp(pars_temp->name + adv,
            EXTENTION_FILE,
            bstrlen(EXTENTION_FILE)))
            end = adv;
    }
    if (end == 0)  {
        return 1;
    }
    return 0;
}

bool verif_all(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        if (verif_id(coord, pars_temp->arg_n) > 1 ||
            verif_file_name(pars_temp) ||
            verif_file(pars_temp))
            return 1;
    }
    return 0;
}

bool verif_champion_size(list_t *coord)
{
    // list_node_t *node_temp = NULL;
    // parsing_t *pars_temp1 = NULL;
    // parsing_t *pars_temp2 = NULL;

    // foreach(coord->head, node_temp) {
    //     pars_temp1 = (parsing_t *)node_temp->data;
    //     if (node_temp->next) {
    //         pars_temp2 = (parsing_t *)node_temp->next->data;
    //         if (pars_temp1->arg_a + pars_temp1->file->len )
    //     }
    // }
    // return 0;
}