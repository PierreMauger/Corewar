/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void remove_node(list_node_t *node)
{
    if (!node)
        return;
    if (node->last)
        node->last->next = node->next;
    if (node->next)
        node->next->last = node->last;
    node->last = NULL;
    node->next = NULL;
}