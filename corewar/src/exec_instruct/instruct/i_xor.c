/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static bool verif_args(unsigned char indicator)
{
    if (verif_nbr_param(indicator, 3))
        return 1;
    if (!verif_act_param(indicator, 0, I_REG) &&
        !verif_act_param(indicator, 0, I_DIR) &&
        !verif_act_param(indicator, 0, I_IND))
        return 1;
    if (!verif_act_param(indicator, 1, I_REG) &&
        !verif_act_param(indicator, 1, I_DIR) &&
        !verif_act_param(indicator, 1, I_IND))
        return 1;
    if (!verif_act_param(indicator, 2, I_REG))
        return 1;
    return 0;
}

static bool verif_params(params_t *params)
{
    if ((params[0].type == T_REG && params[0].param >= REG_NUMBER) ||
        (params[1].type == T_REG && params[1].param >= REG_NUMBER) ||
        (params[2].param >= REG_NUMBER)) {
        return 1;
    }
    return 0;
}

static void exec_or(process_t *process, params_t *params)
{
    int value_1 = params[0].type == T_REG ?
        (unsigned int)process->reg[params[0].param] : params[0].param;
    int value_2 = params[1].type == T_REG ?
        (unsigned int)process->reg[params[1].param] : params[1].param;

    process->reg[params[2].param] = value_1 ^ value_2;
    increase_coord(process, T_ID + T_INFO + params[0].type +
        params[1].type + params[2].type);
    process->carry = 1;
    free(params);
}

int i_xor(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    params_t *params = create_params(MAX_ARGS_NUMBER);

    if (params == NULL)
        return 1;
    if (verif_args(indicator)) {
        process->carry = 0;
        return 0;
    }
    params = get_all_args(vm, process, indicator, params);
    if (verif_params(params)) {
        process->carry = 0;
        return 0;
    }
    exec_or(process, params);
    return 0;
}
