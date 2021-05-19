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
    if (!verif_act_param(indicator, 0, T_DIR) &&
        !verif_act_param(indicator, 0, T_IND))
        return 1;
    if (!verif_act_param(indicator, 1, I_REG))
        return 1;
    return 0;
}

static params_t *get_args(vm_t *vm, process_t *process,
    unsigned char indicator)
{
    params_t *params = create_params(MAX_ARGS_NUMBER);

    if (!verif_act_param(indicator, 0, T_DIR)) {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_IND);
        params[1].type = T_DIR;
    }
    else {
        params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
            process->coord_pc.y + T_ID + T_INFO, T_IND);
        params[1].type = T_IND;
    }
    params[1].param = (unsigned int)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID + T_INFO + params[1].type, T_REG);
    params[1].type = T_REG;
    if (params[1].param >= REG_NUMBER)
        return NULL;
    return params;
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
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    params_t *params = NULL;

    if (verif_args(indicator))
        return 0;
    params = get_args(vm, process, indicator);
    if (params == NULL)
        return 0;
    ld(vm, process, params);
    increase_coord(process, T_ID + T_INFO + params[0].type + params[1].type);
    free(params);
    return 0;
}
