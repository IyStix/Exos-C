#ifndef EVALEXPR_H
#define EVALEXPR_H

#include <stddef.h>

#define MAX_TOKENS 100

enum TokenType
{
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_LPAREN,
    TOKEN_RPAREN
};

struct Token
{
    enum TokenType type;
    union
    {
        double number;
        char operator;
    } value;
};

int evaluate_rpn(const char *expr, double *result);
int evaluate_infix(const char *expr, double *result);

#endif // EVALEXPR_H
