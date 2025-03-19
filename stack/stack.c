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

    if (target->size == 0)
    {
        output = true;
    }
    return output;
}

bool is_full(struct stack *target)
{
    bool output = false;

    if (target->cap == target->size)
    {
        output = true;
    }

    return output;
}
