#include <stdio.h>
#include <assert.h>
#include "Queue.h"


#define QUEUE_SIZE 100
#define ARRAY_SIZE (QUEUE_SIZE + 1)


static  Queue_t     queue[ARRAY_SIZE];
static  size_t      q_front = 1;
static  size_t      q_rear  = 0;


void
Queue_insert(Queue_t value)
{
    assert( !Queue_is_full() );
    q_rear = ( q_rear + 1 ) % ARRAY_SIZE;
    queue[q_rear] = value;
}

void
Queue_delete(void)
{
    assert( !Queue_is_empty() );
    q_front = ( q_front + 1 ) % ARRAY_SIZE;
}

Queue_t
Queue_first(void)
{
    assert( !Queue_is_empty() );
    return queue[q_front];
}
