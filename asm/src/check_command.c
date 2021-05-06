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

static int count_size_arg(char *buffer, size_t *adv)
{
    size_t compt = 0;
    int len = 0;

    if (buffer[*adv] == ',')
        (*adv)++;
    compt = *adv;
    while (buffer[compt] && buffer[compt] != ' ' && buffer[compt] != '\n') {
        compt++;
        len++;
    }
    return len;
}

static char *get_one_param(char *buffer, size_t *adv)
{
    size_t len = count_size_arg(buffer, adv);
    size_t fill_tab = 0;
    char *param = malloc(sizeof(char) * (len + 1));

    for (; buffer[*adv] && buffer[*adv] != ' ' && buffer[*adv] != '\n';
    (*adv)++, fill_tab++) {
        if (buffer[*adv] == ',')
            break;
        param[fill_tab] = buffer[*adv];
    }
    param[fill_tab] = '\0';
    return param;
}

char **get_command_params(char *buffer, size_t adv)
{
    char **params_tab = malloc(sizeof(char *) * MAX_ARGS_NUMBER);
    int i = 0;

    for (; buffer[adv] && buffer[adv] != '\n'; i++, adv++) {
        params_tab[i] = get_one_param(buffer, &adv);
        if (buffer[adv] == '\n') {
            i++;
            break;
        }
    }
    params_tab[i] = NULL;
    return params_tab;
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
    com->params = get_command_params(buffer, adv);
    elem->data = com;
    return elem;
}

size_t check_command(char *buffer, size_t adv)
{
    list_node_t *list = NULL;
    list_node_t *elem = NULL;

    for (; buffer[adv + 1] && buffer[adv] != '\n'; adv++);
    adv++;
    for (; buffer[adv]; adv++) {
        elem = create_elem(buffer, adv);
        // bprintf("\e[34m%s \e[35m%s\e[0m\n", ((command_t *)elem->data)->name, ((command_t *)elem->data)->params[0]);
        add_elem(list, elem);
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    }
    return adv;
}
