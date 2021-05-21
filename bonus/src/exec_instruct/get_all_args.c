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
    else if (verif_act_param(indicator, 0, I_IND)) {
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
    else if (verif_act_param(indicator, 1, I_IND)) {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO + params[0].type, T_IND);
        params[1].type = T_IND;
    }
    return params;
}

params_t *get_third_arg(vm_t *vm, process_t *process,
    unsigned char indicator, params_t *params)
{
    if (verif_act_param(indicator, 2, I_REG)) {
        params[2].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO +
            params[0].type + params[1].type, T_REG);
        params[2].type = T_REG;
    }
    else if (verif_act_param(indicator, 2, I_DIR)) {
        params[2].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO +
            params[0].type + params[1].type, T_DIR);
        params[2].type = T_DIR;
    }
    else if (verif_act_param(indicator, 3, I_IND)) {
        params[2].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO +
            params[0].type + params[1].type, T_IND);
        params[2].type = T_IND;
    }
    return params;
}

params_t *get_all_args(vm_t *vm, process_t *process,
    unsigned char indicator)
{
    params_t *params = create_params(MAX_ARGS_NUMBER);

    if (!params)
        return NULL;
    params = get_first_arg(vm, process, indicator, params);
    params = get_second_arg(vm, process, indicator, params);
    params = get_third_arg(vm, process, indicator, params);
    return params;
}

size_t get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    size_t result = 0;

    for (size_t adv = 0; adv < size_to_get; adv++) {
        if (y >= IDX_MOD) {
            x += ((y / IDX_MOD) - x);
            y %= IDX_MOD;
            x %= IDX_NBR;
        }
        result |= GET_ACT_CASE(vm, x, y);
        if (adv + 1 != size_to_get)
            result <<= 8;
        y++;
    }
    return result;
}
