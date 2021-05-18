/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#ifndef BSTRING_H
#define BSTRING_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t bstrlen(char *str);

void *bmemset(void *s, int c, size_t n);

int bstrcmp(char *s1, char *s2);
int bstrncmp(char *s1, char *s2, size_t n);

char *bstrdup(char *src);
char *bstrndup(char *src, size_t n);
char *bstrndup_forced(char *src, size_t n);

char *bstrcat(char *dest, char *src);
char *bstrncat(char *dest, char *src, size_t n);
char *bstrncat_forced(char *dest, char *src, size_t size_base,
    size_t plus_size);

char *bstrcpy(char *dest, char *src);
char *bstrncpy(char *dest, char *src, size_t n);

char *brevstr(char *src);
char *brevstr_forced(char *src, size_t size_str);

char *bitoa(int nbr);
char *bitoa_base(int nbr, char *base);
int batoi(char *str);

#endif // BSTRING_H
