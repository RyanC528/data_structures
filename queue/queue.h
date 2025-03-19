#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

struct queue
{
    int front, size;
    unsigned cap;
    int *array;
};

struct queue *create_queue();

void enqueue();

void dequeue();

int peek();

bool is_full();

bool is_empty();

int size();

void destroy_queue();

#endif