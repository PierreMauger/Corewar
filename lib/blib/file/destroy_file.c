/*
** EPITECH PROJECT, 2021
** destroy file func
** File description:
** destroy_file
*/

#include "blib.h"

void destroy_file(file_t *file)
{
    if (!file)
        return;
    if (file->file)
        free(file->file);
    free(file);
}
