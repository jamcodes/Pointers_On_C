#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include <stdbool.h>


typedef int Queue_t;


void Queue_create(size_t size);
void Queue_destroy(void);

void Queue_insert(Queue_t value);

void Queue_delete(void);

Queue_t Queue_first(void);

static inline bool
Queue_is_empty(void)
{
    return (q_rear + 1) % ARRAY_SIZE == q_front;
}

static inline bool
Queue_is_full(void)
{
    return (q_rear + 2) % ARRAY_SIZE == q_front;
}

#endif /*_QUEUE_H_*/
