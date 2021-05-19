/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

void destroy_list(list_t *list, void (*destroy_data)(void *data))
{
    list_node_t *node = NULL;
    list_node_t *temp = NULL;

    for (node = list->head; node; node = temp) {
        destroy_node(node, destroy_data);
        temp = node->next;
        free(node);
    }
    free(list);
}