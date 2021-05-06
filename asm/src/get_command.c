/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

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
    if (!com->params[0])
        return NULL;
    elem->data = com;
    return elem;
}

void print_elem(command_t *elem)
{
    bprintf("\e[34m%s \e[0m", elem->name);
    for (size_t i = 0; i < barray_len(elem->params); i++) {
        bprintf("\e[35m%s \e[0m", elem->params[i]);
    }
    bprintf("\n");
}

size_t get_command(char *buffer, size_t adv)
{
    list_node_t *list = NULL;
    list_node_t *elem = NULL;

    for (; buffer[adv + 1] && buffer[adv] != '\n'; adv++);
    adv++;
    for (; buffer[adv]; adv++) {
        elem = create_elem(buffer, adv);
        // print_elem((command_t *)elem->data);
        add_elem(list, elem);
        for (; buffer[adv] && buffer[adv] != '\n'; adv++);
    }
    return adv;
}
