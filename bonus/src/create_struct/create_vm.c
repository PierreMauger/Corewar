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

vm_t *create_vm(void)
{
    vm_t *result = bcalloc(sizeof(vm_t), 1);

    result->memory = init_mem(IDX_NBR, IDX_MOD);
    result->cycle.it_max = CYCLE_TO_DIE;
    return result;
}
