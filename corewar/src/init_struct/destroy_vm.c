/*
** EPITECH PROJECT, 2021
** cleaning func for vm
** File description:
** destroy_vm
*/

#include "corewar.h"

void destroy_vm(vm_t *vm)
{
    for (int i = 0; i != IDX_NBR; i++)
        free(vm->memory[i]);
    free(vm->memory);
    free(vm);
}