#include "evalexpr.h"

#include "lexer.h"
#include "operators.h"
#include "shunting_yard.h"
#include "stack.h"

static int evaluate_postfix(struct Token *postfix, size_t size, double *result)
{
    struct Stack eval_stack;
    init_stack(&eval_stack);

    for (size_t i = 0; i < size; i++)
    {
        if (postfix[i].type == TOKEN_NUMBER)
        {
            push(&eval_stack, postfix[i].value.number);
        }
        else if (postfix[i].type == TOKEN_OPERATOR)
        {
            double a;
            double b;
            int is_unary_minus = 0;

            if (postfix[i].value.operator== '-' &&(
                    i == 0 || (i > 0 && postfix[i - 1].type == TOKEN_OPERATOR)))
            {
                is_unary_minus = 1;
            }

            if (is_unary_minus)
            {
                if (!pop(&eval_stack, &a))
                    return 2;
                push(&eval_stack, -a);
            }
            else
            {
                if (!pop(&eval_stack, &b) || !pop(&eval_stack, &a))
                    return 2;
                push(&eval_stack, apply_op(a, b, postfix[i].value.operator));
            }
        }
    }

    if (is_empty(&eval_stack) || eval_stack.top > 0)
        return 2;

    *result = eval_stack.items[0];
    return 0;
}

int evaluate_rpn(const char *expr, double *result)
{
    struct Token tokens[MAX_TOKENS];
    size_t token_count;

    int lex_result = lex(expr, tokens, MAX_TOKENS, &token_count);
    if (lex_result != 0)
        return lex_result;

    return evaluate_postfix(tokens, token_count, result);
}

static int validate_token_sequence(struct Token *tokens, size_t size)
{
    int expect_number = 1;
    int paren_count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (tokens[i].type == TOKEN_NUMBER)
        {
            if (!expect_number)
                return 2;
            expect_number = 0;
        }
        else if (tokens[i].type == TOKEN_OPERATOR)
        {
            if (expect_number && tokens[i].value.operator!= '-')
                return 2;
            expect_number = 1;
        }
        else if (tokens[i].type == TOKEN_LPAREN)
        {
            paren_count++;
            expect_number = 1;
        }
        else if (tokens[i].type == TOKEN_RPAREN)
        {
            paren_count--;
            if (paren_count < 0 || expect_number)
                return 2;
            expect_number = 0;
        }
    }

    return (expect_number || paren_count != 0) ? 2 : 0;
}

int evaluate_infix(const char *expr, double *result)
{
    struct Token infix_tokens[MAX_TOKENS];
    struct Token postfix_tokens[MAX_TOKENS];
    size_t infix_size;
    size_t postfix_size;

    int lex_result = lex(expr, infix_tokens, MAX_TOKENS, &infix_size);
    if (lex_result != 0)
        return lex_result;

    int validation_result = validate_token_sequence(infix_tokens, infix_size);
    if (validation_result != 0)
        return validation_result;

    int shunting_yard_result =
        shunting_yard(infix_tokens, infix_size, postfix_tokens, &postfix_size);
    if (shunting_yard_result != 0)
        return shunting_yard_result;

    return evaluate_postfix(postfix_tokens, postfix_size, result);
}
