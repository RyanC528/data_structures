#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

void enqueue(struct queue *target, int input)
{
    if (is_full(target))
    {
        printf("ERROR QUEUE FULL\n");
        return;
    }
    else
    {
        target->array[target->size] = input;
    }
}

void dequeue(struct queue *target, int input)
{
    if (is_empty(target))
    {
        printf("ERROR QUEUE EMPTY\n");
        return;
    }
    else
    {

        for (int i = 0; i < target->size - 1; i++)
        {
            target->array[i] = target->array[i + 1];
        }
    }
    return;
}

int peek(struct queue *target)
{
    return target->front;
}

bool is_full(struct queue *target)
{
    bool output = false;

    if (target->size == target->cap)
    {
        output = true;
    }

    return output;
}

bool is_empty(struct queue *target)
{
    bool output = false;

    if (target->size == 0)
    {
        output = true;
    }

    return output;
}

int size(struct queue *target)
{
    return target->size;
}

struct queue *create_queue(unsigned capacity)
{
    struct queue *new_queue;

    new_queue->cap = capacity;
    new_queue->size = 0;
    new_queue->front = -1;
    new_queue->array = malloc(new_queue->cap * sizeof(int));

    return new_queue;
}

void destroy_queue(struct queue *target)
{
    free(target->array);
    free(target);

    return;
}