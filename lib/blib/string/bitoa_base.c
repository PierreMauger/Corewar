/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

static int get_base_int_size(int nbr, int base_size)
{
    int i = 0;

    if (nbr == 0)
        nbr++;
    if (nbr < 0)
        i++;
    while (nbr != 0) {
        nbr /= base_size;
        i++;
    }
    return i;
}

char *bitoa_base(int nbr, char *base)
{
    int base_len = bstrlen(base);
    int len_nbr = get_base_int_size(nbr, base_len);
    char *str = bcalloc(sizeof(char), len_nbr + 1);
    int comm = 0;
    int adv = 0;

    if (!str)
        return NULL;
    if (nbr < 0) {
        str[len_nbr - 1] = '-';
        nbr *= -1;
    }
    do {
        comm = nbr % base_len;
        nbr /= base_len;
        str[adv] = base[comm];
        adv++;
    } while (nbr != 0);
    return brevstr_forced(str, len_nbr);
}
