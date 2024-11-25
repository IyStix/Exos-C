CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -I/opt/homebrew/include
COVERAGE_FLAGS=-fprofile-arcs -ftest-coverage
LDFLAGS=-fsanitize=address -g -L/opt/homebrew/lib
LDLIBS=-lcriterion

SRC=src/tinyprintf.c
OBJ=$(SRC:.c=.o)

TEST=tests/test_tinyprintf.c
OBJ_TEST=$(TEST:.c=.o)

all: $(OBJ)

check: clean
	$(CC) $(CFLAGS) -c $(SRC) -o src/tinyprintf.o
	$(CC) $(CFLAGS) -c $(TEST) -o tests/test_tinyprintf.o
	$(CC) $(LDFLAGS) $(LDLIBS) -o tinyprintf src/tinyprintf.o tests/test_tinyprintf.o
	./tinyprintf

coverage: clean
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $(SRC) -o src/tinyprintf.o
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) -c $(TEST) -o tests/test_tinyprintf.o
	$(CC) $(COVERAGE_FLAGS) $(LDFLAGS) $(LDLIBS) -o tinyprintf src/tinyprintf.o tests/test_tinyprintf.o
	./tinyprintf
	mkdir -p coverage
	gcov -r src/tinyprintf.c
	lcov --capture --directory src --output-file coverage/coverage.info
	genhtml coverage/coverage.info --output-directory coverage/report
	open coverage/report/index.html

clean:
	$(RM) $(OBJ_TEST) $(OBJ) tinyprintf
	$(RM) -f *.gcno *.gcda coverage.info
	$(RM) -rf coverage
	$(RM) -f src/*.gcno src/*.gcda tests/*.gcno tests/*.gcda
	$(RM) -f *.gcov

.PHONY: all check clean coverage
