/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

list_t *create_list(void)
{
    list_t *result = bcalloc(sizeof(list_t), 1);

    return result;
}
