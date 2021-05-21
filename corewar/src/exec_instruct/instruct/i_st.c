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

static void exec_st(vm_t *vm, process_t *process, params_t *params)
{
    if (params[1].type == T_IND) {
        write_int_mem(vm, process->coord_pc.x,
            (process->coord_pc.x + params[1].param) % IDX_MOD,
            process->reg[params[0].param - 1]);
    }
    else {
        process->reg[params[1].param - 1] = process->reg[params[0].param - 1];
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
    params = get_params(vm, process, indicator, 2);
    if (params == NULL)
        return 1;
    if (verif_all_params(params)) {
        free(params);
        return 0;
    }
    exec_st(vm, process, params);
    increase_coord(process, T_ID + T_INFO + params[0].type + params[1].type);
    free(params);
    return 0;
}
