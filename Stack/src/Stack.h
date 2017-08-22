#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

typedef int Stack_t

/* push a new value on the stack */
void push(Stack_t value);

void pop(void);

Stack_t top(void);

static inline bool
is_empty(void)
{
    return top_element == -1;
}

static inline bool
is_full(void)
{
    return top_element == STACK_SIZE - 1;
}

#define IS_FULL()    top_element == STACK_SIZE - 1
#define IS_EMPTY()   top_element == -1

#endif /*_STACK_H_*/
