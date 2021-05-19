/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static void aff(vm_t *vm, process_t *process)
{
    unsigned int reg = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO, T_REG);

    increase_coord(process, T_ID + T_INFO + T_REG);
    if (reg >= REG_NUMBER)
        return;
    bprintf("%c", process->reg[reg] % 256);
}

int i_aff(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);

    if (verif_nbr_param(indicator, 1) || (indicator & I_INFO) != I_REG) {
        increase_coord(process, T_ID);
        return 0;
    }
    aff(vm, process);
    return 0;
}
