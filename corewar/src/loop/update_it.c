/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void update_it(vm_t *vm)
{
    if (!vm)
        return;
    vm->cycle.current_it++;
    vm->cycle.it_total++;
    if (vm->cycle.current_it == vm->cycle.it_max) {
        vm->cycle.current_it = 0;
        vm->cycle.cycle_total++;
    }
}