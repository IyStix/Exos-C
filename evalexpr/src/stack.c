#include "stack.h"

void init_stack(struct Stack *s)
{
    s->top = -1;
}

int is_empty(struct Stack *s)
{
    return s->top == -1;
}

int push(struct Stack *s, double value)
{
    if (s->top >= MAX_STACK - 1)
    {
        return 0;
    }
    s->top++;
    s->items[s->top] = value;
    return 1;
}

int pop(struct Stack *s, double *value)
{
    if (is_empty(s))
    {
        return 0;
    }
    *value = s->items[s->top];
    s->top--;
    return 1;
}
