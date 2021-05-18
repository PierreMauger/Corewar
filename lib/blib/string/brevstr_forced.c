/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 26/03/2021
*/

#include "blib.h"

char *brevstr_forced(char *src, size_t size_str)
{
    size_t size = size_str;
    char c;

    size_str--;
    for (size_t i = 0; i < size / 2; i++) {
        c = src[i];
        src[i] = src[size_str];
        src[size_str] = c;
        size_str--;
    }
    return src;
}
