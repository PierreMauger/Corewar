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

#include "process.h"

// CHAMPION LIST
typedef struct champion_s {
    size_t id;
    char *name;
    bool is_alive;
    process_list_t *process_list;
    struct champion_s *next;
    struct champion_s *last;
} champion_t;

typedef struct {
    champion_t *head;
    champion_t *tail;
    size_t lenght;
} champion_list_t;

#endif // CHAMPION_H