/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void destroy_list(list_t *list)
{
    list_node_t *temp = NULL;

    foreach(list->head, temp) {
        destroy_node(temp);
    }
    free(list);
}