#include <stdio.h>
#include <string.h>

#include "evalexpr.h"

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [-rpn]\n", argv[0]);
        return 4;
    }

    char input[1024];
    if (!fgets(input, sizeof(input), stdin))
    {
        return 0;
    }

    input[strcspn(input, "\n")] = 0;

    double result;
    int error;

    if (argc == 2 && strcmp(argv[1], "-rpn") == 0)
    {
        error = evaluate_rpn(input, &result);
    }
    else
    {
        error = evaluate_infix(input, &result);
    }

    if (error)
    {
        return error;
    }

    printf("%.0f\n", result);
    return 0;
}
