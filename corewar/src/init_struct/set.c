/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void set_id(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;
    ssize_t act_id = 1;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        if (pars_temp->arg_n == -1) {
            for (; verif_id(coord, act_id); act_id++);
            pars_temp->arg_n = act_id;
            act_id++;
        }
    }
}

bool set_file(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        pars_temp->file = bread_file_len(pars_temp->name, READ_SIZE);
        if (!pars_temp->file || !pars_temp->file->file ||
            !pars_temp->file->len)
            return 1;
        // printf("%ld\n", pars_temp->file->len);
    }
    return 0;
}

bool set_name(list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;
    char *temp = NULL;
    size_t start = 0;
    size_t end = 0;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        for (size_t adv = 0; pars_temp && pars_temp->name[adv]; adv++) {
            if (pars_temp->name[adv] == '/')
                start = adv;
            if (!bstrncmp(pars_temp->name + adv, ".cor", bstrlen(".cor")))
                end = adv;
        }
        temp = bstrndup(pars_temp->name + start + 1, end - (start + 1));
        free(pars_temp->name);
        pars_temp->name = temp;
        if (end == 0)
            return 1;
    }
    return 0;
}