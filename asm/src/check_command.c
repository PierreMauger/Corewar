/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

char *get_command_name(char *buffer, size_t adv)
{
    size_t len = 0;

    for (; buffer[adv + len] && buffer[adv + len] !=  ' ' && buffer[adv + len] !=  ':'; len++);
    for (int i = 0; i < 16; i++)
        if (!bstrncmp(buffer + adv, op_tab[i].mnemonique, len))
            return bstrdup(op_tab[i].mnemonique);
    return NULL;
}

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

static char **stock_arg_in_tab(char *buffer, size_t adv)
{
    int i = 0;
    char **stock_arg_d = malloc(sizeof(char *) * 4);

    while (buffer[adv] && buffer[adv] != '\n') {
        stock_arg_d[i] = get_one_arg(buffer, &adv, stock_arg_d[i]);
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

list_node_t *create_elem(char *buffer, size_t adv)
{
    list_node_t *elem = malloc(sizeof(list_node_t));
    command_t *com = malloc(sizeof(command_t));

    com->name = get_command_name(buffer, adv);
    if (!com->name)
        return NULL;
    adv += bstrlen(com->name);
    for (; buffer[adv] && (buffer[adv] == ' ' || buffer[adv] == ':'); adv++);
    com->params = stock_arg_in_tab(buffer, adv);
    elem->data = com;
    return elem;
}

size_t check_command(char *buffer, size_t adv)
{
    list_node_t *list = NULL;
    list_node_t *elem = NULL;

    for (; buffer[adv + 1] && buffer[adv] != ':'; adv++);
    adv++;
    for (; buffer[adv]; adv++) {
        elem = create_elem(buffer, adv);
        add_elem(list, elem);
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    }
    return adv;
}
