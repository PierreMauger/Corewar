/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void update_process(process_t *process)
{
    process->current_it++;
    process->current_it %= process->goal_it;
}

void update_champion(champion_t *champion)
{
    list_t *process_list = champion->process_list;
    list_node_t *temp = NULL;

    foreach(process_list->head, temp) {
        update_process((process_t *)temp->data);
    }
}

void update_vm(vm_t *vm)
{
    list_t *champion_list = vm->champion_list;
    list_node_t *temp = NULL;

    foreach(champion_list->head, temp) {
        update_champion((champion_t *)temp->data);
    }
}
