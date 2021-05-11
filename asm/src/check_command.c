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

size_t check_command(list_t *list)
{
    list_node_t *temp = NULL;
    size_t id = 0;

    foreach(list->head, temp) {
        id = get_id(((command_t *)temp->data)->name);
        if ((int)barray_len(((command_t *)temp->data)->params) !=
        op_tab[id].nbr_args)
            return 0;
        if (!check_size(((command_t *)temp->data)->params, op_tab[id].type,
        list))
            return 0;
    }
    return 1;
}
