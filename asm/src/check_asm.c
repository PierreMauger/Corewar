/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

list_t *check_asm(char *buffer)
{
    size_t adv = 0;
    list_t *list = NULL;

    if (!buffer)
        return 0;
    adv = skip_head(buffer);
    adv = check_header(buffer, adv);
    if (adv) {
        list = get_command(buffer, adv);
        if (!list)
            return NULL;
        adv = check_command(list);
    }
    return list;
}
