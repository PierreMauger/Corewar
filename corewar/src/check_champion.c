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
    return 0;
}

void check_process(process_t *process)
{
    if (process->current_it == process->goal_it) {
        process->current_it = 0;
        process->goal_it = 0;
        // EXEC NEXT INSTRUCTION
    }
}