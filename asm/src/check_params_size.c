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
    if (str[0] == 'r' && batoi(str + 1) <= REG_NUMBER && batoi(str + 1) > 0)
        return 1;
    return 0;
}

int check_size(char **params, args_type_t *type)
{
    for (size_t i = 0; i < barray_len(params); i++) {
        if (is_reg(params[i]) && type[i] % 2 != 1)
            return 0;
        if (params[i][0] == '%' && type[i] % 4 < 2)
            return 0;
        if (is_num(params[i]) && type[i] < 4)
            return 0;
    }
    return 1;
}
