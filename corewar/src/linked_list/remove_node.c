/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

list_node_t *remove_node(list_node_t *node)
{
    if (!node)
        return NULL;
    if (node->last)
        node->last->next = node->next;
    if (node->next)
        node->next->last = node->last;
    node->last = NULL;
    node->next = NULL;
    if (node->last)
        return node->last;
    else return node->next;
    return node;
}