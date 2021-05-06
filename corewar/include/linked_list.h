/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct list_node_s {
    struct list_node_s *next;
    struct list_node_s *last;
    void *data;
} list_node_t;

typedef struct {
    list_node_t *head;
    list_node_t *tail;
    size_t lenght;
} list_t;

list_node_t *add_elem(list_node_t *actual, list_node_t *elem);

#endif // LINKED_LIST_H