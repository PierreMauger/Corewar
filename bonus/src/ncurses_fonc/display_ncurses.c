/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static void display_arena_split(int x, int y, vm_t *vm)
{
    if (vm->ncur.arena.blue > 0) {
        attron(COLOR_PAIR(2));
        mvprintw(y, x, "%.2f%%", (vm->ncur.arena.blue / MEM_SIZE) * 100);
        attroff(COLOR_PAIR(2));
        x += 8;
    }
    if (vm->ncur.arena.green > 0) {
        attron(COLOR_PAIR(3));
        mvprintw(y, x, "%.2f%%", (vm->ncur.arena.green / MEM_SIZE) * 100);
        attroff(COLOR_PAIR(3));
        x += 8;
    }
    if (vm->ncur.arena.yellow > 0) {
        attron(COLOR_PAIR(4));
        mvprintw(y, x, "%.2f%%", (vm->ncur.arena.yellow / MEM_SIZE) * 100);
        attroff(COLOR_PAIR(4));
    }
}

static void display_arena(vm_t *vm)
{
    int x = (COLS / 2) + (70 + 6);
    int y = 30;

    mvprintw(y - 2, x, "---------- Arena distribution ----------");
    mvprintw(y, x, "%.2f%%", (vm->ncur.arena.white / MEM_SIZE) * 100);
    x += 8;
    if (vm->ncur.arena.red > 0) {
        attron(COLOR_PAIR(1));
        mvprintw(y, x, "%.2f%%", (vm->ncur.arena.red / MEM_SIZE) * 100);
        attroff(COLOR_PAIR(1));
        x += 8;
    }
    display_arena_split(x, y, vm);
    vm->ncur.arena.white = 0;
    vm->ncur.arena.red = 0;
    vm->ncur.arena.blue = 0;
    vm->ncur.arena.green = 0;
    vm->ncur.arena.yellow = 0;
}

void print_color_ncurses(int x, int y, mem_t mem)
{
    char *ret = NULL;
    int hex = mem.cas;

    find_color(mem);
    ret = bitoa_base(hex, HEXA_BASE);
    if (bstrlen(ret) == 1)
        mvprintw(y, x, "0%s", ret);
    else
        mvprintw(y, x, "%s", ret);
    free(ret);
    del_color(mem);
    mvprintw(y, x + 2, " ");
}

static int print_mem_ncurse_spl(int *x, int *y, size_t *i, mem_t *mem)
{
    int color = 0;

    color = mem[*i].proprio;
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
    return (color);
}

void print_mem_ncurse(vm_t *vm, int nb_cycle, int scroll)
{
    size_t i = 0;
    int color = 0;
    int x = (COLS / 2) - (64 + 64);
    int y = 2;

    display_info(vm, nb_cycle, 0, ((COLS / 2) + (70)));
    for (size_t compt = scroll; compt < IDX_NBR; compt++) {
        while (i != IDX_MOD) {
            color = print_mem_ncurse_spl(&x, &y, &i, vm->memory[compt]);
            arena_color(vm, color);
        }
        i = 0;
    }
    display_arena(vm);
    refresh();
    usleep(vm->ncur.speed);
}
