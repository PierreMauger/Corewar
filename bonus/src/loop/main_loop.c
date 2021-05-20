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

void print_ncurses(vm_t *vm)
{
    char *hex = NULL;

    for (size_t x = 0; x < IDX_NBR; x++) {
        if (x < 6) attron(COLOR_PAIR(1));
        else attron(COLOR_PAIR(2));
        for (size_t y = 0; y < IDX_MOD; y++) {
            hex = bitoa_base((int)GET_ACT_CASE(vm, x, y), HEXA_BASE);
            if (bstrlen(hex) == 1)
                printw("0%s ", hex);
            else printw("%s ", hex);
            free(hex);
            if ((y + 1) % 64 == 0)
                printw("\n");
        }
        if (x < 6) attroff(COLOR_PAIR(1));
        else attroff(COLOR_PAIR(2));
    }
    refresh();
    usleep(50000);
    clear();
}

void init_ncurses(void)
{
    initscr();
    noecho();
    if (!has_colors()) {
        endwin();
        exit (84);
    }
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

int vm_loop(vm_t *vm)
{
    int ret = 0;

    init_ncurses();
    while (!ret) {
        ret = champion_loop(vm);
        if (update_it(vm)) {
            endwin();
            return 0;
        }
        print_ncurses(vm);
        print_memory(vm);
    }
    endwin();
    return ret;
}