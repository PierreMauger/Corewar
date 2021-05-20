/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

params_t *get_first_arg(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params)
{
    if (verif_act_param(indicator, 0, I_REG)) {
        params[0].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_REG);
        params[0].type = T_REG;
    }
    else if (verif_act_param(indicator, 0, I_DIR)) {
        params[0].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_DIR);
        params[0].type = T_DIR;
    }
    else {
        params[0].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_IND);
        params[0].type = T_IND;
    }
    return params;
}

params_t *get_second_arg(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params)
{
    if (verif_act_param(indicator, 1, I_REG)) {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO + params[0].type, T_REG);
        params[1].type = T_REG;
    }
    else if (verif_act_param(indicator, 1, I_DIR)) {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO + params[0].type, T_DIR);
        params[1].type = T_DIR;
    }
    else {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO + params[0].type, T_IND);
        params[1].type = T_IND;
    }
    return params;
}

params_t *get_third_arg(vm_t *vm, process_t *process, params_t *params)
{
    params[2].param = (unsigned int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO + params[0].type +
        params[1].type, T_REG);
    params[2].type = T_REG;
    return params;
}

params_t *get_all_args(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params)
{
    params = get_first_arg(vm, process, indicator, params);
    params = get_second_arg(vm, process, indicator, params);
    params = get_third_arg(vm, process, params);
    return params;
}