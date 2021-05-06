/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

static int count_size_arg(char *buffer, size_t *adv, int len)
{
    size_t compt;

    if (buffer[*adv] == 44)
        (*adv)++;
    compt = *adv;
    while (buffer[compt] && buffer[compt] != ' ' && buffer[compt] != '\n') {
        compt++;
        len++;
    }
    return (len);
}

static char *get_one_arg(char *buffer, size_t *adv, char *stock_arg_one)
{
    size_t len = 0;
    size_t fill_tab = 0;

    len = count_size_arg(buffer, adv, len);
    stock_arg_one = malloc(sizeof(char) * (len + 1));
    while (buffer[*adv] && buffer[*adv] != ' ' && buffer[*adv] != '\n') {
        if (buffer[*adv] == 44)
            break;
        stock_arg_one[fill_tab] = buffer[*adv];
        (*adv)++;
        fill_tab++;
    }
    stock_arg_one[fill_tab] = '\0';
    return (stock_arg_one);
}

static char **stock_arg_in_tab(char *buffer, size_t adv, char **stock_arg_d)
{
    int i = 0;

    stock_arg_d = malloc(sizeof(char *) * 4);
    while (buffer[adv] && buffer[adv] != '\n') {
        stock_arg_d[i] = get_one_arg(buffer, &adv, stock_arg_d[i]);
        bprintf("\e[31m%s\e[0m\n", stock_arg_d[i]);
        if (buffer[adv] == '\n') {
            i++;
            break;
        }
        adv++;
        i++;
    }
    stock_arg_d[i] = NULL;
    return (stock_arg_d);
}

int get_arg(char *buffer, size_t adv, char **stock_name, char ***stock_arg)
{
    size_t i_tab = 0;

    bprintf("\e[33m%s\e[0m\n", buffer + adv);
    while (buffer[adv]) {
        while ((bstrncmp(buffer + adv, stock_name[i_tab],
            bstrlen(stock_name[i_tab])) != 0) && buffer[adv])
            adv++;
        adv += bstrlen(stock_name[i_tab]);
        for (; buffer[adv] && buffer[adv] == ' '; adv++);
        bprintf("\e[32m%s\e[0m\n", buffer + adv);
        stock_arg[i_tab] = stock_arg_in_tab(buffer, adv, stock_arg[i_tab]);
        i_tab++;
        if (stock_name[i_tab] == NULL)
            break;
    }
    stock_arg[i_tab] = NULL;
    return (0);
}
