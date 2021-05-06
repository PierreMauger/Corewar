/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

list_node_t *create_node(void *data)
{
    list_node_t *result = bcalloc(sizeof(list_node_t), 1);

    if (data) {
        result->data = data;
    }
    return result;
}