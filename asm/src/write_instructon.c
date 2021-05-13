/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void write_params(int fd, command_t *com, list_t *list)
{
    for (size_t i = 0; i < barray_len(com->params); i++) {
        if (is_reg(com->params[i]))
            bdprintf(fd, "%c", (char)batoi(com->params[i] + 1));
        if (is_num(com->params[i]))
            bdprintf(fd, "%d", batoi(com->params[i]));
        if (is_dir(com->params[i], list))
            /* different dir sizes (with labels) */;
    }
}

void write_instructions(int fd, list_t *list)
{
    list_node_t *temp = NULL;
    command_t *com = NULL;
    size_t id = 0;

    foreach(list->head, temp) {
        com = (command_t *)temp->data;
        id = get_id(com->name);
        bdprintf(fd, "%c", op_tab[id].code);
        write_params(fd, com, list);
    }
}
