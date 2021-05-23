/*
** EPITECH PROJECT, 2021
** file creating func
** File description:
** create_file
*/

#include "blib.h"

file_t *create_file(size_t buff_size, size_t len)
{
    file_t *ret = bcalloc(1, sizeof(file_t));

    if (!ret)
        return NULL;
    ret->file = bcalloc(sizeof(char), buff_size);
    if (!ret->file) {
        free(ret);
        return NULL;
    }
    ret->len = len;
    return ret;
}
