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
    if (!verif_act_param(indicator, 0, I_REG))
        return 1;
    if (!verif_act_param(indicator, 1, I_IND) &&
        !verif_act_param(indicator, 1, I_REG))
        return 1;
    return 0;
}

static params_t *get_args(vm_t *vm, process_t *process,
    unsigned char indicator)
{
    params_t *params = create_params(MAX_ARGS_NUMBER);

    params[0].param = (unsigned int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO, T_REG);
    params[0].type = T_REG;
    if (params[0].param >= REG_NUMBER)
        return NULL;
    if (!verif_act_param(indicator, 1, I_IND)) {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO + T_REG, T_IND);
        params[1].type = T_IND;
    }
    else {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO + T_REG, T_REG);
        params[1].type = T_REG;
        if (params[1].param >= REG_NUMBER)
            return NULL;
    }
    return params;
}

static void exec_st(vm_t *vm, process_t *process, params_t *params)
{
    if (params[1].type == T_IND) {
        GET_ACT_CASE(vm, process->coord_pc.x, params[1].param % IDX_MOD) =
            process->reg[params[0].param];
    }
    else {
        process->reg[params[1].param] = process->reg[params[0].param];
    }
}

int i_st(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    params_t *params = NULL;

    if (verif_args(indicator))
        return 0;
    params = get_args(vm, process, indicator);
    if (params == NULL)
        return 0;
    exec_st(vm, process, params);
    free(params);
    return 0;
}
