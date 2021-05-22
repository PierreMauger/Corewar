/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static void count_proprio(mem_t mem, size_t *red, size_t *blue, size_t *green)
{
    if (mem.proprio == 1)
        (*red)++;
    if (mem.proprio == 2)
        (*blue)++;
    if (mem.proprio == 3)
        (*green)++;
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
    mvprintw(y + 10, x + 5, "Cycles max :");
    x += 14;
    attron(A_BOLD);
    mvprintw(y + 10, x + 5, "%ld", vm->cycle.it_max);
    x -= 14;
    attroff(A_BOLD);
    mvprintw(y + 12, x + 5, "Speed cycle :");
    x += 14;
    attron(A_BOLD);
    mvprintw(y + 12, x + 5, "%d", vm->ncur.speed);
    attroff(A_BOLD);
}

void display_info(vm_t *vm, int nb_cycle, int y, int x)
{
    size_t i = 0;
    size_t red = 0;
    size_t blue = 0;
    size_t green = 0;
    size_t yellow = 0;

    display_encart(y + 2, x);
    display_cycle(vm, y, x, nb_cycle);
    for (size_t compt = 0; compt < IDX_NBR; compt++) {
        for (i = 0; i < IDX_MOD; i++) {
            count_proprio(vm->memory[compt][i], &red, &blue, &green);
            if (vm->memory[compt][i].proprio == 4)
                yellow++;
        }
    }
    display_nb_proprio(vm, red, blue, green);
    display_nb_yellow(vm, yellow);
    attroff(A_BOLD);
}