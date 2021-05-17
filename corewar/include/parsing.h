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
    file_t *file;
    ssize_t arg_n;
    ssize_t arg_a;
} parsing_t;

typedef struct {
    char *flag;
    size_t len_flag;
    bool (*get_flag)(char **, size_t, parsing_t *);
} flag_t;

// PARSING FUNCT
size_t get_dump(int argc, char **argv);
bool get_n(char **argv, size_t adv, parsing_t *pars);
bool get_a(char **argv, size_t adv, parsing_t *pars);
bool verif_flag(char *flag);

int check_flag(char *act_case);
list_t *get_info_champion(char **argv, bool dump);

void print_usage(void);

// MANAGE STRUCT
parsing_t *create_parsing(char *name, ssize_t arg_n, ssize_t arg_a);
void destroy_parsing(void *parsing);

// ID MANAGE
void set_id(list_t *coord, parsing_t *pars_temp);
bool set_file(parsing_t *pars_temp);
bool set_name(parsing_t *pars_temp);
void set_coord_champion(parsing_t *pars_temp, size_t espacement);
bool set_all(list_t *coord);
size_t verif_id(list_t *coord, ssize_t id);
bool verif_file(parsing_t *pars_temp);
bool verif_all(list_t *coord);

// OPERATIONS
size_t adv_to_next(size_t adv, unsigned char *buffer, size_t max);
size_t get_n_bytes(size_t adv, unsigned char *buffer, size_t max, int n);

#endif // PARSING_H