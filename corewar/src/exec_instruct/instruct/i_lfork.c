/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

int i_lfork(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned int fork_to = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_DIR);
    process_t *new_process = NULL;

    new_process = create_process(process);
    if (!new_process)
        return 1;
    increase_coord(new_process, fork_to);
    increase_coord(process, T_ID + T_DIR);
    return 0;
}
