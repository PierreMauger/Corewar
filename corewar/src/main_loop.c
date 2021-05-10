/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void process_loop(vm_t *vm, champion_t *champion)
{
    list_t *process_list = champion->process_list;
    list_node_t *temp = NULL;

    foreach(process_list->head, temp) {
        update_process((process_t *)temp->data);
        check_iteration(vm, (process_t *)temp->data);
    }
}

void champion_loop(vm_t *vm)
{
    list_t *champion_list = vm->champion_list;
    list_node_t *temp = NULL;

    foreach(champion_list->head, temp) {
        process_loop(vm, (champion_t *)temp->data);
    }
}
