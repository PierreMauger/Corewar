/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void destroy_all(vm_t *vm)
{
    if (!vm)
        return;
    if (vm->champion_list)
        destroy_list(vm->champion_list, destroy_champion);
    destroy_vm(vm);
}
