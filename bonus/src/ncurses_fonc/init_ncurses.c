/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

int count_len_nb(int nb)
{
    int count = 1;

    while (nb > 10) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

void del_color(mem_t mem)
{
    if (mem.proprio == 1)
        attroff(COLOR_PAIR(1));
    if (mem.proprio == 2)
        attroff(COLOR_PAIR(2));
    if (mem.proprio == 3)
        attroff(COLOR_PAIR(3));
    if (mem.proprio == 4)
        attroff(COLOR_PAIR(4));
    if (mem.id_process != 0)
        attroff(A_BOLD | A_STANDOUT);
}

void find_color(mem_t mem)
{
    if (mem.proprio == 1)
        attron(COLOR_PAIR(1));
    if (mem.proprio == 2)
        attron(COLOR_PAIR(2));
    if (mem.proprio == 3)
        attron(COLOR_PAIR(3));
    if (mem.proprio == 4)
        attron(COLOR_PAIR(4));
    if (mem.id_process != 0)
        attron(A_BOLD | A_STANDOUT);
}

void init_ncurses(void)
{
    initscr();
    noecho();
    if (!has_colors()) {
        endwin();
        exit(84);
    }
    keypad(stdscr, TRUE);
    start_color();
    timeout(0);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}