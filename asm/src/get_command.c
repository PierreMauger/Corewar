/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

char *get_label(char *buffer, size_t *adv)
{
    char *label = NULL;

    for (; buffer[*adv] == ' ' || buffer[*adv] == ','
        || buffer[*adv] == '\t'; (*adv)++);
    for (size_t temp = 0; buffer[*adv + temp] &&
    buffer[*adv + temp] != ' ' && buffer[*adv + temp] != '\t'; temp++)
        if (buffer[*adv + temp] == ':') {
            label = bstrndup(buffer + *adv, temp);
            for (; buffer[*adv] && buffer[*adv - 1] != ':'; (*adv)++);
            for (; buffer[*adv] == ',' || buffer[*adv] == ' '
                || buffer[*adv] == '\t'; (*adv)++);
            for (; buffer[*adv] && buffer[*adv] == '\n'; (*adv)++);
        }
    return label;
}

command_t *create_com(char *buffer, size_t *adv)
{
    command_t *com = malloc(sizeof(command_t));

    if (!com)
        return NULL;
    while (buffer[*adv] == '#') {
        for (; buffer[*adv] && buffer[*adv] != '\n'; (*adv)++);
        (*adv)++;
    }
    com->label = get_label(buffer, adv);
    if (com->label && check_label(com->label))
        return NULL;
    com->name = get_command_name(buffer, adv);
    if (!com->name)
        return NULL;
    *adv += bstrlen(com->name);
    for (; buffer[*adv] && (buffer[*adv] == ' '
        || buffer[*adv] == ':' || buffer[*adv] == '\t'); (*adv)++);
    com->params = get_command_params(buffer, *adv);
    if (com->params == NULL)
        return NULL;
    return com;
}

void print_elem(command_t *elem)
{
    bprintf("\e[34m%s \e[0m", elem->name);
    for (size_t i = 0; i < barray_len(elem->params); i++) {
        bprintf("\e[35m%s->\e[0m", elem->params[i]);
    }
    bprintf("\e[31m%s\e[0m", elem->label);
    bprintf("\n");
}

list_t *get_command(char *buffer, size_t adv)
{
    list_t *list = create_list();
    list_node_t *node = NULL;
    command_t *elem = NULL;

    if (!list)
        return NULL;
    while (buffer[adv]) {
        elem = create_com(buffer, &adv);
        node = create_node((void *)elem);
        if (!elem || !node)
            return NULL;
        add_node(list, node);
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
        check_new_line(buffer, &adv);
    }
    return list;
}
