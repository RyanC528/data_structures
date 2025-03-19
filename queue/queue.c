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
        target->array[target->rear] = input;
        target->rear++;
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

        for (int i = 0; i < target->rear - 1; i++)
        {
            target->array[i] = target->array[i + 1];
        }

        target->rear--;
    }
    return;
}

int peek(struct queue *target)
{
    return target->front;
}

int rear(struct queue *target)
{
    return target->rear;
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