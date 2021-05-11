/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>

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

typedef struct {
    size_t x;
    size_t y;
} coord_t;

typedef struct {
    int reg[REG_NUMBER];
    coord_t coord_pc;
    size_t goal_it;
    size_t current_it;
    int id_instruct;
    bool carry;
} process_t;

// CREATE STRUCTURE
process_t *create_process(process_t *base_process);

#endif // PROCESS_H