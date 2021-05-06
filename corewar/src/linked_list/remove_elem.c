/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

list_node_t *remove_elem(list_node_t *elem)
{
    if (!elem)
        return NULL;
    if (elem->last)
        elem->last->next = elem->next;
    if (elem->next)
        elem->next->last = elem->last;
    elem->last = NULL;
    elem->next = NULL;
    if (elem->last)
        return elem->last;
    else return elem->next;
    return elem;
}