/*
** EPITECH PROJECT, 2021
** utils for args parsing
** File description:
** parsing_utils
*/

#include "corewar.h"

bool verif_nbr_param(unsigned char indicator, int nbr_param)
{
    if ((unsigned char)(indicator << (nbr_param * 2)) != 0)
        return 1;
    return 0;
}

bool verif_act_param(unsigned char indicator, int pos, int info)
{
    if (((indicator << (pos * 2)) & I_INFO) == info)
        return 1;
    return 0;
}

bool verif_all_params(params_t *params)
{
    if (params[0].type == T_REG &&
        (params[0].param > REG_NUMBER || params[0].param == 0))
        return 1;
    if (params[1].type == T_REG &&
        (params[1].param > REG_NUMBER || params[1].param == 0))
        return 1;
    if ((params[2].type == T_REG &&
        (params[2].param > REG_NUMBER || params[2].param == 0)))
        return 1;
    return 0;
}
