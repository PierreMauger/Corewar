/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

void destroy_champion(champion_t *champion)
{
    free(champion->name);
}