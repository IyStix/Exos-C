CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
SRCS = create.c add.c pop.c del.c print.c
OBJS = $(SRCS:.c=.o)
TARGET = libheap.a

.PHONY: all clean

all: library

library: $(OBJS)
	ar rcs $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
