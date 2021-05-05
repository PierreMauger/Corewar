/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char **barray_cpy(char **dest, char **src)
{
    for (size_t adv = 0; src[adv]; adv++) {
        dest[adv] = src[adv];
    }
    return dest;
}
