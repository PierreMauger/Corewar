/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static bool verif_args(unsigned char indicator)
{
    if (verif_nbr_param(indicator, 2))
        return 1;
    if (!verif_act_param(indicator, 0, I_DIR) &&
        !verif_act_param(indicator, 0, I_IND))
        return 1;
    if (!verif_act_param(indicator, 1, I_REG))
        return 1;
    return 0;
}

static bool verif_params(params_t *params)
{
    if (params[0].type == T_REG && params[0].param >= REG_NUMBER)
        return 1;
    if (params[1].type == T_REG && params[1].param >= REG_NUMBER)
        return 1;
    if (params[2].type == T_REG && params[2].param >= REG_NUMBER)
        return 1;
    return 0;
}

static params_t *get_args(vm_t *vm, process_t *process,
    unsigned char indicator)
{
    params_t *params = create_params(MAX_ARGS_NUMBER);

    if (!params)
        return NULL;
    params = get_first_arg(vm, process, indicator, params);
    params = get_second_arg(vm, process, indicator, params);
    return params;
}

static void exec_lld(vm_t *vm, process_t *process, params_t *params)
{
    int value = 0;

    if (params[0].type == I_IND)
        value = (int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + params[0].param, REG_SIZE);
    else value = (int)get_param(vm, process->coord_pc.x,
            params[0].param % IDX_MOD, REG_SIZE);
    process->reg[params[1].param] = value;
    increase_coord(process, T_ID + T_INFO + params[0].type +
        params[1].type + params[2].type);
    process->carry = 1;
}

int i_lld(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    params_t *params = NULL;

    if (verif_args(indicator)) {
        process->carry = 0;
        return 0;
    }
    params = get_args(vm, process, indicator);
    if (params == NULL)
        return 1;
    if (verif_params(params)) {
        process->carry = 0;
        return 0;
    }
    exec_lld(vm, process, params);
    free(params);
    return 0;
}
