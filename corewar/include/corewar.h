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

void print_usage(void);

// VM
vm_t *create_vm(void);
void destroy_vm(vm_t *vm);

vm_t *init_vm(int champ_count, char **argv);

// Args parsing funcs
char **init_checking_flags(void);
bool check_read_accessibility(char *str);
int parse_champ_args(char **av);
list_t *store_champ_arguments(char **av, vm_t *vm, int champ_count);
bool is_id_valid(list_t *champs, size_t curr);
int get_champ_index(char **av, int iterations);
int get_arguments_index(char **av, char *str, int iterations);

// VM LOOP
void move_process(vm_t *vm, process_t *process);
void check_case(vm_t *vm, process_t *process);
void check_iteration(vm_t *vm, champion_t *champion, process_t *process);

// ALL INSTRUCT
void i_live(vm_t *vm, champion_t *champion, process_t *process);
void i_ld(vm_t *vm, champion_t *champion, process_t *process);
void i_st(vm_t *vm, champion_t *champion, process_t *process);
void i_add(vm_t *vm, champion_t *champion, process_t *process);
void i_sub(vm_t *vm, champion_t *champion, process_t *process);
void i_and(vm_t *vm, champion_t *champion, process_t *process);
void i_or(vm_t *vm, champion_t *champion, process_t *process);
void i_xor(vm_t *vm, champion_t *champion, process_t *process);
void i_zjmp(vm_t *vm, champion_t *champion, process_t *process);
void i_ldi(vm_t *vm, champion_t *champion, process_t *process);
void i_sti(vm_t *vm, champion_t *champion, process_t *process);
void i_fork(vm_t *vm, champion_t *champion, process_t *process);
void i_lld(vm_t *vm, champion_t *champion, process_t *process);
void i_lldi(vm_t *vm, champion_t *champion, process_t *process);
void i_lfork(vm_t *vm, champion_t *champion, process_t *process);
void i_aff(vm_t *vm, champion_t *champion, process_t *process);
void exec_instruct(vm_t *vm, champion_t *champion, process_t *process);

void process_loop(vm_t *vm, champion_t *champion);
void champion_loop(vm_t *vm);

int vm_loop(vm_t *vm);

// DESTROY ALL
void destroy_all(vm_t *vm);

#endif // COREWAR_H