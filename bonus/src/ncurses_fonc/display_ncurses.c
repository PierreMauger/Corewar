/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void print_color_ncurses(int x, int y, mem_t mem)
{
    char *ret = NULL;
    int hex = mem.cas;

    find_color(mem);
    ret = bitoa_base(hex, HEXA_BASE);
    if (bstrlen(ret) == 1)
        mvprintw(y, x, "0%s ", ret);
    else
        mvprintw(y, x, "%s ", ret);
    free(ret);
    del_color(mem);
}

static void print_mem_ncurse_spl(int *x, int *y, size_t *i, mem_t *mem)
{
    print_color_ncurses(*x, *y, mem[*i]);
    (*i)++;
    if (*i == 513) {
        *x = (COLS / 2) - (64 + 64);
    }
    else if (*i % 64 == 0) {
        *y += 1;
        *x = COLS / 2 - (64 + 64);
    }
    else
        *x += 3;
}

void print_mem_ncurse(vm_t *vm, int nb_cycle, int scroll)
{
    size_t i = 0;
    int x = (COLS / 2) - (64 + 64);
    int y = 2;

    clear();
    display_info(vm, nb_cycle, 0, ((COLS / 2) + (70)));
    for (size_t compt = scroll; compt < IDX_NBR; compt++) {
        while (i != IDX_MOD)
            print_mem_ncurse_spl(&x, &y, &i, vm->memory[compt]);
        i = 0;
    }
    refresh();
    usleep(70000);
}
