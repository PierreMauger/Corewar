/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

int i_aff(vm_t *vm, champion_t *champion, process_t *process)
{
    unsigned int reg = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_REG);

    increase_coord(process, T_ID + T_REG);
    if (reg >= REG_NUMBER)
        return 0;
    bprintf("%c", process->reg[reg] % 256);
    return 0;
}
