/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char *bstrndup_forced(char *src, size_t n)
{
    char *cp_src = malloc(sizeof(char) * (n + 1));
    size_t i = 0;

    if (!cp_src || !src)
        return NULL;
    for (; i < n; i++)
        cp_src[i] = src[i];
    cp_src[i] = '\0';
    return cp_src;
}
