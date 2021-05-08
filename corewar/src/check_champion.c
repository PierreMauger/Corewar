/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void check_process(process_t *process)
{
    if (process->current_it == process->goal_it) {
        process->current_it = 0;
        // EXEC NEXT INSTRUCTION
    }
}