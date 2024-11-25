#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *create_node(int data)
{
    struct stack *new_node = malloc(sizeof(struct stack));
    if (new_node == NULL)
    {
        err(1, "Memory allocation failed");
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new_node = create_node(e);
    if (s == NULL)
    {
        return new_node;
    }
    new_node->next = s;
    return new_node;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
    {
        return NULL;
    }
    struct stack *temp = s->next;
    free(s);
    return temp;
}

int stack_peek(struct stack *s)
{
    assert(s != NULL);
    return s->data;
}
