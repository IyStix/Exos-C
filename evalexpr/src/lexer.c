#include "lexer.h"

#include <ctype.h>
#include <stdlib.h>

#include "operators.h"

int lex(const char *expr, struct Token *tokens, size_t max_tokens,
        size_t *token_count)
{
    *token_count = 0;
    const char *p = expr;

    while (*p && *token_count < max_tokens)
    {
        if (isspace(*p))
        {
            p++;
            continue;
        }

        if (isdigit(*p)
            || (*p == '-'
                && (isdigit(*(p + 1))
                    || (*token_count == 0
                        || tokens[*token_count - 1].type == TOKEN_OPERATOR
                        || tokens[*token_count - 1].type == TOKEN_LPAREN))))
        {
            char *end;
            tokens[*token_count].type = TOKEN_NUMBER;
            tokens[*token_count].value.number = strtod(p, &end);
            p = end;
        }
        else if (is_operator(*p))
        {
            tokens[*token_count].type = TOKEN_OPERATOR;
            tokens[*token_count].value.operator= * p;
            p++;
        }
        else if (*p == '(')
        {
            tokens[*token_count].type = TOKEN_LPAREN;
            p++;
        }
        else if (*p == ')')
        {
            tokens[*token_count].type = TOKEN_RPAREN;
            p++;
        }
        else
        {
            return 1;
        }

        (*token_count)++;
    }

    return (*p != '\0') ? 1 : 0;
}
