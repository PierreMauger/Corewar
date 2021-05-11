/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

char *variable_name(char *buffer, size_t *adv)
{
    char *var = NULL;

    for (size_t temp = 0; buffer[*adv + temp] && buffer[*adv + temp] != '\n' &&
    buffer[*adv + temp] != ' '; temp++)
    if (buffer[*adv + temp] == ':') {
        var = bstrndup(buffer + *adv, temp);
        for (; buffer[*adv] && buffer[*adv - 1] != ':'; (*adv)++);
        for (; buffer[*adv] && buffer[*adv] == ' '; (*adv)++);
    }
    return var;
}

command_t *create_com(char *buffer, size_t adv)
{
    command_t *com = malloc(sizeof(command_t));

    com->var = variable_name(buffer, &adv);
    com->name = get_command_name(buffer, adv);
    if (!com->name)
        return NULL;
    adv += bstrlen(com->name);
    for (; buffer[adv] && (buffer[adv] == ' ' || buffer[adv] == ':'); adv++);
    com->params = get_command_params(buffer, adv);
    if (com->params == NULL)
        return NULL;
    return com;
}

void print_elem(command_t *elem)
{
    bprintf("\e[34m%s \e[0m", elem->name);
    for (size_t i = 0; i < barray_len(elem->params); i++) {
        bprintf("\e[35m%s \e[0m", elem->params[i]);
    }
    bprintf("\e[31m%s\e[0m", elem->var);
    bprintf("\n");
}

list_t *get_command(char *buffer, size_t adv)
{
    list_t *list = create_list();
    list_node_t *node = NULL;
    command_t *elem = NULL;

    while (buffer[adv]) {
        elem = create_com(buffer, adv);
        if (elem == NULL)
            return (NULL);
        node = create_node((void *)elem);
        add_node(list, node);
        print_elem(elem);
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
        for (; buffer[adv] && buffer[adv] == '\n'; adv++);
    }
    return list;
}