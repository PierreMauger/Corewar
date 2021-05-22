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

static void exec_lld(vm_t *vm, process_t *process, params_t *params)
{
    int value = params[0].type == IND_SIZE ? (unsigned int)get_param(vm,
        process->coord_pc.x, process->coord_pc.y + params[0].param,
        REG_SIZE) : params[0].param;

    process->reg[params[1].param - 1] = value;
    if (!params[0].param)
        process->carry = 1;
    else process->carry = 0;
}

static int init_lld(vm_t *vm, process_t *process, unsigned char indicator)
{
    params_t *params = NULL;
    int size_skip = 0;

    if (verif_args(indicator))
        return T_ID;
    size_skip += T_ID + T_INFO;
    params = get_params(vm, process, indicator, 2);
    if (params == NULL)
        return -1;
    size_skip += params[0].type + params[1].type + params[2].type;
    if (verif_all_params(params)) {
        free(params);
        return size_skip;
    }
    exec_lld(vm, process, params);
    free(params);
    return size_skip;
}

int i_lld(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    int size_skip = init_lld(vm, process, indicator);

    if (size_skip == -1)
        return 1;
    increase_coord(process, size_skip);
    return 0;
}
