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
#include <ncurses.h>
#include <curses.h>

#include "blib.h"
#include "linked_list.h"
#include "op.h"

#include "parsing.h"
#include "process.h"
#include "champion.h"

// DEFINES
#define RETURN_ERROR 84
#define READ_SIZE 1024

#define MAX_CHAMP 4

#define HEXA_BASE "0123456789abcdef"

#define BYTES_MOD 32

#define GET_CASE(vm, process) \
    vm->memory[process->coord_pc.x][process->coord_pc.y]

#define GET_ACT_CASE(vm, x, y) vm->memory[x][y]

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

typedef struct {
    unsigned char *cas;
    size_t proprio;
    size_t id_process;
} mem_t;

typedef struct {
    unsigned int param;
    int type;
} params_t;

vm_t *create_vm(void);
void destroy_vm(vm_t *vm);

// INIT ALL
params_t *create_params(size_t len);
void write_mem(unsigned char **memory, unsigned char *champion,
    size_t adress, size_t len_champion);
process_t *init_process(parsing_t *pars_temp, champion_t *champ_temp);
bool init_champion(vm_t *vm, parsing_t *pars_temp, champion_t *champ_temp);
bool get_coord(vm_t *vm, list_t *coord);
vm_t *init_all(list_t *coord, size_t dump);

// ALL INSTRUCT
int i_live(vm_t *vm, champion_t *champion, process_t *process);
int i_ld(vm_t *vm, champion_t *champion, process_t *process);
int i_st(vm_t *vm, champion_t *champion, process_t *process);
int i_add(vm_t *vm, champion_t *champion, process_t *process);
int i_sub(vm_t *vm, champion_t *champion, process_t *process);
int i_and(vm_t *vm, champion_t *champion, process_t *process);
int i_or(vm_t *vm, champion_t *champion, process_t *process);
int i_xor(vm_t *vm, champion_t *champion, process_t *process);
int i_zjmp(vm_t *vm, champion_t *champion, process_t *process);
int i_ldi(vm_t *vm, champion_t *champion, process_t *process);
int i_sti(vm_t *vm, champion_t *champion, process_t *process);
int i_fork(vm_t *vm, champion_t *champion, process_t *process);
int i_lld(vm_t *vm, champion_t *champion, process_t *process);
int i_lldi(vm_t *vm, champion_t *champion, process_t *process);
int i_lfork(vm_t *vm, champion_t *champion, process_t *process);
int i_aff(vm_t *vm, champion_t *champion, process_t *process);
int exec_instruct(vm_t *vm, champion_t *champion, process_t *process);

// UTILS INSTRUCT
params_t *get_first_arg(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params);
params_t *get_second_arg(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params);
params_t *get_third_arg(vm_t *vm, process_t *process,
    params_t *params);
params_t *get_all_args(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params);
void increase_coord(process_t *process, size_t increase);
bool verif_nbr_param(unsigned char indicator, int nbr_param);
bool verif_act_param(unsigned char indicator, int pos, int info);
void write_int_mem(vm_t *vm, size_t x, size_t y, int to_write);
size_t get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get);

// VM LOOP
void check_case(vm_t *vm, process_t *process);
int check_iteration(vm_t *vm, champion_t *champion, process_t *process);

int process_loop(vm_t *vm, champion_t *champion);
int champion_loop(vm_t *vm);

int delete_dead(vm_t *vm);
int update_it(vm_t *vm);

int vm_loop(vm_t *vm);

void print_all(vm_t *vm);
void print_memory(vm_t *vm);

// DESTROY ALL
void destroy_all(vm_t *vm);

// NCURSES
void print_ncurses(vm_t *vm);
void init_ncurses(void);
void print_mem_ncurse(vm_t *vm, int nb_cycle);
mem_t *init_mem(mem_t *mem);

#endif // COREWAR_H