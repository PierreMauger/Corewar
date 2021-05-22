/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void write_dir(int fd, command_t *com, size_t i, list_t *list)
{
    int res = batoi(com->params[i] + 1);
    int name_id = get_id(com->name);

    if (is_num(com->params[i] + 1)) {
        if (name_id >= 8 && name_id <= 14 && name_id != 12) {
            res = swap_endian_2(res);
            write(fd, &res, 2);
        }
        else {
            res = swap_endian_4(res);
            write(fd, &res, 4);
        }
    }
    if (is_label(com, i, list, 1))
        write_label(fd, com, com->params[i] + 2, list);
}

void write_ind(int fd, command_t *com, size_t i, list_t *list)
{
    int res = 0;

    if (is_num(com->params[i])) {
        res = batoi(com->params[i]);
        res = swap_endian_2(res);
        write(fd, &res, 2);
    }
    if (is_label(com, i, list, 0))
        write_label(fd, com, com->params[i] + 1, list);
}

void write_params(int fd, command_t *com, list_t *list)
{
    int res = 0;

    if (barray_len(com->params) != 1 || get_id(com->name) == 15)
        write_info(fd, com, list);
    for (size_t i = 0; i < barray_len(com->params); i++) {
        if (is_reg(com->params[i])) {
            res = batoi(com->params[i] + 1);
            write(fd, &res, 1);
        }
        if (is_ind(com, i, list))
            write_ind(fd, com, i, list);
        if (is_dir(com, i, list))
            write_dir(fd, com, i, list);
    }
}

void write_instructions(int fd, list_t *list)
{
    list_node_t *temp = NULL;
    command_t *com = NULL;
    size_t id = 0;

    foreach(list->head, temp) {
        com = (command_t *)temp->data;
        if (com->name) {
            id = get_id(com->name);
            write(fd, &op_tab[id].code, 1);
            write_params(fd, com, list);
        }
    }
}
