/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "corewar.h"

params_t *create_params(size_t len)
{
    params_t *result = bcalloc(sizeof(params_t), len);

    return result;
}