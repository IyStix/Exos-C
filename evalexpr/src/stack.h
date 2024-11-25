#ifndef STACK_H
#define STACK_H

#define MAX_STACK 100

struct Stack
{
    double items[MAX_STACK];
    int top;
};

void init_stack(struct Stack *s);
int is_empty(struct Stack *s);
int push(struct Stack *s, double value);
int pop(struct Stack *s, double *value);

#endif // STACK_H
