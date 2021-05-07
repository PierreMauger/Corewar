/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

list_node_t *add_node(list_node_t *actual, list_node_t *node)
{
    list_node_t *temp = NULL;

    if (!actual || !node)
        return NULL;
    temp = actual->next;
    actual->next = node;
    node->last = actual;
    node->next = temp;
    if (temp)
        temp->last = node;
    return node;
}