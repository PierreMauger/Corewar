/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static void handle_nbr_live(vm_t *vm)
{
    static int nbr_live = 0;

    nbr_live++;
    if (nbr_live >= NBR_LIVE) {
        nbr_live = 0;
        if ((ssize_t)(vm->cycle.it_max - CYCLE_DELTA) <= 0)
            vm->cycle.it_max = 0;
        else vm->cycle.it_max -= CYCLE_DELTA;
    }
}

static champion_t *verif_id_live(unsigned int id, vm_t *vm)
{
    list_node_t *temp_node = NULL;
    champion_t *temp_champ = NULL;

    foreach(vm->champion_list->head, temp_node) {
        temp_champ = (champion_t *)temp_node->data;
        if (temp_champ->id == id) {
            return temp_champ;
        }
    }
    return NULL;
}

int i_live(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned int id_mem = get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, sizeof(int));
    champion_t *champ_id = NULL;

    increase_coord(process, T_ID + sizeof(int));
    champ_id = verif_id_live(id_mem, vm);
    if (!champ_id) {
        return 0;
    }
    bprintf("The player %d(%s) is alive.\n", id_mem, champ_id->name);
    handle_nbr_live(vm);
    champ_id->is_alive = 1;
    champ_id->alive_it = vm->cycle.it_total;
    return 0;
}
