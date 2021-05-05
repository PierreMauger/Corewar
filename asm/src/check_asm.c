/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

size_t skip_header(char *buffer)
{
    size_t adv = 0;

    for (; buffer[adv] && buffer[adv] == '#'; adv++)
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    return adv;
}

size_t check_asm(char *buffer)
{
    size_t adv = 0;

    if (!buffer)
        return 0;
    adv = skip_header(buffer);
    if (!bstrncmp(buffer + adv, ".name", 6))
        return 0;
    for (; buffer[adv + 1] && buffer[adv] != '\n'; adv++);
    adv++;
    if (!bstrncmp(buffer + adv, ".comment", 9))
        return 0;
    for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    return adv;
}
