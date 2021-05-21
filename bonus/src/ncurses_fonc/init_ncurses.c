/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void display_count_proprio(int *x, size_t red, size_t blue, size_t green)
{
    int y = 0;

    *x += 5;
    if (red != 0) {
        mvprintw(y, *x, "Le joueur 1 a %d cases.", red);
        *x += 28;
    }
    if (blue != 0) {
        mvprintw(y, *x, "Le joueur 2 a %d cases.", blue);
        *x += 28;
    }
    if (green != 0) {
        mvprintw(y, *x, "Le joueur 1 a %d cases.", green);
        *x += 28;
    }
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
        attroff(A_BOLD);
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
        attron(A_BOLD);
}

void init_ncurses(void)
{
    initscr();
    noecho();
    if (!has_colors()) {
        endwin();
        exit(84);
    }
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}
