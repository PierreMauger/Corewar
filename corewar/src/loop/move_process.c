/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void move_process(process_t *process)
{
    process->coord_pc.y++;
    process->coord_pc.y %= IDX_MOD;
    !process->coord_pc.y ? process->coord_pc.x++ : 0;
    process->coord_pc.x %= IDX_NBR;
}