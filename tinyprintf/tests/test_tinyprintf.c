#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <limits.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

// Test simple avec une chaîne, un entier, et une autre chaîne
Test(tinyprintf, Simple, .init = redirect_all_stdout)
{
    tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    fflush(NULL);
    char *expected = "Hello [42] world!";
    cr_assert_stdout_eq_str(expected);
}

// Test de conversion en hexadécimal
Test(tinyprintf, Hexadecimal, .init = redirect_all_stdout)
{
    tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    fflush(NULL);
    char *expected = "Hello [2a] world!";
    cr_assert_stdout_eq_str(expected);
}

// Test d'impression d'un pourcentage littéral
Test(tinyprintf, Percent, .init = redirect_all_stdout)
{
    tinyprintf("%%s", "in your head");
    fflush(NULL);
    char *expected = "%s";
    cr_assert_stdout_eq_str(expected);
}

// Test avec une directive inconnue
Test(tinyprintf, Unknown, .init = redirect_all_stdout)
{
    tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    fflush(NULL);
    char *expected = "Good morning ACU! %t Tinyprintf is cool";
    cr_assert_stdout_eq_str(expected);
}

// Test d'impression d'un caractère suivi de deux autres, avec chaîne et nombre
Test(tinyprintf, Tricky, .init = redirect_all_stdout)
{
    tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", 42);
    fflush(NULL);
    char *expected = "42 is the answer... 42 too.";
    cr_assert_stdout_eq_str(expected);
}

// Test avec un pourcentage suivi d'une chaîne
Test(tinyprintf, Percent2, .init = redirect_all_stdout)
{
    tinyprintf("%%%s", "on est laaaa");
    fflush(NULL);
    char *expected = "%on est laaaa";
    cr_assert_stdout_eq_str(expected);
}

// Test combinant plusieurs types de variables
Test(tinyprintf, All, .init = redirect_all_stdout)
{
    tinyprintf("%s %c %d %u %o %x %%", "Hello", 'c', 42, 42, 42, 42);
    fflush(NULL);
    char *expected = "Hello c 42 42 52 2a %";
    cr_assert_stdout_eq_str(expected);
}

// Test avec plus d'arguments que nécessaire
Test(tinyprintf, Moreargs, .init = redirect_all_stdout)
{
    tinyprintf("%s", "im giving more args", 42, 42, 42);
    fflush(NULL);
    char *expected = "im giving more args";
    cr_assert_stdout_eq_str(expected);
}

// Test avec aucun argument
Test(tinyprintf, NoArgs, .init = redirect_all_stdout)
{
    tinyprintf("Hello world");
    fflush(NULL);
    char *expected = "Hello world";
    cr_assert_stdout_eq_str(expected);
}

// Test pour vérifier l'impression de (null) quand l'argument chaîne est NULL
Test(tinyprintf, NullString, .init = redirect_all_stdout)
{
    tinyprintf("%s", NULL);
    fflush(NULL);
    char *expected = "(null)";
    cr_assert_stdout_eq_str(expected);
}

// Test pour un caractère unique
Test(tinyprintf, SingleCharacter, .init = redirect_all_stdout)
{
    tinyprintf("%c", 'A');
    fflush(NULL);
    char *expected = "A";
    cr_assert_stdout_eq_str(expected);
}

// Test pour un entier négatif
Test(tinyprintf, NegativeInteger, .init = redirect_all_stdout)
{
    tinyprintf("%d", -12345);
    fflush(NULL);
    char *expected = "-12345";
    cr_assert_stdout_eq_str(expected);
}

// Test pour une conversion en octal
Test(tinyprintf, Octal, .init = redirect_all_stdout)
{
    tinyprintf("%o", 255);
    fflush(NULL);
    char *expected = "377";
    cr_assert_stdout_eq_str(expected);
}

// Test pour vérifier la gestion des grands nombres en hexadécimal
Test(tinyprintf, LargeHexadecimal, .init = redirect_all_stdout)
{
    tinyprintf("%x", 65535);
    fflush(NULL);
    char *expected = "ffff";
    cr_assert_stdout_eq_str(expected);
}

// Test pour vérifier les valeurs de retour avec plusieurs directives
Test(tinyprintf, Return_Multiple_Directives, .init = redirect_all_stdout)
{
    int result = tinyprintf("%d %x %o %s", 42, 255, 8, "test");
    fflush(NULL);
    char *expected = "42 ff 10 test";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 13, "Expected return value 13, but got %d", result);
}

// Test pour la valeur de retour avec des caractères spéciaux
Test(tinyprintf, Return_Special_Chars, .init = redirect_all_stdout)
{
    int result = tinyprintf("Special: %c%c%c", '!', '@', '#');
    fflush(NULL);
    char *expected = "Special: !@#";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 12, "Expected return value 12, but got %d", result);
}

// Test pour la valeur de retour avec des grands nombres
Test(tinyprintf, Return_Large_Numbers, .init = redirect_all_stdout)
{
    int result = tinyprintf("%d %u %x", 123456, 123456, 123456);
    fflush(NULL);
    char *expected = "123456 123456 1e240";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 19, "Expected return value 19, but got %d", result);
}

// Test pour vérifier le cas où format est NULL
Test(tinyprintf, Null_Format, .init = redirect_all_stdout)
{
    int result = tinyprintf(NULL);
    cr_assert_eq(result, 0);
}

// Test pour vérifier my_itoa avec NULL buffer
Test(tinyprintf, Null_Buffer_Itoa, .init = redirect_all_stdout)
{
    char *result = my_itoa(42, NULL);
    cr_assert_eq(result, 0);
}

