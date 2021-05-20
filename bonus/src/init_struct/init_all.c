/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

process_t *init_process(parsing_t *pars_temp, champion_t *champ_temp)
{
    process_t *process_temp = create_process(NULL);

    if (!process_temp)
        return NULL;
    process_temp->coord_pc = (coord_t){
        pars_temp->arg_a / IDX_MOD,
        pars_temp->arg_a % IDX_MOD
    };
    process_temp->reg[r1] = champ_temp->id;
    return process_temp;
}

bool init_champion(vm_t *vm, parsing_t *pars_temp, champion_t *champ_temp)
{
    list_node_t *node_temp = NULL;
    process_t *process_temp = NULL;

    write_mem(vm->memory, (unsigned char *)pars_temp->file->file,
        pars_temp->arg_a, pars_temp->file->len);
    champ_temp->process_list = create_list();
    if (!champ_temp->process_list)
        return 1;
    process_temp = init_process(pars_temp, champ_temp);
    if (!process_temp)
        return 1;
    node_temp = create_node((void *)process_temp);
    if (!node_temp)
        return 1;
    add_node(champ_temp->process_list, node_temp);
    return 0;
}

bool get_coord(vm_t *vm, list_t *coord)
{
    list_node_t *node_temp1 = NULL;
    list_node_t *node_temp2 = NULL;
    parsing_t *pars_temp = NULL;
    champion_t *champ_temp = NULL;

    vm->champion_list = create_list();
    if (!vm->champion_list)
        return 1;
    foreach(coord->head, node_temp1) {
        pars_temp = (parsing_t *)node_temp1->data;
        champ_temp = create_champion(pars_temp->arg_n,
            bstrdup(pars_temp->name));
        if (!champ_temp || init_champion(vm, pars_temp, champ_temp))
            return 1;
        node_temp2 = create_node((void *)champ_temp);
        if (!node_temp2)
            return 1;
        add_node(vm->champion_list, node_temp2);
    }
    return 0;
}

vm_t *init_all(list_t *coord, size_t dump)
{
    vm_t *vm = create_vm();

    if (!vm || !coord || coord->lenght <= 1 || coord->lenght > MAX_CHAMP)
        return NULL;
    vm->dump = dump;
    if (set_all(coord) || verif_all(coord) ||
        verif_champion_size(coord) ||
        get_coord(vm, coord)) {
        vm = NULL;
    }
    destroy_list(coord, destroy_parsing);
    return vm;
}
