/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

size_t get_command_name(char *buffer, size_t adv)
{
    size_t len = 0;

    for (; buffer[adv + len] && buffer[adv + len] !=  ' '; len++);
    for (int i = 0; i < 16; i++)
        if (!bstrncmp(buffer + adv, op_tab[i].mnemonique, len))
            return 0;
    return 1;
}

size_t check_command(char *buffer, size_t adv)
{
    // for (; buffer[adv]; adv++) {

    // }
    bprintf("%d\n", get_command_name(buffer, adv));
    return adv;
}
