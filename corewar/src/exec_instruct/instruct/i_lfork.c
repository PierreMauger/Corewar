/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static bool lfork_to(vm_t *vm, process_t *process)
{
    unsigned int fork_to = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO, T_DIR);
    process_t *new_process = create_process(process);

    if (!new_process)
        return 1;
    increase_coord(new_process, fork_to);
    increase_coord(process, T_ID + T_INFO + T_DIR);
    return 0;
}

int i_lfork(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);

    if (verif_nbr_param(indicator, 1) || (indicator & I_INFO) != I_DIR) {
        increase_coord(process, T_ID);
        return 0;
    }
    if (lfork_to(vm, process))
        return 1;
    return 0;
}
