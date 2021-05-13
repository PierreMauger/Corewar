/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef ASM_H
#define ASM_H

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

#define READ_SIZE 50

typedef struct {
    char *name;
    char **params;
    char *label;
} command_t;

    // check_asm.c
list_t *check_asm(char *buffer);

    // check_header.c
size_t skip_head(char *buffer);
size_t check_name(char *buffer, size_t adv, char *param_name, int param_len);
size_t check_header(char *buffer, size_t adv);

    // check_command.c
size_t get_id(char *name);
int check_label(char *label);
size_t check_command(list_t *list);

    // check_params_size.c
int is_num(char *str);
int is_reg(char *str);
int is_label(char *str, list_t *list);
int is_dir(char *str, list_t *list);
int check_size(char **params, args_type_t *type, list_t *list);

    // destroy_command.c
void destroy_command(void *com);

    // get_command_name.c
char *get_command_name(char *buffer, size_t *adv);

    // get_command_params.c
size_t get_param_len(char *buffer, size_t *adv);
char *get_one_param(char *buffer, size_t *adv);
char **get_command_params(char *buffer, size_t adv);

    // get_command.c
command_t *create_com(char *buffer, size_t *adv);
list_t *get_command(char *buffer, size_t adv);

    //write_asm.c
char *get_chmp_filename(char *filename);
void write_asm(char *filename, char *buffer, list_t *list);

    //write_instructions.c
void write_instructions(int fd, list_t *list);

    //write_name.c
char *get_name(char *buffer, size_t *adv, size_t size);
void write_header(int fd, char *buffer);

#endif // ASM_H
