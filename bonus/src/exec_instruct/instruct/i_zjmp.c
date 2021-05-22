/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static void exec_zjmp(process_t *process, unsigned int jump)
{
    if (!process->carry) {
        increase_coord(process, T_ID + DIR_SIZE_INDEX);
        return;
    }
    process->coord_pc.y = (process->coord_pc.y + jump) % IDX_MOD;
}

int i_zjmp(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned int jump = (unsigned int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, DIR_SIZE_INDEX);

    exec_zjmp(process, jump);
    return 0;
}
