CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
SRC = fifo_access.c fifo_setup_destroy.c
OBJ = $(SRC:.c=.o)
LIB = libfifo.a

.PHONY: all clean

all: library

library: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test_fifo: test_fifo.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L. -lfifo

clean:
	$(RM) $(OBJ) $(LIB) test_fifo test_fifo.o

test: test_fifo
	./test_fifo
