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
    if (!verif_act_param(indicator, 1, I_DIR) &&
        !verif_act_param(indicator, 1, I_REG))
        return 1;
    if (!verif_act_param(indicator, 2, I_REG))
        return 1;
    return 0;
}

static void exec_ldi(vm_t *vm, process_t *process, params_t *params)
{
    int value_1 = 0;
    int value_2 = params[1].type == T_REG ?
        (unsigned int)process->reg[params[1].param] : params[1].param;
    int value_3 = 0;

    if (params[0].type == T_REG)
        value_1 = (unsigned int)process->reg[params[0].param];
    else if (params[0].type == T_DIR)
        value_1 = (int)get_param(vm, process->coord_pc.x,
            params[0].param, IND_SIZE);
    else value_1 = (int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + params[0].param, IND_SIZE);
    value_3 = (int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + value_1 + value_2, REG_SIZE);
    process->reg[params[2].param] = value_3;
    increase_coord(process, T_ID + T_INFO + params[0].type +
        params[1].type + params[2].type);
    process->carry = 1;
    free(params);
}

int i_lldi(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    params_t *params = NULL;

    if (verif_args(indicator)) {
        process->carry = 0;
        return 0;
    }
    params = get_all_args(vm, process, indicator);
    if (params == NULL)
        return 1;
    if (verif_all_params(params)) {
        process->carry = 0;
        return 0;
    }
    exec_ldi(vm, process, params);
    return 0;
}
