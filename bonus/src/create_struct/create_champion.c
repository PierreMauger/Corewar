/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

champion_t *create_champion(size_t id, char *name)
{
    champion_t *result = bcalloc(sizeof(champion_t), 1);

    if (result) {
        result->id = id;
        result->name = name;
    }
    return result;
}
