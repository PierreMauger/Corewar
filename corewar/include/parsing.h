/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef PARSING_H
#define PARSING_H

#include "blib.h"

typedef struct {
    char *name;
    ssize_t arg_n;
    ssize_t arg_a;
} parsing_t;

typedef struct {
    char *flag;
    size_t len_flag;
    ssize_t (*get_flag)(char **, size_t);
} flag_t;

// PARSING FUNCT
ssize_t get_n(char **argv, size_t adv);
ssize_t get_a(char **argv, size_t adv);
bool verif_flag(char *flag);

int check_flag(char *act_case);
list_t *get_info_champion(char **argv);

void print_usage(void);

// MANAGE STRUCT
parsing_t *create_parsing(char *name, ssize_t arg_n, ssize_t arg_a);
void destroy_parsing(void *parsing);

#endif // PARSING_H