#ifndef MY_STRTOK_R_H
#define MY_STRTOK_R_H

#include <stddef.h>

char *my_strtok_r(char *str, const char *delim, char **saveptr);

static inline int is_delim(char c, const char *delim);

static char *find_next_token(char *str, const char *delim);

#endif // MY_STRTOK_R_H
