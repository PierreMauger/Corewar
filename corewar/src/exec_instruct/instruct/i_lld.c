/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

int i_lld(vm_t *vm, champion_t *champion, process_t *process)
{
    if (vm && champion && process)
        return 0;
    return 1;
}
