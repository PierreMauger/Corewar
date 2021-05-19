/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

int i_ld(vm_t *vm, champion_t *champion, process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);

    if (indicator << 2 != 1) {
        process->carry = 0;
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
