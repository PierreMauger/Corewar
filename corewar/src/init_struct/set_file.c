/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool set_file(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        pars_temp->file = bread_file(pars_temp->name, READ_SIZE);
        if (!pars_temp->file)
            return 1;
    }
    return 0;
}