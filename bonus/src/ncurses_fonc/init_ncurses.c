/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static mem_t **split_init_men(mem_t **mem, int compt)
{
    size_t i = 0;
    unsigned char *s = "00";

    while (i != 513) {
        if (compt < 6)
            mem[compt][i].proprio = 0;
        else
            mem[compt][i].proprio = 1;
        mem[compt][i].id_process = 1;
        mem[compt][i].cas = s;
        i++;
    }
    mem[compt][i].cas = NULL;
    return (mem);
}

mem_t **init_mem(mem_t **mem)
{
    size_t compt = 0;

    mem = malloc(sizeof(mem_t *) * (13));
    while (compt != 13) {
        mem[compt] = malloc(sizeof(mem_t) * 514);
        mem = split_init_men(mem, compt);
        compt++;
    }
    mem[compt] = NULL;
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