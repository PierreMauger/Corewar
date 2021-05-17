/*
** EPITECH PROJECT, 2021
** destroy file func
** File description:
** destroy_file
*/

#include "blib.h"

void destroy_file(file_t *file)
{
    free(file->file);
    free(file);
}