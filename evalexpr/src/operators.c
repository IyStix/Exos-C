#include "operators.h"

#include <stdio.h>
#include <stdlib.h>

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

double my_pow(double base, double exponent)
{
    double result = 1.0;
    int i;
    int int_exponent;

    if (exponent < 0)
    {
        base = 1.0 / base;
        exponent = -exponent;
    }

    int_exponent = exponent;
    if (exponent != int_exponent)
    {
        fprintf(stderr, "Error: Non-integer exponent not supported\n");
        exit(3);
    }

    for (i = 0; i < int_exponent; i++)
    {
        result *= base;
    }

    return result;
}

double apply_op(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            fprintf(stderr, "Division by zero\n");
            exit(3);
        }
        return a / b;
    case '%':
        if (b == 0)
        {
            fprintf(stderr, "Modulo by zero\n");
            exit(3);
        }
        {
            int ia = a;
            int ib = b;
            return ia % ib;
        }
    case '^':
        return my_pow(a, b);
    default:
        fprintf(stderr, "Unknown operator\n");
        exit(1);
    }
}
