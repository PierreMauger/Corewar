/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

char *get_command_name(char *buffer, size_t adv)
{
    size_t len = 0;

    for (; buffer[adv + len] && buffer[adv + len] !=  ' ' && buffer[adv + len] !=  ':'; len++);
    for (int i = 0; i < 16; i++)
        if (!bstrncmp(buffer + adv, op_tab[i].mnemonique, len))
            return bstrdup(op_tab[i].mnemonique);
    return NULL;
}
