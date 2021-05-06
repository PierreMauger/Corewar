/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "asm.h"

void free_triple_tab(char ***tab)
{
    for (size_t i = 0; tab[i] != NULL; i++) {
        for (size_t z = 0; tab[i][z] != NULL; z++)
            free(tab[i][z]);
        free(tab[i]);
    }
    free(tab);
}
