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
    if (parsing_cast->name)
        free(parsing_cast->name);
    if (parsing_cast->file)
        destroy_file(parsing_cast->file);
}
