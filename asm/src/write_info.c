/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void write_info(int fd, command_t *com, list_t *list)
{
    int info = 0;
    int delay = 6;

    for (size_t i = 0; i < barray_len(com->params); i++, delay -= 2) {
        info = info >> delay;
        if (is_reg(com->params[i]))
            info += 1;
        if (is_dir(com, i, list))
            info += 2;
        if (is_ind(com, i, list))
            info += 3;
        info = info << delay;
    }
    write(fd, &info, 1);
}
