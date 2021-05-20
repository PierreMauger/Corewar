/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "blib.h"

#define foreach(node, temp) \
    for (temp = node; temp; temp = temp->next)

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

// CREATE LIST
list_t *create_list(void);
list_node_t *create_node(void *data);

// MANAGE LINKED LIST
void add_node(list_t *list, list_node_t *node);
void remove_node(list_t *list, list_node_t *node);

// DESTROY LIST
void destroy_list(list_t *list, void (*destroy_data)(void *data));
void destroy_node(list_node_t *node, void (*destroy_data)(void *data));

#endif // LINKED_LIST_H