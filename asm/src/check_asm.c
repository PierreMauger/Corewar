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

    for (; buffer[adv] && buffer[adv] == COMMENT_CHAR; adv++)
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    return adv;
}

size_t check_name(char *buffer, size_t adv)
{
    if (!bstrncmp(buffer + adv, NAME_CMD_STRING, 6))
        return 0;
    for (; buffer[adv + 1] && buffer[adv] != '\n'; adv++);
    adv++;
    if (!bstrncmp(buffer + adv, COMMENT_CMD_STRING, 9))
        return 0;
    for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    for (; buffer[adv + 1] && buffer[adv] != '\n'; adv++);
    adv++;
    return adv;
}

size_t check_asm(char *buffer)
{
    size_t adv = 0;

    if (!buffer)
        return 0;
    adv = skip_header(buffer);
    adv = check_name(buffer, adv);
    adv = check_command(buffer, adv);
    return adv;
}
