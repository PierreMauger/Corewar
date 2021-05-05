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

size_t count_line_buff(char *buffer, size_t adv)
{
    size_t count_line = 0;

    while (buffer[adv]) {
        if (buffer[adv] == '\n')
            count_line++;
        adv++;
    }
    return (count_line + 1);
}

void go_to_next_name(size_t *i_name, size_t *sz_ft, char *buffer, size_t *adv)
{
    (*i_name)++;
    *sz_ft = 0;
    for (; buffer[*adv] && buffer[*adv - 1] != '\n'; (*adv)++);
    while (buffer[*adv] && (!(buffer[*adv] >= 'a' && buffer[*adv] <= 'z')))
        (*adv)++;
}

size_t check_name_fonc(char *buffer, size_t adv)
{
    size_t sz_ft = 0;
    size_t i_name = 0;
    char **stock_name = malloc(sizeof(char *) * (count_line_buff(buffer, adv)));

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
            return (0);
        go_to_next_name(&i_name, &sz_ft, buffer, &adv);
    }
    return (adv);
}