/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

mem_t **init_mem(size_t x, size_t y)
{
    mem_t **mem = bcalloc(sizeof(mem_t *), x + 1);

    if (!mem)
        return NULL;
    for (size_t i = 0; i < x; i++) {
        mem[i] = bcalloc(sizeof(mem_t), y + 1);
        if (!mem[i])
            return NULL;
    }
    mem[x] = NULL;
    return mem;
}

static ncurses_t create_ncurses(ncurses_t ncur)
{
    ncur.alive = malloc(sizeof(int) * 4);
    ncur.nb_process = malloc(sizeof(int) * 4);
    ncur.arena.red = 0;
    ncur.arena.blue = 0;
    ncur.arena.green = 0;
    ncur.arena.yellow = 0;
    ncur.speed = 15000;
    return (ncur);
}

vm_t *create_vm(void)
{
    vm_t *result = bcalloc(sizeof(vm_t), 1);

    result->memory = init_mem(IDX_NBR, IDX_MOD);
    result->cycle.it_max = CYCLE_TO_DIE;
    result->ncur = create_ncurses(result->ncur);
    return result;
}
