/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void add_node(list_t *list, list_node_t *node)
{
    if (!node || !list)
        return;
    list->lenght++;
    if (!list->tail) {
        list->head = node;
        list->tail = node;
        return;
    }
    node->last = list->tail;
    list->tail->next = node;
    list->tail = node;
}