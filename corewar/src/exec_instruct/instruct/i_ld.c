/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static void dir_ld(vm_t *vm, champion_t *champion, process_t *process)
{

}

static void ind_ld(vm_t *vm, champion_t *champion, process_t *process)
{

}

int i_ld(vm_t *vm, champion_t *champion, process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + 1, 1);
    unsigned char temp = indicator >> 4;

    if (temp & BIT_REG != BIT_REG) {
        vm->carry = 0;
        return 0;
    }
    temp = indicator >> 6;
    if (temp & BIT_DIR == BIT_DIR) {
        dir_ld(vm, champion, process);
    }
    else {
        ind_ld(vm, champion, process);
    }
}

11 01 00 00
10 01 00 00