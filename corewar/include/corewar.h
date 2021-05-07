/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef COREWAR_H
#define COREWAR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#include "linked_list.h"
#include "blib.h"
#include "op.h"

#include "process.h"
#include "champion.h"

// VM
typedef struct {
    size_t current_it;
    size_t it_max;
    size_t it_total;
    size_t cycle_total;
} cycle_t;

typedef struct {
    unsigned char memory[MEM_SIZE];
    list_t *champion_list;
    cycle_t cycle;
    size_t dump;
} vm_t;

// CREATE VM
vm_t *create_vm(void);

// Args parsing funcs
char **init_checking_flags(void);
bool check_read_accessibility(char *str);
int parse_champ_args(char **av);
list_t *store_champ_arguments(char **av, vm_t *vm, int champ_count);

// UPDATE VM
void update_process(process_t *process);
void update_champion(champion_t *champion);

#endif // COREWAR_H