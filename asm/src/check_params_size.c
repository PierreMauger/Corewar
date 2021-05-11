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
        if (str[i] < '0' || str[i] > '9')
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

int is_var(char *str, list_t *list)
{
    list_node_t *temp = NULL;

    foreach(list->head, temp) {
        if (str[0] == ':' && ((command_t *)temp->data)->var &&
        !bstrcmp(((command_t *)temp->data)->var, str + 1))
            return 1;
    }
    return 0;
}

int is_ind(char *str, list_t *list)
{
    if (str[0] == '%' && (is_num(str + 1) || is_var(str + 1, list))) {
        return 1;
    }
    return 0;
}

int check_size(char **params, args_type_t *type, list_t *list)
{
    bool check = false;

    for (size_t i = 0; i < barray_len(params); i++, check = false) {
        if (is_reg(params[i]) && type[i] % 2 != REG_SIZE)
            check = true;
        if (is_ind(params[i], list) && type[i] % 4 >= IND_SIZE)
            check = true;
        if (is_num(params[i]) && type[i] >= DIR_SIZE)
            check = true;
        if (check == false)
            return 0;
    }
    return 1;
}
