CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
AR = ar
ARFLAGS = rcs
INCLUDE = -Iinclude

SRC = src/libstream.c
OBJ = $(SRC:.c=.o)
LIB = libstream.a
TEST_SRC = test_libstream.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXEC = test_libstream

.PHONY: all clean test library

all: library

library: $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lstream

clean:
	$(RM) $(OBJ) $(LIB) $(TEST_OBJ) $(TEST_EXEC)
