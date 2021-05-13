/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static const void(*instruct[])(vm_t *, champion_t *, process_t *) = {
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

void exec_instruct(vm_t *vm, champion_t *champion, process_t *process)
{
    instruct[process->id_instruct](vm, champion, process);
}