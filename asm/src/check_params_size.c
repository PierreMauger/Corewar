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

int is_reg(char *str)
{
    if (str[0] == 'r' && batoi(str + 1) <= REG_NUMBER && batoi(str + 1) > 0) {
        return 1;
    }
    return 0;
}

int is_label(command_t *com, size_t i, list_t *list)
{
    list_node_t *temp = NULL;
    command_t *temp_com = NULL;

    foreach(list->head, temp) {
        temp_com = (command_t *)temp->data;
        if (com->params[i][1] == ':' && temp_com->label &&
        !bstrcmp(temp_com->label, com->params[i] + 2))
            return 1;
    }
    return 0;
}

int is_dir(command_t *com, size_t i, list_t *list)
{
    if (com->params[i][0] == '%' && (is_num(com->params[i] + 1) ||
    is_label(com, i, list))) {
        return 1;
    }
    return 0;
}

int check_size(command_t *com, args_type_t *type, list_t *list)
{
    bool check = false;

    for (size_t i = 0; i < barray_len(com->params); i++, check = false) {
        if (is_reg(com->params[i]) && type[i] % 2 == T_REG)
            check = true;
        if (is_dir(com, i, list) && type[i] % 4 >= T_DIR)
            check = true;
        if (is_num(com->params[i]) && type[i] >= T_IND)
            check = true;
        if (check == false)
            return 0;
    }
    return 1;
}
