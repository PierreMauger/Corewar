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

    instruct_nbr = check_op(GET_CASE(vm, process));
    if (instruct_nbr != -1) {
        process->id_instruct = instruct_nbr;
        process->goal_it = op_tab[instruct_nbr].nbr_cycles;
    }
    else move_process(vm, process);
}

void check_iteration(vm_t *vm, champion_t *champion, process_t *process)
{
    if (process->goal_it == 0) {
        check_case(vm, process);
    }
    else if (process->current_it == process->goal_it) {
        process->current_it = 0;
        process->goal_it = 0;
        exec_instruct(vm, champion, process);
    }
    else {
        process->current_it++;
    }
}
