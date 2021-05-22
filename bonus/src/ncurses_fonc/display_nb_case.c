/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static void spl_display_name(int x, size_t nb, int color, int y)
{
    if (color == 1)
        attroff(COLOR_PAIR(1));
    if (color == 2)
        attroff(COLOR_PAIR(2));
    if (color == 3)
        attroff(COLOR_PAIR(3));
    if (color == 4)
        attroff(COLOR_PAIR(4));
    mvprintw(y, x, "a ");
    x += 2;
    attron(A_BOLD);
    mvprintw(y, x, "%d", nb);
    x += count_len_nb(nb);
    attroff(A_BOLD);
    mvprintw(y, x, " cases.");
}

static void display_name_color(char *nom_champ, size_t nb, int color, int y)
{
    int x = (COLS / 2) + (70 + 5);

    mvprintw(y, x, "Le champion ");
    x += 12;
    if (color == 1)
        attron(COLOR_PAIR(1));
    if (color == 2)
        attron(COLOR_PAIR(2));
    if (color == 3)
        attron(COLOR_PAIR(3));
    if (color == 4)
        attron(COLOR_PAIR(4));
    attron(A_BOLD);
    mvprintw(y, x, "%s", nom_champ);
    attroff(A_BOLD);
    x += bstrlen(nom_champ) + 1;
    spl_display_name(x, nb, color, y);
}

static void dp_el_p(list_node_t *temp_node, vm_t *vm, size_t blue, size_t green)
{
    char *nom_champ = NULL;
    champion_t *temp_cast = NULL;
    int x = (COLS / 2) + (70 + 5);
    int y = 2;
    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    display_name_color(nom_champ, blue, 2, (y + 16));
    mvprintw(y + 17, x, "Last live : ");
    attron(A_BOLD);
    mvprintw(y + 17, x + 12, "%d", vm->ncur.alive.second);
    attroff(A_BOLD);
    temp_node = temp_node->next;
    if (!temp_node) return;
    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    display_name_color(nom_champ, green, 3, y + 19);
    mvprintw(y + 20, x, "Last live : ");
    attron(A_BOLD);
    mvprintw(y + 20, x + 12, "%d", vm->ncur.alive.third);
    attroff(A_BOLD);
}

void display_nb_proprio(vm_t *vm, size_t red, size_t blue, size_t green)
{
    int y = 2;
    int x = (COLS / 2) + (70 + 5);
    list_node_t *temp_node = NULL;
    char *nom_champ = NULL;
    champion_t *temp_cast = NULL;

    temp_node = vm->champion_list->head;
    if (!temp_node)
        return;
    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    display_name_color(nom_champ, red, 1, y + 13);
    mvprintw(y + 14, x, "Last live : ");
    attron(A_BOLD);
    mvprintw(y + 14, x + 12, "%d", vm->ncur.alive.first);
    attroff(A_BOLD);
    temp_node = temp_node->next;
    if (!temp_node)
        return;
    dp_el_p(temp_node, vm, blue, green);
}

void display_nb_yellow(vm_t *vm, size_t yellow)
{
    int y = 2;
    int x = (COLS / 2) + (70 + 5);
    int compt = 0;
    list_node_t *temp_node = NULL;
    char *nom_champ = NULL;
    champion_t *temp_cast = NULL;

    foreach(vm->champion_list->head, temp_node) {
        temp_cast = (champion_t *)temp_node->data;
        nom_champ = temp_cast->name;
        compt++;
    }
    if (yellow != 0 && compt >= 3) {
        display_name_color(nom_champ, yellow, 4, y + 22);
        mvprintw(y + 23, x, "Last live : ");
        attron(A_BOLD);
        mvprintw(y + 23, x + 12, "%d", vm->ncur.alive.fourth);
        attroff(A_BOLD);
    }
}