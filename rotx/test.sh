#!/bin/bash

# Fonction pour exécuter un test
run_test() {
    local test_name="$1"
    local input="$2"
    local rotation="$3"
    local expected="$4"

    echo "Test: $test_name"
    result=$(echo -n "$input" | ./rotx "$rotation")
    if [ "$result" = "$expected" ]; then
        echo "PASS"
    else
        echo "FAIL"
        echo "Expected: $expected"
        echo "Got     : $result"
    fi
    echo
}

# Test 1: Rotation simple de l'alphabet
run_test "Rotation simple de l'alphabet" "abcdefghijklmnopqrstuvwxyz" "1" "bcdefghijklmnopqrstuvwxyza"

# Test 2: Rotation avec boucle (z -> a)
run_test "Rotation avec boucle" "xyz" "3" "abc"

# Test 3: Rotation des majuscules
run_test "Rotation des majuscules" "XYZ" "3" "ABC"

# Test 4: Rotation des chiffres
run_test "Rotation des chiffres" "789" "3" "012"

# Test 5: Caractères spéciaux inchangés
run_test "Caractères spéciaux inchangés" "a!b@c#" "1" "b!c@d#"

# Test 6: Rotation négative
run_test "Rotation négative" "abc" "-1" "zab"

# Test 7: Grande rotation (équivalent à une petite rotation)
run_test "Grande rotation" "abc" "27" "bcd"

# Test 8: Pas de rotation (x = 0)
run_test "Pas de rotation" "abc123" "0" "abc123"

# Test 9: Texte mixte
run_test "Texte mixte" "Hello, World! 123" "13" "Uryyb, Jbeyq! 456"

# Test 10: Rotation de 26 (équivalent à pas de rotation pour les lettres)
run_test "Rotation de 26" "abcABC" "26" "abcABC"

# Vérification des cas d'erreur
echo "Test: Aucun argument"
./rotx > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "PASS (Le programme s'est terminé sans erreur)"
else
    echo "FAIL (Le programme a retourné une erreur)"
fi
echo

echo "Test: Argument invalide"
./rotx "abc" > /dev/null 2>&1
if [ $? -eq 1 ]; then
    echo "PASS (Le programme a retourné une erreur comme attendu)"
else
    echo "FAIL (Le programme n'a pas retourné d'erreur)"
fi
echo
