/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char *bstrncat_forced(char *dest, char *src, size_t size_base,
    size_t plus_size)
{
    size_t j = 0;

    if (!dest || !src)
        return NULL;
    for (; j < plus_size; j++)
        dest[size_base + j] = src[j];
    dest[size_base + j] = '\0';
    return dest;
}