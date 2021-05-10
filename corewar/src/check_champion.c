/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

int check_op(unsigned char index_value)
{
    for (int adv = 0; op_tab[adv].code; adv++) {
        if (op_tab[adv].code == index_value) {
            return adv;
        }
    }
    return -1;
}

void check_case(vm_t *vm, process_t *process)
{
    int instruct_nbr = 0;

    // INCREASE POS
    instruct_nbr = check_op(GET_CASE(vm, process));
    if (instruct_nbr != -1) {
        process->id_instruct = op_tab[instruct_nbr].code;
    }
}

void check_iteration(vm_t *vm, process_t *process)
{
    if (process->goal_it == 0) {
        check_case(vm, process);
    }
    else if (process->current_it == process->goal_it) {
        process->current_it = 0;
        process->goal_it = 0;
        // EXEC NEXT INSTRUCTION
    }
}