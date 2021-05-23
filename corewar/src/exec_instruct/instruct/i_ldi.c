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
    int value_1 = get_value(vm, process, params[0], 1);
    int value_2 = get_value(vm, process, params[1], 1);
    int value_3 = 0;
    ssize_t x = process->coord_pc.x;
    ssize_t y = process->coord_pc.y;

    if (params[0].type == 2)
        value_1 = (short)value_1;
    if (params[1].type == 2)
        value_2 = (short)value_2;
    nbr_to_coord(&x, &y, (value_1 + value_2) % IDX_MOD);
    value_3 = (int)get_param(vm, x, y, REG_SIZE);
    process->reg[params[2].param - 1] = value_3;
    if (!value_3)
        process->carry = 1;
    else process->carry = 0;
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
        free(params);
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
