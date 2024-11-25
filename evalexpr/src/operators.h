#ifndef OPERATORS_H
#define OPERATORS_H

int is_operator(char c);
int precedence(char op);
double my_pow(double base, double exponent);
double apply_op(double a, double b, char op);

#endif // OPERATORS_H
