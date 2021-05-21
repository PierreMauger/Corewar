/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

int process_loop(vm_t *vm, champion_t *champion)
{
    list_t *process_list = champion->process_list;
    list_node_t *temp = NULL;
    int ret = 0;

    foreach(process_list->head, temp) {
        ret = check_iteration(vm, champion, (process_t *)temp->data);
        if (ret)
            return ret;
    }
    return 0;
}

int champion_loop(vm_t *vm)
{
    list_t *champion_list = vm->champion_list;
    list_node_t *temp = NULL;
    int ret = 0;

    foreach(champion_list->head, temp) {
        ret = process_loop(vm, (champion_t *)temp->data);
        if (ret)
            return ret;
    }
    return 0;
}

int vm_loop(vm_t *vm)
{
    int ret = 0;

    init_ncurses();
    for (int cycle = 0; !ret; cycle++) {
        print_mem_ncurse(vm, cycle);
        ret = champion_loop(vm);
        if (update_it(vm)) {
            endwin();
            return 0;
        }
        print_memory(vm);
    }
    endwin();
    return ret;
}
