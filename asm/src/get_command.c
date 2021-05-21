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
        || buffer[*adv] == '\t'|| buffer[*adv] == '\n'; (*adv)++);
    // printf("\e[32m%s\e[0m\n", buffer + *adv);
    for (size_t len = 0; buffer[*adv + len] &&
    buffer[*adv + len] != ' ' && buffer[*adv + len] != '\t'; len++)
        if (buffer[*adv + len] == ':') {
            label = bstrndup(buffer + *adv, len);
            *adv += len + 1;
            for (; buffer[*adv] == '\n'; (*adv)++);
            // printf("\e[33m%s\e[0m\n", buffer + *adv);
            break;
        }
    return label;
}

static void skip_hash(char *buffer, size_t *adv)
{
    while (buffer[*adv] == '#') {
        for (; buffer[*adv] && buffer[*adv] != '\n'; (*adv)++);
        (*adv)++;
    }
}

command_t *create_com(char *buffer, size_t *adv)
{
    command_t *com = bcalloc(sizeof(command_t), 1);

    if (!com)
        return NULL;
    skip_hash(buffer, adv);
    com->label = get_label(buffer, adv);
    if (com->label && check_label(com->label))
        return NULL;
    com->name = get_command_name(buffer, adv);
    if (!com->name && com->label)
        return com;
    if (!com->name)
        return NULL;
    for (; buffer[*adv] && (buffer[*adv] == ' '
        || buffer[*adv] == ':' || buffer[*adv] == '\t'); (*adv)++);
    com->params = get_command_params(buffer, adv);
    if (!com->params)
        return NULL;
    return com;
}

void print_elem(command_t *elem)
{
    if (elem->name)
        bprintf("\e[34m%s \e[0m", elem->name);
    for (size_t i = 0; i < barray_len(elem->params); i++) {
        bprintf("\e[35m%s \e[0m", elem->params[i]);
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
        // printf("\e[32m> %s\e[0m\n", buffer + adv);
        elem = create_com(buffer, &adv);
        node = create_node((void *)elem);
        if (!elem || !node)
            return NULL;
        // print_elem(elem);
        add_node(list, node);
        check_new_line(buffer, &adv);
    }
    return list;
}
