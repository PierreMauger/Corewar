/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

vm_t *create_vm(void)
{
    vm_t *result = bcalloc(sizeof(vm_t), 1);

    result->cycle.it_max = CYCLE_TO_DIE;
    return result;
}