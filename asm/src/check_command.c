/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

size_t get_id(char *name)
{
    for (size_t i = 0; i < 16; i++)
        if (!bstrcmp(name, op_tab[i].mnemonique))
            return i;
    return 0;
}

int check_label(char *label)
{
    size_t j = 0;

    for (size_t i = 0; label[i]; i++) {
        for (j = 0; j < bstrlen(LABEL_CHARS); j++)
            if (label[i] == LABEL_CHARS[j])
                break;
        if (j == bstrlen(LABEL_CHARS))
            return 1;
    }
    return 0;
}

size_t check_command(list_t *list)
{
    list_node_t *temp = NULL;
    command_t *temp_com = NULL;
    size_t id = 0;

    foreach(list->head, temp) {
        temp_com = (command_t *)temp->data;
        if (temp_com->name) {
            id = get_id(temp_com->name);
            if ((int)barray_len(temp_com->params) != op_tab[id].nbr_args)
                return 0;
            if (!check_size(temp_com, op_tab[id].type, list))
                return 0;
        }
    }
    return 1;
}
