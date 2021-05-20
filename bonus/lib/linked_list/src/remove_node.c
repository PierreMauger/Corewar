/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void remove_node(list_t *list, list_node_t *node)
{
    if (!node || !list)
        return;
    list->lenght--;
    if (node->last)
        node->last->next = node->next;
    else list->head = node->next;
    if (node->next)
        node->next->last = node->last;
    else list->tail = node->last;
    node->last = NULL;
    node->next = NULL;
}