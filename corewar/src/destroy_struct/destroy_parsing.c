/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void destroy_parsing(void *parsing)
{
    parsing_t *parsing_cast = (parsing_t *)parsing;

    if (!parsing_cast)
        return;
    free(parsing_cast->name);
}