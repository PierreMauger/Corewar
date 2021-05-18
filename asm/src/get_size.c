/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

int get_size_dir(char *param, list_t *list, size_t name_id)
{
    if (is_num(param + 1)) {
        if (name_id >= 8 && name_id < 12)
            return 2;
        else
            return 4;
    }
    if (is_label(param + 1, list))
        return 2;
    return 0;
}

int get_size(char *param, list_t *list, size_t name_id)
{
    if (is_reg(param))
        return 1;
    if (is_num(param))
        return 2;
    if (is_dir(param, list))
        return get_size_dir(param, list, name_id);
    return 0;
}
