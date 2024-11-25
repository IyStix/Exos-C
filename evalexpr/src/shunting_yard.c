#include "shunting_yard.h"

#include "operators.h"
#include "stack.h"

static void handle_number(struct Token *postfix, size_t *postfix_size,
                          struct Token infix_token)
{
    postfix[(*postfix_size)++] = infix_token;
}

static void handle_operator(struct Stack *operator_stack, struct Token *postfix,
                            size_t *postfix_size, char current_operator)
{
    while (!is_empty(operator_stack)
           && operator_stack->items[operator_stack->top] != '('
           && (precedence(operator_stack->items[operator_stack->top])
                   > precedence(current_operator)
               || (precedence(operator_stack->items[operator_stack->top])
                       == precedence(current_operator)
                   && current_operator != '^')))
    {
        struct Token op_token;
        op_token.type = TOKEN_OPERATOR;
        op_token.value.operator= operator_stack->items[operator_stack->top];
        postfix[(*postfix_size)++] = op_token;
        operator_stack->top--;
    }
    push(operator_stack, current_operator);
}

static int handle_right_parenthesis(struct Stack *operator_stack,
                                    struct Token *postfix, size_t *postfix_size)
{
    while (!is_empty(operator_stack)
           && operator_stack->items[operator_stack->top] != '(')
    {
        struct Token op_token;
        op_token.type = TOKEN_OPERATOR;
        op_token.value.operator= operator_stack->items[operator_stack->top];
        postfix[(*postfix_size)++] = op_token;
        operator_stack->top--;
    }
    if (is_empty(operator_stack))
    {
        return 2;
    }
    operator_stack->top--;
    return 0;
}

int shunting_yard(struct Token *infix, size_t infix_size, struct Token *postfix,
                  size_t *postfix_size)
{
    struct Stack operator_stack;
    init_stack(&operator_stack);
    *postfix_size = 0;

    for (size_t i = 0; i < infix_size; i++)
    {
        switch (infix[i].type)
        {
        case TOKEN_NUMBER:
            handle_number(postfix, postfix_size, infix[i]);
            break;
        case TOKEN_OPERATOR:
            handle_operator(&operator_stack, postfix, postfix_size,
                            infix[i].value.operator);
            break;
        case TOKEN_LPAREN:
            push(&operator_stack, '(');
            break;
        case TOKEN_RPAREN:
            if (handle_right_parenthesis(&operator_stack, postfix,
                                         postfix_size))
                return 2;
            break;
        default:
            return 2;
        }
    }

    while (!is_empty(&operator_stack))
    {
        char op = operator_stack.items[operator_stack.top--];
        if (op == '(')
            return 2;
        postfix[(*postfix_size)++] =
            (struct Token){ TOKEN_OPERATOR, { .operator= op } };
    }
    return 0;
}
