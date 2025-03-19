#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

struct stack
{
    int front;
    unsigned cap;
    int *array;
};

struct stack* create_stack();

void destroy_stack();

void push();

void pop();

int top();

bool is_empty();

bool is_full();

#endif