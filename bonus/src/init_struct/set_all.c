/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void set_id(list_t *coord, parsing_t *pars_temp)
{
    static ssize_t act_id = 1;

    if (pars_temp->arg_n == -1) {
        for (; verif_id(coord, act_id); act_id++);
        pars_temp->arg_n = act_id;
        act_id++;
    }
}

bool set_file(parsing_t *pars_temp)
{
    pars_temp->file = bread_file_len(pars_temp->name, READ_SIZE);
    if (!pars_temp->file || !pars_temp->file->file || !pars_temp->file->len) {
        if (pars_temp->file)
            free(pars_temp->file);
        return 1;
    }
    return 0;
}

void set_coord_champion(parsing_t *pars_temp, size_t espacement)
{
    static size_t it = 0;

    if (pars_temp->arg_a == -1) {
        pars_temp->arg_a = it * espacement;
        it++;
    }
}

bool set_all(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;
    size_t espacement = MEM_SIZE / coord->lenght;

    if (!espacement)
        return 1;
    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        set_id(coord, pars_temp);
        set_coord_champion(pars_temp, espacement);
        if (set_file(pars_temp))
            return 1;
    }
    return 0;
}
