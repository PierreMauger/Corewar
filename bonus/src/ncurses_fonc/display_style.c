/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

void display_live_bold(int y, int x, int live)
{
    mvprintw(y, x, "Last live : ");
    attron(A_BOLD);
    mvprintw(y, x + 12, "%d", live);
    attroff(A_BOLD);
}

void display_process_bold(int y, int x, int process)
{
    mvprintw(y, x, "Nombre de process : ");
    attron(A_BOLD);
    mvprintw(y, x + 20, "%d", process);
    attroff(A_BOLD);
}