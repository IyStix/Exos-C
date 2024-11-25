#!/bin/sh

EVALEXPR="../evalexpr"

test_infix()
{
    expr="$1"
    expected=$(echo "$expr" | bc 2>/dev/null)
    result=$(echo "$expr" | $EVALEXPR 2>/dev/null)
    exitcode=$?
    
    if [ $exitcode -eq 0 ] && [ "$result" = "$expected" ]; then
        echo "OK - infix: $expr = $result"
        return 0
    else
        echo "KO - infix: $expr"
        echo "Expected: $expected"
        echo "Got: $result (exit code: $exitcode)"
        return 1
    fi
}

test_rpn()
{
    expr="$1"
    expected="$2"
    result=$(echo "$expr" | $EVALEXPR -rpn 2>/dev/null)
    exitcode=$?
    
    if [ $exitcode -eq 0 ] && [ "$result" = "$expected" ]; then
        echo "OK - rpn: $expr = $result"
        return 0
    else
        echo "KO - rpn: $expr"
        echo "Expected: $expected"
        echo "Got: $result (exit code: $exitcode)"
        return 1
    fi
}

test_error()
{
    expr="$1"
    expected_code="$2"
    mode="$3"
    
    if [ "$mode" = "rpn" ]; then
        echo "$expr" | $EVALEXPR -rpn >/dev/null 2>&1
    else
        echo "$expr" | $EVALEXPR >/dev/null 2>&1
    fi
    
    exitcode=$?
    
    if [ $exitcode -eq $expected_code ]; then
        echo "OK - error test: $expr (expected code $expected_code)"
        return 0
    else
        echo "KO - error test: $expr"
        echo "Expected code: $expected_code"
        echo "Got: $exitcode"
        return 1
    fi
}

# Basic infix tests
test_infix "1 + 1"
test_infix "2 * 3"
test_infix "10 / 2"
test_infix "7 - 3"
test_infix "2 ^ 3"
test_infix "10 % 3"

# Complex infix tests
test_infix "1 + 2 * 3"
test_infix "(1 + 2) * 3"
test_infix "2 ^ 3 ^ 2"
test_infix "(2 ^ 3) ^ 2"

# Unary operators tests
test_infix "-5 + 3"
test_infix "5 + (-3)"

# Basic RPN tests
test_rpn "1 1 +" "2"
test_rpn "2 3 *" "6"
test_rpn "10 2 /" "5"
test_rpn "7 3 -" "4"
test_rpn "2 3 ^" "8"
test_rpn "10 3 %" "1"

# Complex RPN tests
test_rpn "1 2 3 * +" "7"
test_rpn "2 3 4 + *" "14"
test_rpn "5 2 2 ^ 3 + *" "35"

# Error cases - Lexical errors (1)
test_error "a + 1" 1 "infix"
test_error "1 + b" 1 "infix"
test_error "a b +" 1 "rpn"

# Error cases - Syntax errors (2)
test_error "1 + " 2 "infix"
test_error "( 1 + 2" 2 "infix"
test_error "1 1" 2 "rpn"
test_error "+" 2 "rpn"

# Error cases - Arithmetic errors (3)
test_error "1 / 0" 3 "infix"
test_error "1 % 0" 3 "infix"
test_error "1 0 /" 3 "rpn"
test_error "1 0 %" 3 "rpn"
