/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void display_info(mem_t **mem, int nb_cycle, int y, int x)
{
    size_t i = 0;
    size_t red = 0;
    size_t blue = 0;

    mvprintw(y, x, "Nombre de cycle : ");
    x += 18;
    mvprintw(y, x, bitoa(nb_cycle));
    for (size_t compt = 0; compt < IDX_NBR; compt++) {
        for (i = 0; i < IDX_MOD; i++) {
            if (mem[compt][i].proprio == 1)
                red++;
            if (mem[compt][i].proprio == 2)
                blue++;
        }
    }
    x += 5;
    mvprintw(y, x, "Le joueur 1 a %d cases.", red);
    x += 28;
    mvprintw(y, x, "Le joueur 2 a %d cases.", blue);
}

void print_color_ncurses(int x, int y, mem_t mem)
{
    char *ret = NULL;
    int hex = mem.cas;

    if (mem.proprio == 1)
        attron(COLOR_PAIR(1));
    if (mem.proprio == 2)
        attron(COLOR_PAIR(2));
    ret = bitoa_base(hex, HEXA_BASE);
    if (bstrlen(ret) == 1)
        mvprintw(y, x, "0%s ", ret);
    else
        mvprintw(y, x, "%s ", ret);
    free(ret);
    if (mem.proprio == 1)
        attroff(COLOR_PAIR(1));
    if (mem.proprio == 2)
        attroff(COLOR_PAIR(2));
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
    size_t i = 0;
    int x = 20;
    int y = 2;

    clear();
    display_info(vm->memory, nb_cycle, 0, x);
    for (size_t compt = 0; compt < IDX_NBR; compt++) {
        while (i != IDX_MOD)
            print_mem_ncurse_spl(&x, &y, &i, vm->memory[compt]);
        i = 0;
    }
    refresh();
    usleep(70000);
}
