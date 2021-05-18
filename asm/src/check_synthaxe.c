/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void skip_comment(char *buffer, size_t *adv)
{
    while (buffer[*adv] && buffer[*adv] != '\n')
        (*adv)++;
}

int check_new_line(char *buffer, size_t *adv)
{
    while (buffer[*adv]) {
        if (buffer[*adv] == '#')
            skip_comment(buffer, adv);
        if (buffer[*adv] != ' ' && buffer[*adv] != ','
            && buffer[*adv] != '\t' && buffer[*adv] != '\n') {
            return (1);
        }
        (*adv)++;
    }
    return (0);
}