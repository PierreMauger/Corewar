/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static void handle_nbr_live(vm_t *vm, champion_t *champion, process_t *process)
{
    static int nbr_live = 0;

    nbr_live++;
    if (nbr_live == NBR_LIVE) {
        nbr_live = 0;
        vm->cycle.it_max -= CYCLE_DELTA;
    }
}

int i_live(vm_t *vm, champion_t *champion, process_t *process)
{
    if (vm && champion && process)
        return 0;
    handle_nbr_live(vm, champion, process);
    return 1;
}
// DONT FORGET TO SET LIVE IT