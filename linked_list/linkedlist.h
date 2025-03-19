#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node{
    int data;
    struct node *next;
};

struct node *create_list();

struct node *create_node();

struct node *reverse_node();

struct node *list_end();

void destroy_node();

#endif