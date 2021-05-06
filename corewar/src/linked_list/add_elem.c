/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

list_node_t *add_elem(list_node_t *actual, list_node_t *elem)
{
    list_node_t *temp = NULL;

    if (!actual || !elem)
        return NULL;
    temp = actual->next;
    actual->next = elem;
    elem->last = actual;
    elem->next = temp;
    if (temp)
        temp->last = elem;
    return elem;
}