/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

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

void print_color_ncurses(int x, int y, mem_t mem)
{
    if (mem.proprio == 0 && mem.id_process == 1)
        attron(COLOR_PAIR(1));
    if (mem.proprio == 1 && mem.id_process == 1)
        attron(COLOR_PAIR(2));
    if (mem.id_process == 1)
        attron(A_BOLD);
    mvprintw(y, x, "%s ", mem.cas);
    if (mem.proprio == 0 && mem.id_process == 1)
        attroff(COLOR_PAIR(1));
    if (mem.proprio == 1 && mem.id_process == 1)
        attroff(COLOR_PAIR(2));
    if (mem.id_process == 1)
        attroff(A_BOLD);
}

void display_info(mem_t **mem, int nb_cycle, int y, int x)
{
    size_t i = 0;
    size_t compt = 0;
    size_t red = 0;
    size_t blue = 0;

    mvprintw(y, x, "Nombre de cycle : ");
    x += 18;
    mvprintw(y, x, bitoa(nb_cycle));
    for (; mem[compt] != NULL; compt++) {
        for (; mem[compt][i].cas != NULL; i++) {
            if (mem[compt][i].proprio == 0) red++;
            if (mem[compt][i].proprio == 1) blue++;
        }
        i = 0;
    }
    x += 5;
    mvprintw(y, x, "Le joueur 1 a %d cases.", red);
    x += 28;
    mvprintw(y, x, "Le joueur 2 a %d cases.", blue);
}

static void print_mem_ncurse_spl(int *x, int *y, size_t *i, mem_t *mem)
{
    print_color_ncurses(*x, *y, mem[*i]);
    (*i)++;
    if (*i == 513) {
        mvprintw(*y, *x, "\n");
        *x = 20;
    }
    else if (*i % 64 == 0) {
        mvprintw(*y, *x, "\n");
        *y += 1;
        *x = 20;
    }
    else
        *x += 3;
}

void print_mem_ncurse(vm_t *vm, int nb_cycle)
{
    mem_t **mem = NULL;
    size_t i = 0;
    size_t compt = 0;
    int x = 20;
    int y = 2;

    mem = init_mem(mem);
    clear();
    display_info(mem, nb_cycle, 0, x);
    while (mem[compt] != NULL) {
        while (mem[compt][i].cas != NULL)
            print_mem_ncurse_spl(&x, &y, &i, mem[compt]);
        i = 0;
        compt++;
    }
    refresh();
    usleep(70000);
}