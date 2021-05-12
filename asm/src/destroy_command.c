/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void destroy_command(void *com)
{
    command_t *temp = (command_t *)com;

    if (!temp)
        return;
    if (temp->params)
        bfree_array(temp->params);
    if (temp->label)
        free(temp->label);
    if (temp->name)
        free(temp->name);
}
