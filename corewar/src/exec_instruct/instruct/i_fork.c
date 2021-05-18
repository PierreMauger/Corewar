/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

int i_fork(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned int fork_to = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + 1, T_DIR);
    process_t *new_process = NULL;

    reset_it(process);
    new_process = create_process(process);
    if (!new_process)
        return 1;
    new_process->coord_pc.y += fork_to;
    new_process->coord_pc.y %= IDX_MOD;
    increase_coord(process, T_DIR + 1);
    return 0;
}
