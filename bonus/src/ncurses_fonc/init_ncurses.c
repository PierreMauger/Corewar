/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

mem_t *init_mem(mem_t *mem)
{
    size_t i = 0;
    unsigned char *s = "00";

    mem = malloc(sizeof(mem_t) * ((6*1024) + 1));
    while (i != 6144) {
        if (i < 3072)
            mem[i].proprio = 0;
        else
            mem[i].proprio = 1;
        mem[i].id_process = 1;
        mem[i].cas = s;
        i++;
    }
    mem[i].cas = NULL;
    return (mem);
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