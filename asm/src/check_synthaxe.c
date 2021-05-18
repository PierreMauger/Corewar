/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void skip_comment(char *buffer, size_t *adv)
{
    for (; buffer[*adv] && buffer[*adv] != '\n'; (*adv)++);
}

int check_after_name(char *buffer, size_t *adv, char *param_name)
{
    *adv += bstrlen(param_name);
    if (buffer[*adv] == '"')
        return (1);
    for (; buffer[*adv] && buffer[*adv] != '"'; (*adv)++) {
        if (buffer[*adv] != ' ' && buffer[*adv] != '\t') {
            return (1);
        }
    }
    (*adv)++;
    return (0);
}

int go_to_name(char *buffer, size_t *adv, char *param_name)
{
    for (; buffer[*adv] && bstrncmp(
        buffer + *adv, param_name, bstrlen(param_name)) != 0; (*adv)++) {
        if (buffer[*adv] != ' ' && buffer[*adv] != '\t'
            && buffer[*adv] != '\n' && buffer[*adv] != ',') {
            return (1);
        }
    }
    return (0);
}

int check_new_line(char *buffer, size_t *adv)
{
    for (; buffer[*adv]; (*adv)++) {
        if (buffer[*adv] == '#')
            skip_comment(buffer, adv);
        if (buffer[*adv] != ' ' && buffer[*adv] != ','
            && buffer[*adv] != '\t' && buffer[*adv] != '\n') {
            return (1);
        }
    }
    return (0);
}