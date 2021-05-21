/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static size_t get_last_live(vm_t *vm)
{
    list_t *champion_list = vm->champion_list;
    list_node_t *temp = NULL;
    champion_t *champion = NULL;
    size_t last_live = 0;

    foreach(champion_list->head, temp) {
        champion = (champion_t *)temp->data;
        if (champion->alive_it > last_live) {
            last_live = champion->alive_it;
        }
    }
    return last_live;
}

static int check_lenght(vm_t *vm)
{
    champion_t *champion = NULL;

    if (vm->champion_list->lenght == 1) {
        champion = (champion_t *)vm->champion_list->head->data;
        bprintf("The player %d(%s) has won.\n", champion->id, champion->name);
        return 1;
    }
    return 0;
}

int delete_dead(vm_t *vm)
{
    list_t *champion_list = vm->champion_list;
    list_node_t *temp = NULL;
    champion_t *champion = NULL;
    size_t last_live = get_last_live(vm);

    foreach(champion_list->head, temp) {
        champion = (champion_t *)temp->data;
        if (!champion->is_alive && champion->alive_it < last_live) {
            destroy_champion(champion);
        }
        else if (!champion->is_alive && champion->alive_it == last_live) {
            bprintf("The player %d(%s) has won.\n",
                champion->id, champion->name);
            return 1;
        }
        else champion->is_alive = 0;
    }
    return check_lenght(vm);
}

int update_it(vm_t *vm)
{
    if (!vm)
        return 0;
    vm->cycle.current_it++;
    vm->cycle.it_total++;
    if (vm->cycle.current_it >= vm->cycle.it_max) {
        vm->cycle.current_it = 0;
        vm->cycle.cycle_total++;
        return delete_dead(vm);
    }
    return 0;
}