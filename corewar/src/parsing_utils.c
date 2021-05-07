/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool check_read_accessibility(char *str)
{
    char *temp = NULL;

    if ((temp = bread_file(str, 20)) == NULL)
        return false;
    else {
        free(temp);
        return true;
    }
}

char **init_checking_flags(void)
{
    char **flags = binit_array_light(4);

    flags[0] = bstrdup("-dump");
    flags[1] = bstrdup("-n");
    flags[2] = bstrdup("-a");
    flags[3] = NULL;
    return flags;
}