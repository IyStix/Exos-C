#!/bin/bash

# Compile the program
gcc -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -o my_c_tail main.c my_c_tail.c

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local n="$3"
    local expected_output="$4"
    
    echo "Running test: $test_name"
    actual_output=$(echo -e "$input" | ./my_c_tail "$n")
    if [ "$actual_output" = "$expected_output" ]; then
        echo "PASS"
    else
        echo "FAIL"
        echo "Expected:"
        echo "$expected_output"
        echo "Got:"
        echo "$actual_output"
    fi
    echo
}

# Test 1: Basic functionality
run_test "Basic functionality" \
"line1
line2
line3
line4
line5" 3 \
"line3
line4
line5"

# Test 2: Less lines than requested
run_test "Less lines than requested" \
"line1
line2
line3" 5 \
"line1
line2
line3"

# Test 3: Exactly n lines
run_test "Exactly n lines" \
"line1
line2
line3" 3 \
"line1
line2
line3"

# Test 4: Empty input
run_test "Empty input" "" 5 ""

# Test 5: Single line
run_test "Single line" "only line" 1 "only line"

# Test 6: Long lines
run_test "Long lines" \
"This is a very long line that exceeds the buffer size to test how the program handles long lines of input and ensures that it correctly processes and outputs them without any truncation or errors in the final result.
Another long line to further verify the correct handling of extended input that goes beyond the standard buffer size and checks the robustness of the line processing logic implemented in the stdintail function.
A third lengthy line to provide comprehensive coverage of the program's ability to manage substantial input gracefully and produce accurate output conforming to the specified requirements of the My C tail exercise." 2 \
"Another long line to further verify the correct handling of extended input that goes beyond the standard buffer size and checks the robustness of the line processing logic implemented in the stdintail function.
A third lengthy line to provide comprehensive coverage of the program's ability to manage substantial input gracefully and produce accurate output conforming to the specified requirements of the My C tail exercise."

# Test 7: Many short lines
many_lines=$(seq 1000)
expected_output=$(echo "$many_lines" | tail -n 50)
run_test "Many short lines" "$many_lines" 50 "$expected_output"

echo "All tests completed."
