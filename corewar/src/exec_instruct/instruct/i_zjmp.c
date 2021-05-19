/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static void jump_to(vm_t *vm, process_t *process)
{
    unsigned int jump = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO, T_DIR);

    if (!jump || !process->carry) {
        increase_coord(process, T_ID + T_INFO + T_DIR);
        return;
    }
    process->carry = 1;
    increase_coord(process, jump);
}

int i_zjmp(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);

    if (verif_nbr_param(indicator, 1) || (indicator & I_INFO) != I_DIR) {
        increase_coord(process, T_ID);
        return 0;
    }
    jump_to(vm, process);
    return 0;
}
