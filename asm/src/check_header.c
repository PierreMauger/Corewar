/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

size_t skip_head(char *buffer)
{
    size_t adv = 0;

    if (buffer[adv] == COMMENT_CHAR) {
        for (; buffer[adv] && buffer[adv] == COMMENT_CHAR; adv++)
            for (; buffer[adv] && buffer[adv] != '\n'; adv++);
        for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    }
    return adv;
}

size_t check_name(char *buffer, size_t adv, char *param_name, int param_len)
{
    if (go_to_name(buffer, &adv, param_name) == 1)
        return 0;
    if (!bstrncmp(buffer + adv, param_name, bstrlen(param_name) + 1))
        return 0;
    if (check_after_name(buffer, &adv, param_name) == 1)
        return 0;
    for (size_t len = 0; buffer[adv] && buffer[adv] != '"'; adv++, len++) {
        if (buffer[adv] == '\n')
            return 0;
        if (len >= (size_t)param_len)
            return 0;
    }
    adv++;
    return adv;
}

size_t check_header(char *buffer, size_t adv)
{
    adv = check_name(buffer, adv, NAME_CMD_STRING, PROG_NAME_LENGTH);
    if (!adv)
        return (0);
    check_new_line(buffer, &adv);
    adv = check_name(buffer, adv, COMMENT_CMD_STRING, COMMENT_LENGTH);
    if (adv) {
        check_new_line(buffer, &adv);
    }
    return adv;
}
