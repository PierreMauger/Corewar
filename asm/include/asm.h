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

#include "op.h"

#define READ_SIZE 50

size_t skip_header(char *buffer);
size_t check_asm(char *buffer);
int recup_all(char *buffer, size_t adv);
int check_name_fonc(char *buffer, size_t adv, char **stock_name);
int get_arg(char *buffer, size_t adv, char **stock_name, char ***stock_arg);
void free_triple_tab(char ***tab);
void free_double_tab(char **tab);

#endif // ASM_H
