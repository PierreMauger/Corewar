/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

vm_t *init_vm(int champ_count, char **argv)
{
    vm_t *vm = NULL;

    vm = create_vm();
    if (!vm)
        return NULL;
    vm->champion_list = store_champ_arguments(argv, vm, champ_count);
    if (vm->champion_list == NULL)
        return NULL;
    return vm;
}