/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

int is_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
    }
    return 1;
}

int is_label(command_t *com, size_t i, list_t *list, int offset)
{
    list_node_t *temp = NULL;
    command_t *temp_com = NULL;

    foreach(list->head, temp) {
        temp_com = (command_t *)temp->data;
        if (com->params[i][offset] == ':' && temp_com->label &&
        !bstrcmp(temp_com->label, com->params[i] + offset + 1))
            return 1;
    }
    return 0;
}

int is_reg(char *str)
{
    if (str[0] == 'r' && batoi(str + 1) <= REG_NUMBER && batoi(str + 1) > 0) {
        return 1;
    }
    return 0;
}

int is_dir(command_t *com, size_t i, list_t *list)
{
    if (com->params[i][0] == '%' && (is_num(com->params[i] + 1) ||
    is_label(com, i, list, 1))) {
        return 1;
    }
    return 0;
}

int is_ind(command_t *com, size_t i, list_t *list)
{
    if (is_num(com->params[i]) || is_label(com, i, list, 0)) {
        return 1;
    }
    return 0;
}
