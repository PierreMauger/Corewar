/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

process_t *create_process(process_t *base_process)
{
    process_t *process = bcalloc(1, sizeof(process_t));

    if (base_process) {
        process->coord_pc = base_process->coord_pc;
        for (size_t adv = 0; adv < REG_NUMBER; adv++) {
            process->reg[adv] = base_process->reg[adv];
        }
    }
    return process;
}
