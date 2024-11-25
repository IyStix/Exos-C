#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

#include "evalexpr.h"

int lex(const char *expr, struct Token *tokens, size_t max_tokens,
        size_t *token_count);

#endif // LEXER_H
