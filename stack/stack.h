#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

struct stack
{
    int front;
    unsigned cap;
    int *array;
};

struct stack *create_stack();

void push();

void pop();

int top();

bool is_empty();

bool is_full();

#endif