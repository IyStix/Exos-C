#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "evalexpr.h"

int shunting_yard(struct Token *infix, size_t infix_size, struct Token *postfix,
                  size_t *postfix_size);

#endif // SHUNTING_YARD_H
