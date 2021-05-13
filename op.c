/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** op
*/

#include "op.h"

op_t op_tab[] =
{
    {"live", 1, {T_DIR}, I_LIVE, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, I_LD, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, I_ST, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, I_ADD, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, I_SUB, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, I_AND, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, I_OR, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, I_XOR, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, I_ZJMP, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, I_LDI, 25,
    "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, I_STI, 25,
    "store index"},
    {"fork", 1, {T_DIR}, I_FORK, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, I_LLD, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, I_LLDI, 50,
    "long load index"},
    {"lfork", 1, {T_DIR}, I_LFORK, 1000, "long fork"},
    {"aff", 1, {T_REG}, I_AFF, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};
