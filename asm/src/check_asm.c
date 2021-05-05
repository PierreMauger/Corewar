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
    for (size_t len = 0; buffer[adv + 1] && buffer[adv] != '\n'; adv++, len++)
        if (len >= 128)
            return (0);
    adv++;
    if (!bstrncmp(buffer + adv, ".comment", 9))
        return 0;
    for (size_t len = 0; buffer[adv] && buffer[adv] != '\n'; adv++, len++)
        if (len >= 2048)
            return (0);
    for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    recup_all(buffer, adv);
    return adv;
}