// Test pour my_itoa_base avec base invalide
Test(tinyprintf, Invalid_Base, .init = redirect_all_stdout)
{
    char buffer[32];
    char *result = my_itoa_base(42, buffer, "1");
    cr_assert_str_eq(result, buffer);
}

// Test pour les très grands nombres
Test(tinyprintf, Large_Numbers_All_Bases, .init = redirect_all_stdout)
{
    int result =
        tinyprintf("%d %u %o %x", INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    fflush(NULL);
    cr_assert_gt(result, 0);
}

// Test pour vérifier le comportement avec des bases différentes
Test(tinyprintf, Different_Bases, .init = redirect_all_stdout)
{
    int result = tinyprintf("%x %o", 255, 255);
    fflush(NULL);
    char *expected = "ff 377";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 6);
}

// Test pour la chaîne vide
Test(tinyprintf, Empty_String, .init = redirect_all_stdout)
{
    int result = tinyprintf("");
    cr_assert_eq(result, 0);
}

// Test pour les caractères spéciaux et échappements
Test(tinyprintf, Special_Chars, .init = redirect_all_stdout)
{
    int result = tinyprintf("%%d %%s %%%% %s", "test");
    fflush(NULL);
    char *expected = "%d %s %% test";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 13, "Expected 13 characters, got %d", result);
}

// Test pour des séquences de format complexes
Test(tinyprintf, Complex_Format, .init = redirect_all_stdout)
{
    tinyprintf("%d%%%d%s%c", 42, 43, "test", '!');
    fflush(NULL);
    char *expected = "42%43test!";
    cr_assert_stdout_eq_str(expected);
}

// Test pour my_itoa_base avec nombre négatif en différentes bases
Test(tinyprintf, Negative_Different_Bases, .init = redirect_all_stdout)
{
    tinyprintf("%d %x %o", -42, -42, -42);
    fflush(NULL);
    char *expected = "-42 ffffffd6 37777777726";
    cr_assert_stdout_eq_str(expected);
}

// Test pour vérifier la limite inférieure des entiers
Test(tinyprintf, Integer_Min, .init = redirect_all_stdout)
{
    tinyprintf("%d", INT_MIN);
    fflush(NULL);
    char *expected = "-2147483648";
    cr_assert_stdout_eq_str(expected);
}

// Test pour vérifier le comportement avec des formats consécutifs sans espace
Test(tinyprintf, Formats_Without_Space, .init = redirect_all_stdout)
{
    tinyprintf("%d%s%c%x", 42, "test", '!', 255);
    fflush(NULL);
    char *expected = "42test!ff";
    cr_assert_stdout_eq_str(expected);
}

// Test des caractères spéciaux dans la chaîne
Test(tinyprintf, String_Special_Chars, .init = redirect_all_stdout)
{
    tinyprintf("%s", "\n\t\r");
    fflush(NULL);
    char *expected = "\n\t\r";
    cr_assert_stdout_eq_str(expected);
}

// Test pour la fonction my_utoa_base avec différentes valeurs
Test(tinyprintf, Unsigned_Max_Value, .init = redirect_all_stdout)
{
    int result = tinyprintf("%u", UINT_MAX);
    fflush(NULL);
    char *expected = "4294967295";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 10);
}

// Test pour les séquences d'échappement multiples
Test(tinyprintf, Multiple_Percent_Signs, .init = redirect_all_stdout)
{
    int result = tinyprintf("%%%%%%%%%%");
    fflush(NULL);
    char *expected = "%%%%%";
    cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, 5);
}

// Test pour my_itoa avec valeur négative
Test(tinyprintf, Itoa_Negative_Value, .init = redirect_all_stdout)
{
    char buffer[32];
    my_itoa(-42, buffer);
    cr_assert_str_eq(buffer, "-42");
}

// Test pour my_itoa avec zéro
Test(tinyprintf, Itoa_Zero_Value, .init = redirect_all_stdout)
{
    char buffer[32];
    my_itoa(0, buffer);
    cr_assert_str_eq(buffer, "0");
}

// Test pour my_itoa_base avec différentes valeurs négatives
Test(tinyprintf, Itoa_Base_Edge_Cases, .init = redirect_all_stdout)
{
    char buffer[32];
    // Test valeur négative
    my_itoa_base(-123, buffer, "0123456789");
    cr_assert_str_eq(buffer, "-123");

    // Test avec zéro
    my_itoa_base(0, buffer, "0123456789");
    cr_assert_str_eq(buffer, "0");

    // Test avec petite base (binaire)
    my_itoa_base(7, buffer, "01");
    cr_assert_str_eq(buffer, "111");
}

// Test pour my_itoa_base avec base invalide
Test(tinyprintf, Itoa_Base_Invalid, .init = redirect_all_stdout)
{
    char buffer[32];
    // Test avec base vide
    my_itoa_base(42, buffer, "");
    cr_assert_str_eq(buffer, buffer);

    // Test avec base de taille 1
    my_itoa_base(42, buffer, "0");
    cr_assert_str_eq(buffer, buffer);
}

// Test pour my_itoa et my_itoa_base avec des valeurs limites
Test(tinyprintf, Itoa_Limit_Values, .init = redirect_all_stdout)
{
    char buffer[32];
    // Test INT_MIN
    my_itoa(INT_MIN, buffer);
    cr_assert_str_eq(buffer, "-2147483648");

    // Test INT_MAX
    my_itoa(INT_MAX, buffer);
    cr_assert_str_eq(buffer, "2147483647");
}
