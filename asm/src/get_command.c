/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

command_t *create_com(char *buffer, size_t adv)
{
    command_t *com = malloc(sizeof(command_t));

    com->name = get_command_name(buffer, adv);
    if (!com->name)
        return NULL;
    adv += bstrlen(com->name);
    for (; buffer[adv] && (buffer[adv] == ' ' || buffer[adv] == ':'); adv++);
    com->params = get_command_params(buffer, adv);
    if (!com->params[0])
        return NULL;
    return com;
}

void print_elem(command_t *elem)
{
    bprintf("\e[34m%s \e[0m", elem->name);
    for (size_t i = 0; i < barray_len(elem->params); i++) {
        bprintf("\e[35m%s \e[0m", elem->params[i]);
    }
    bprintf("\n");
}

list_t *get_command(char *buffer, size_t adv)
{
    list_t *list = create_list();
    list_node_t *node = NULL;
    command_t *elem = NULL;

    for (; buffer[adv + 1] && buffer[adv] != '\n'; adv++);
    adv++;
    for (; buffer[adv]; adv++) {
        elem = create_com(buffer, adv);
        node = create_node((void *)elem);
        add_node(list, node);
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    }
    return list;
}
