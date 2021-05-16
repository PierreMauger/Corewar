/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

parsing_t *create_champion(char *name, ssize_t arg_n, ssize_t arg_a)
{
    parsing_t *result = bcalloc(sizeof(parsing_t), 1);

    if (result) {
        result->name = bstrdup(name);
        result->arg_n = arg_n;
        result->arg_a = arg_a;
    }
    return result;
}
