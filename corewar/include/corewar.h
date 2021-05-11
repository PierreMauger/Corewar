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

#include "blib.h"
#include "linked_list.h"
#include "op.h"

#include "process.h"
#include "champion.h"

// DEFINES
#define READ_SIZE 1024
#define FLAGS_NBR 3

#define GET_CASE(vm, process) \
    vm->memory[process->coord_pc.x][process->coord_pc.y]

// VM
typedef struct {
    size_t current_it;
    size_t it_max;
    size_t it_total;
    size_t cycle_total;
} cycle_t;

typedef struct {
    unsigned char **memory;
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
bool is_id_valid(list_t *champs, size_t curr);
int get_champ_index(char **av, int iterations);
int get_arguments_index(char **av, char *str, int iterations);

// VM LOOP
void check_case(vm_t *vm, process_t *process);
void check_iteration(vm_t *vm, process_t *process);

bool exec_instruct(vm_t *vm, process_t *process);

void process_loop(vm_t *vm, champion_t *champion);
void champion_loop(vm_t *vm);

int vm_loop(vm_t *vm);

#endif // COREWAR_H