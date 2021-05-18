/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

int i_zjmp(__attribute__((unused))vm_t *vm,
    __attribute__((unused))champion_t *champion, process_t *process)
{
    unsigned int jump_to = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + 1, T_DIR);

    reset_it(process);
    if (!jump_to || !vm->carry) {
        increase_coord(process, T_DIR + 1);
        return 0;
    }
    increase_coord(process, jump_to);
    return 0;
}
