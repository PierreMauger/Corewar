/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static int check_indicator(vm_t *vm, process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);

    if (verif_nbr_param(indicator, 2))
        return 0;
    if (!verif_act_param(indicator, 1, I_REG))
        return 0;
    if (verif_act_param(indicator, 0, I_DIR))
        return I_DIR;
    else if (verif_act_param(indicator, 0, I_IND))
        return I_IND;
    else return 0;
}

static bool fill_params(vm_t *vm, process_t *process,
    params_t *params, int ret)
{
    if (ret == I_DIR) {
        params[0].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_DIR);
    }
    else if (ret == I_IND)
        params[0].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_IND);
    else return 1;
    params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO + ret, T_REG);
    params[0].type = ret;
    params[1].type = I_REG;
    return 0;
}

static void ld(vm_t *vm, process_t *process, params_t *params)
{
    int value = 0;

    if (params[0].type == I_DIR)
        value = (int)get_param(vm, process->coord_pc.x,
            (process->coord_pc.y + params[0].param) % IDX_MOD, REG_SIZE);
    else value = (int)get_param(vm, process->coord_pc.x,
            (params[0].param) % IDX_MOD, REG_SIZE);
    process->reg[params[1].param] = value;
}

int i_ld(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    int ret = check_indicator(vm, process);
    params_t params[MAX_ARGS_NUMBER] = {0};

    if (fill_params(vm, process, params, ret) ||
        params[1].param >= REG_NUMBER) {
        process->carry = 0;
        return 0;
    }
    ld(vm, process, params);
    return 0;
}
