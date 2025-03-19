#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"


struct node *create_list(int value) 
{
    struct node *new_list = (struct node*)malloc(sizeof(struct node));

    new_list->data = value;
    new_list->next = NULL;

    return new_list;
}

struct node *create_node(int value, struct node* head)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = value;
    new_node->next = head;

    return new_node;
}

struct node *reverse_node(struct node* list){

    struct node* reversed_list = (struct node*)malloc(sizeof(struct node));

    return reversed_list;
}

struct node *list_end(struct node* list){
    struct node* end_node;

    return end_node;
}

void destroy_node(struct node *node)
{
    free(node->next);
    free(node);

    return;
}

void destroy_list(struct node *node){//expects input to be head of list

    if(node->next != NULL){
        destroy_list(node);
    }
    
    destroy_node(node);

    return;
}