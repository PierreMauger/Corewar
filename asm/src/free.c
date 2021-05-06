/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void free_triple_tab(char ***tab)
{
    size_t i = 0;
    size_t z = 0;

    while (tab[i] != NULL) {
        while (tab[i][z] != NULL) {
            free(tab[i][z]);
            z++;
        }
        free(tab[i]);
        z = 0;
        i++;
    }
    free(tab);
}

void free_double_tab(char **tab)
{
    size_t i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}