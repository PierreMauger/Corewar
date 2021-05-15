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
    unsigned int id;
    char *name;
    bool is_alive;
    size_t alive_it;
    list_t *process_list;
} champion_t;

// CREATE CHAMPION
champion_t *create_champion(size_t id, char *name);
int create_all_champs(list_t *champs, char **av, int champ_count);
int init_champs_process(list_t *champs, char **av);

// DESTROY CHAMP
void destroy_champion(void *champion);

// CHECK OP
int check_op(unsigned char index_value);

#endif // CHAMPION_H