/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

int check_size(command_t *com, args_type_t *type, list_t *list)
{
    bool check = false;

    for (size_t i = 0; i < barray_len(com->params); i++, check = false) {
        if (is_reg(com->params[i]) && type[i] % 2 == T_REG)
            check = true;
        if (is_dir(com, i, list) && type[i] % 4 >= T_DIR)
            check = true;
        if (is_ind(com, i, list) && type[i] >= T_IND)
            check = true;
        if (check == false)
            return 0;
    }
    return 1;
}
