/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void destroy_node(list_node_t *node)
{
    free(node->data);
    free(node);
}