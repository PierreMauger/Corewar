/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instruct
*/

#include "corewar.h"

static const info_params_t info_params[] = {
    {T_REG, I_REG},
    {DIR_SIZE, I_DIR},
    {IND_SIZE, I_IND},

    {0, 0}
};

int get_info_param(unsigned char indicator, size_t adv)
{
    int result = 0;

    for (; info_params[result].size; result++) {
        if (verif_act_param(indicator, adv, info_params[result].inf))
            return result;
    }
    return -1;
}

void get_one_param(vm_t *vm, params_t *params, coord_t coord,
    info_size_t info)
{
    params[info.adv].param = (unsigned int)get_param(vm, coord.x,
        coord.y, info.size_read);
    params[info.adv].type = info.size_read;
    params[info.adv].inf = info.inf;
}

params_t *get_params(vm_t *vm, process_t *process,
    unsigned char indicator, size_t nbr_args)
{
    params_t *params = create_params(MAX_ARGS_NUMBER);
    coord_t coord = {process->coord_pc.x, process->coord_pc.y};
    info_size_t info = {0};
    int ret = 0;

    if (!params)
        return NULL;
    for (; info.adv < nbr_args; info.adv++) {
        coord.y = process->coord_pc.y + T_ID + T_INFO +
            params[0].type + params[1].type;
        ret = get_info_param(indicator, info.adv);
        if (ret != -1) {
            if (process->id_instruct >= 8 && process->id_instruct <= 14 &&
                process->id_instruct != 12 && info_params[ret].inf == I_DIR)
                info.size_read = DIR_SIZE_INDEX;
            else info.size_read = info_params[ret].size;
            info.inf = info_params[ret].inf;
            get_one_param(vm, params, coord, info);
        }
    }
    return params;
}

size_t get_param(vm_t *vm, size_t x, size_t y, size_t size_to_get)
{
    size_t result = 0;

    for (size_t adv = 0; adv < size_to_get; adv++) {
        if (y >= IDX_MOD) {
            x += (y / IDX_MOD);
            y %= IDX_MOD;
            x %= IDX_NBR;
        }
        result |= GET_ACT_CASE(vm, x, y);
        if (adv + 1 < size_to_get)
            result <<= 8;
        y++;
    }
    return result;
}

int get_value(vm_t *vm, process_t *process, params_t param, bool mod)
{
    if (param.inf == I_REG) {
        return process->reg[param.param - 1];
    }
    else if (param.inf == I_DIR) {
        return param.param;
    }
    else if (param.inf == I_IND) {
        if (mod) {
            return (int)get_param(vm, process->coord_pc.x,
                (process->coord_pc.y + param.param) % IDX_MOD, IND_SIZE);
        }
        else
            return (int)get_param(vm, process->coord_pc.x,
                (process->coord_pc.y + param.param), IND_SIZE);
    }
    return 0;
}
