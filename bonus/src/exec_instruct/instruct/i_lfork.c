/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static bool exec_lfork(champion_t *champion,
process_t *process, unsigned int fork_to)
{
    list_node_t *node_temp = NULL;
    process_t *new_process = create_process(process);

    if (!new_process)
        return 1;
    increase_coord(new_process, fork_to);
    node_temp = create_node((void *)new_process);
    if (!node_temp)
        return 1;
    add_node(champion->process_list, node_temp);
    return 0;
}

int i_lfork(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned int fork_to = (unsigned int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, DIR_SIZE_INDEX);

    if (exec_lfork(champion, process, fork_to))
        return 1;
    increase_coord(process, T_ID + DIR_SIZE_INDEX);
    return 0;
}
