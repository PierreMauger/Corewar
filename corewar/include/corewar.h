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

#include "op.h"

typedef enum {
    r1,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    r10,
    r11,
    r12,
    r13,
    r14,
    r15,
    r16
} register_name_e;

typedef struct process_s {
    int reg[REG_NUMBER];
    size_t coord_pc;
    size_t goal_it;
    size_t current_it;
    int id_instruct;
    bool carry;
    struct process_s *next;
    struct process_s *last;
} process_t;

typedef struct champion_s {
    size_t id;
    char *name;
    bool is_alive;
    process_t *process;
    struct champion_s *next;
    struct champion_s *last;
} champion_t;

typedef struct {
    size_t current_it;
    size_t it_max;
    size_t it_total;
    size_t cycle_total;
} cycle_t;

typedef struct {
    unsigned char memory[MEM_SIZE];
    champion_t *champion;
    cycle_t cycle;
    size_t dump;
} vm_t;

#endif // COREWAR_H