CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
SRCS = size.c height.c traversal.c is_perfect.c is_complete.c is_degenerate.c is_full.c is_bst.c
OBJS = $(SRCS:.c=.o)
TARGET = libbinary_tree.a

.PHONY: all clean

all: library

library: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $^

%.o: %.c binary_tree.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
