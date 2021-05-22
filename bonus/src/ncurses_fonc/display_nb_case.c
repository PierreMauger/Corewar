/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

static void dp_el_p(list_node_t *temp_node, vm_t *vm, size_t blue, size_t green)
{
    char *nom_champ = NULL;
    champion_t *temp_cast = NULL;
    int x = (COLS / 2) + (70 + 5);
    int y = 2;

    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    mvprintw(y + 16, x, "Le champion %s a %d cases.", nom_champ, blue);
    mvprintw(y + 17, x, "Last live : %d", vm->ncur.alive.second);
    temp_node = temp_node->next;
    if (!temp_node)
        return;
    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    mvprintw(y + 19, x, "Le champion %s a %d cases.", nom_champ, green);
    mvprintw(y + 20, x, "Last live : %d", vm->ncur.alive.third);
}

void display_nb_proprio(vm_t *vm, size_t red, size_t blue, size_t green)
{
    int y = 2;
    int x = (COLS / 2) + (70 + 5);
    list_node_t *temp_node = NULL;
    char *nom_champ = NULL;
    champion_t *temp_cast = NULL;

    attron(A_BOLD);
    temp_node = vm->champion_list->head;
    if (!temp_node)
        return;
    temp_cast = (champion_t *)temp_node->data;
    nom_champ = temp_cast->name;
    mvprintw(y + 13, x, "Le champion %s a %d cases.", nom_champ, red);
    mvprintw(y + 14, x, "Last live : %d", vm->ncur.alive.first);
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
        mvprintw(y + 22, x, "Le champion %s a %d cases.", nom_champ, yellow);
        mvprintw(y + 23, x, "Last live : %d", vm->ncur.alive.fourth);
    }
}