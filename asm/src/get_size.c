/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

int get_size_dir(command_t *com, size_t i, list_t *list, size_t name_id)
{
    if (is_num(com->params[i] + 1)) {
        if ((name_id >= 8 && name_id < 12) || name_id == 14 || name_id == 13)
            return 2;
        else
            return 4;
    }
    if (is_label(com, i, list))
        return 2;
    return 0;
}

int get_size(command_t *com, size_t i, list_t *list, size_t name_id)
{
    if (is_reg(com->params[i]))
        return 1;
    if (is_num(com->params[i]))
        return 2;
    if (is_dir(com, i, list))
        return get_size_dir(com, i, list, name_id);
    return 0;
}
