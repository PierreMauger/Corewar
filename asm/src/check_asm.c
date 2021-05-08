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
    for (size_t len = 0; buffer[adv + 1] && buffer[adv] != '\n'; adv++, len++)
        if (len >= PROG_NAME_LENGTH)
            return 0;
    if (!bstrncmp(buffer + adv, COMMENT_CMD_STRING, 9))
        return 0;
    for (size_t len = 0; buffer[adv] && buffer[adv] != '\n'; adv++, len++)
        if (len >= COMMENT_LENGTH)
            return (0);
    for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    return adv;
}

size_t check_asm(char *buffer)
{
    size_t adv = 0;
    list_t *list = NULL;

    if (!buffer)
        return 0;
    adv = skip_header(buffer);
    adv = check_name(buffer, adv);
    list = get_command(buffer, adv);
    adv = check_command(list);
    return adv;
}
