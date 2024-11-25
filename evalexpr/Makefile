SRCS = src/main.c \
       src/evalexpr.c \
       src/lexer.c \
       src/stack.c \
       src/operators.c \
       src/shunting_yard.c 

BIN = evalexpr

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -Wvla
OBJS = $(SRCS:.c=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

check:
	cd tests && ./run_tests.sh

clean:
	rm -f $(OBJS) $(BIN)

.PHONY: all check clean
