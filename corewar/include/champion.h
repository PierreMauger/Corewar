/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef CHAMPION_H
#define CHAMPION_H

#include <stdio.h>

#include "op.h"

#include "linked_list.h"
#include "process.h"

// CHAMPION LIST
typedef struct {
    size_t id;
    char *name;
    bool is_alive;
    list_t *process_list;
} champion_t;

// CREATE CHAMPION
champion_t *create_champion(size_t id, char *name);
int create_all_champs(list_t *champs, char **av, int champ_count);

// DESTROY CHAMP
void destroy_champion(champion_t *champion);

#endif // CHAMPION_H