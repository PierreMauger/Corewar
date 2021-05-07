/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void update_process(process_t *process)
{
    process->current_it++;
    process->current_it %= process->goal_it;
}