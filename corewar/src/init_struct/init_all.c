/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void init_champion(vm_t *vm, list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;
    champion_t *champ_temp = NULL;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        champ_temp = create_champion(pars_temp->arg_n,
            bstrdup(pars_temp->name));
    }
}

vm_t *init_all(list_t *coord, size_t dump)
{
    vm_t *vm = create_vm();

    if (!vm || !coord)
        return NULL;
    vm->dump = dump;
    set_id(coord);
    if (verif_all_id(coord))
        return NULL;
    init_champion(vm, coord);
    return vm;
}