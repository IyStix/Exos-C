CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
AR = ar
ARFLAGS = rcs

SRCS = vector.c
OBJS = $(SRCS:.c=.o)
TARGET = libvector.a

.PHONY: all clean library

all: library

library: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
