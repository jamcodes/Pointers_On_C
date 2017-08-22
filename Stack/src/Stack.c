#include "Stack.h"
#include "assert.h"

#define STACK_SIZE 100

static  Stack_t stack[STACK_SIZE];
static  int     top_element = -1;


void
push(Stack_t value)
{
    assert( !is_full() );
    top_element += 1;
    stack[top_element] = value;
}


void
pop(void)
{
    assert( !is_empty() );
    top_element -= 1;
}


Stack_t
top(void)
{
    assert( !is_empty() );
    return stack[top_element];
}

