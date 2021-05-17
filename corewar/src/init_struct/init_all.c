/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool init_champion(vm_t *vm, list_t *coord)
{
    list_node_t *node_temp = NULL;
    parsing_t *pars_temp = NULL;
    champion_t *champ_temp = NULL;

    foreach(coord->head, node_temp) {
        pars_temp = (parsing_t *)node_temp->data;
        champ_temp = create_champion(pars_temp->arg_n,
            bstrdup(pars_temp->name));
        if (!champ_temp)
            return 1;
        write_mem(vm->memory, pars_temp->file->file,
            pars_temp->arg_a, pars_temp->file->len);
        champ_temp->process_list = create_list();
    }
}
// NEED SOME SPLIT

vm_t *init_all(list_t *coord, size_t dump)
{
    vm_t *vm = create_vm();

    if (!vm || !coord || coord->lenght <= 1)
        return NULL;
    vm->dump = dump;
    if (!set_all(coord) && !verif_all(coord) && !verif_champion_size(coord))
        if (init_champion(vm, coord)) {
            destroy_all(vm);
            vm = NULL;
        }
    else {
        destroy_all(vm);
        vm = NULL;
    }
    destroy_list(coord, destroy_parsing);
    return vm;
}
