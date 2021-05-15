/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void write_dir(int fd, char *param, size_t name_id, list_t *list)
{
    int res = batoi(param);

    if (is_num(param)) {
        if (name_id > 9 && name_id < 13) {
            res = swap_endian_2(res);
            write(fd, &res, 2);
        }
        else {
            res = swap_endian_4(res);
            write(fd, &res, 4);
        }
    }
    if (is_label(param, list))
        write(fd, "\0\0", 2);
}

void write_params(int fd, command_t *com, list_t *list)
{
    int res = 0;

    if (barray_len(com->params) != 1)
        write_info(fd, com, list);
    for (size_t i = 0; i < barray_len(com->params); i++) {
        if (is_reg(com->params[i]))
            bdprintf(fd, "%c", (char)batoi(com->params[i] + 1));
        if (is_num(com->params[i])) {
            res = batoi(com->params[i]);
            res = swap_endian_2(res);
            write(fd, &res, 2);
        }
        if (is_dir(com->params[i], list))
            write_dir(fd, com->params[i] + 1, get_id(com->name), list);
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
