/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void *add_elem(void *actual, void *elem)
{
    void *temp = NULL;

    if (!actual || !elem)
        return NULL;
    temp = actual->next;
    actual->next = elem;
    elem->last = actual;
    elem->next = temp;
    if (temp)
        temp->before = elem;
    return elem;
}