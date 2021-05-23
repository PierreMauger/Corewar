/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void get_info_ncurses(vm_t *vm)
{
    list_t *champion_list = vm->champion_list;
    list_node_t *temp = NULL;
    champion_t *champion = NULL;
    size_t compt = 0;

    foreach(champion_list->head, temp) {
        champion = (champion_t *)temp->data;
        vm->ncur.alive[compt] = champion->alive_it;
        vm->ncur.nb_process[compt] = champion->process_list->lenght;
        compt++;
    }
}

static void count_proprio(mem_t mem, size_t *player)
{
    if (mem.proprio == 1)
        player[0]++;
    if (mem.proprio == 2)
        player[1]++;
    if (mem.proprio == 3)
        player[2]++;
    if (mem.proprio == 4)
        player[3]++;
}

static void display_encart(int y, int x)
{
    int stock = y + 1;

    mvprintw(y, x, "__________________________________________________");
    while (stock != y + 30) {
        mvprintw(stock, x, "|");
        stock++;
    }
    stock = y + 1;
    x += 50;
    while (stock != (y + 30)) {
        mvprintw(stock, x, "|");
        stock++;
    }
    x -= 49;
    mvprintw(stock, x, "__________________________________________________");
}

static void display_cycle(vm_t *vm, int y, int x, int nb_cycle)
{
    attron(A_BOLD);
    mvprintw(y + 4, x + 7, "=============== INFO ===============");
    attroff(A_BOLD);
    mvprintw(y + 7, x + 5, "Nombre de cycles : ");
    x += 19;
    attron(A_BOLD);
    mvprintw(y + 7, x + 5, "%d", nb_cycle);
    attroff(A_BOLD);
    x -= 19;
    mvprintw(y + 9, x + 5, "Cycles to die :");
    x += 14;
    attron(A_BOLD);
    mvprintw(y + 9, x + 5, "%ld", vm->cycle.it_max);
    x -= 14;
    attroff(A_BOLD);
    mvprintw(y + 11, x + 5, "Speed cycle :");
    x += 14;
    attron(A_BOLD);
    mvprintw(y + 11, x + 5, "%d", vm->ncur.speed);
    attroff(A_BOLD);
}

void display_info(vm_t *vm, int nb_cycle, int y, int x)
{
    size_t i = 0;
    size_t player[4] = {0};

    display_encart(y + 2, x);
    display_cycle(vm, y, x, nb_cycle);
    for (size_t compt = 0; compt < IDX_NBR; compt++) {
        for (i = 0; i < IDX_MOD; i++) {
            count_proprio(vm->memory[compt][i], player);
            if (vm->memory[compt][i].proprio == 4)
                player[3]++;
        }
    }
    display_nb_proprio(vm, player);
    display_nb_yellow(vm, player[3]);
}
