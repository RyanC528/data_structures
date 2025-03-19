#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void push(struct stack *target)
{
    if (is_full(target))
    {
        printf("ERROR STACK FULL");
        return;
    }

    return;
}

void pop(struct stack *target)
{
    if (is_empty(target))
    {
        printf("ERROR STACK EMPTY");
        return;
    }

    return;
}

int top(struct stack *target)
{
    return target->front;
}

bool is_empty(struct stack *target)
{
    bool output = false;

    output;
}

bool is_full(struct stack *target)
{
    bool output = false;

    return output;
}

struct stack* create_stack(int capacity){

    struct stack* new_stack = (struct stack*)malloc(sizeof(struct stack));

    new_stack->front = -1;
    new_stack->cap = capacity;

    new_stack->array = malloc(new_stack->cap * sizeof(int));

    return new_stack;
}

void destroy_stack(struct stack* target){
    free(target->array);
    free(target);

    return;
}