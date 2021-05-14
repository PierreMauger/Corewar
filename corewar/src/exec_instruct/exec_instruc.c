/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static int (*instruct[])(vm_t *, champion_t *, process_t *) = {
    i_live,
    i_ld,
    i_st,
    i_add,
    i_sub,
    i_and,
    i_or,
    i_xor,
    i_zjmp,
    i_ldi,
    i_sti,
    i_fork,
    i_lld,
    i_lldi,
    i_lfork,
    i_aff,
};

void increase_coord(process_t *process, size_t increase)
{
    process->coord_pc.y += increase;
    if (process->coord_pc.y >= IDX_MOD) {
        process->coord_pc.y %= IDX_MOD;
        process->coord_pc.x++;
    }
}

int exec_instruct(vm_t *vm, champion_t *champion, process_t *process)
{
    return instruct[process->id_instruct](vm, champion, process);
}