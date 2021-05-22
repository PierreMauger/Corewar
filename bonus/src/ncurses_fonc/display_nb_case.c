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
    display_name_color(nom_champ, blue, 2, (y + 15));
    display_live_bold(y + 16, x, vm->ncur.alive[1]);
    display_process_bold(y + 17, x, vm->ncur.nb_process[1]);
    temp_node = temp_node->next;
    if (!temp_node) return;
    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    display_name_color(nom_champ, green, 3, y + 19);
    display_live_bold(y + 20, x, vm->ncur.alive[2]);
    display_process_bold(y + 21, x, vm->ncur.nb_process[2]);
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
    display_name_color(nom_champ, red, 1, y + 11);
    display_live_bold(y + 12, x, vm->ncur.alive[0]);
    display_process_bold(y + 13, x, vm->ncur.nb_process[0]);
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
        display_name_color(nom_champ, yellow, 4, y + 23);
        display_live_bold(y + 24, x, vm->ncur.alive[3]);
        display_process_bold(y + 25, x, vm->ncur.nb_process[3]);
    }
}