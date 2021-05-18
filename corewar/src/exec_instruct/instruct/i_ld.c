/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static int dir_ld(vm_t *vm, champion_t *champion, process_t *process)
{
    // unsigned int pos = get_param(vm, process->coord_pc.x,
    //     process->coord_pc.y + ID_SIZE + INFO_SIZE, DIR_SIZE);
    // unsigned int reg = get_param(vm, process->coord_pc.x,
    //     process->coord_pc.y + DIR_SIZE + INFO_SIZE, REG_SIZE);

    // if (pos >= IDX_MOD ||reg >= REG_NUMBER) {
    //     vm->carry = 0;
    //     return 0;
    // }
    return 0;
}

static int ind_ld(vm_t *vm, champion_t *champion, process_t *process)
{
    return 0;
}

int i_ld(vm_t *vm, champion_t *champion, process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);

    if (indicator << 2 != 1) {
        vm->carry = 0;
        return 0;
    }
    // if (temp & BIT_DIR == BIT_DIR) {
    //     return dir_ld(vm, champion, process);
    // }
    // else {
    //     return ind_ld(vm, champion, process);
    // }
    return 0;
}
