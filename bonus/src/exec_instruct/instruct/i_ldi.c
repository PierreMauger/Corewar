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
        (unsigned int)process->reg[params[1].param - 1] : params[1].param;
    int value_3 = 0;

    if (params[0].type == T_REG)
        value_1 = (unsigned int)process->reg[params[0].param - 1];
    else if (params[0].type == T_DIR)
        value_1 = (int)get_param(vm, process->coord_pc.x,
            (params[0].param % IDX_MOD), IND_SIZE);
    else value_1 = (int)get_param(vm, process->coord_pc.x,
            (process->coord_pc.y + params[0].param) % IDX_MOD, IND_SIZE);
    value_3 = (int)get_param(vm, process->coord_pc.x,
        (process->coord_pc.y + value_1 + value_2) % IDX_MOD, REG_SIZE);
    process->reg[params[2].param - 1] = value_3;
}

static int init_ldi(vm_t *vm, process_t *process, unsigned char indicator)
{
    params_t *params = NULL;
    int size_skip = 0;

    if (verif_args(indicator))
        return T_ID;
    size_skip += T_ID + T_INFO;
    params = get_params(vm, process, indicator, 3);
    if (params == NULL)
        return -1;
    size_skip += params[0].type + params[1].type + params[2].type;
    if (verif_all_params(params)) {
        return size_skip;
    }
    exec_ldi(vm, process, params);
    free(params);
    return size_skip;
}

int i_ldi(vm_t *vm, __attribute__((unused))champion_t *champion,
    process_t *process)
{
    unsigned char indicator = (unsigned char)get_param(vm, process->coord_pc.x,
        process->coord_pc.y + T_ID, T_INFO);
    int size_skip = init_ldi(vm, process, indicator);

    if (size_skip == -1)
        return 1;
    increase_coord(process, size_skip);
    return 0;
}
