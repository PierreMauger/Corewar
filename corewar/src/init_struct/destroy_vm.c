/*
** EPITECH PROJECT, 2021
** cleaning func for vm
** File description:
** destroy_vm
*/

#include "corewar.h"

void destroy_vm(vm_t *vm)
{
    bfree_array((char **)vm->memory);
    free(vm);
}