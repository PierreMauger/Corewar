/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

char *get_tab(char *buffer, size_t adv, size_t sz_ft, char *get_name)
{
    size_t index_tab = 0;

    while (op_tab[index_tab].mnemonique != NULL) {
        if (bstrncmp(buffer + adv, op_tab[index_tab].mnemonique, sz_ft)) {
            get_name = bstrndup(buffer + adv, sz_ft);
            return (get_name);
        }
        index_tab++;
    }
    return (NULL);
}

void go_to_next_name(size_t *i_name, size_t *sz_ft, char *buffer, size_t *adv)
{
    (*i_name)++;
    *sz_ft = 0;
    for (; buffer[*adv] && buffer[*adv - 1] != '\n'; (*adv)++);
    while (buffer[*adv] && (!(buffer[*adv] >= 'a' && buffer[*adv] <= 'z')))
        (*adv)++;
}

int check_name_fonc(char *buffer, size_t adv, char **stock_name)
{
    size_t sz_ft = 0;
    size_t i_name = 0;

    for (; buffer[adv] && buffer[adv] != ':'; adv++);
    adv += 1;
    for (; buffer[adv] && (buffer[adv] == ' ' || buffer[adv] == '\n'); adv++);
    while (buffer[adv]) {
        while ((buffer[adv + sz_ft] >= 'a' && buffer[adv + sz_ft] <= 'z')
            && buffer[adv + sz_ft])
            sz_ft++;
        stock_name[i_name] = get_tab(buffer, adv, sz_ft, stock_name[i_name]);
        adv += sz_ft;
        if (stock_name[i_name] == NULL)
            return (-1);
        go_to_next_name(&i_name, &sz_ft, buffer, &adv);
    }
    return (0);
}