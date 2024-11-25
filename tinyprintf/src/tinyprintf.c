#include "tinyprintf.h"

#include <err.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void inverser_chaine(char *depart, char *fin)
{
    while (depart < fin)
    {
        char temp = *depart;
        *depart++ = *fin;
        *fin-- = temp;
    }
}

char *my_itoa(int value, char *s)
{
    if (!s)
        return 0;

    char *original_s = s;
    int is_negative = 0;
    unsigned int uvalue;

    if (value < 0)
    {
        is_negative = 1;
        uvalue = 0 - value;
    }
    else
    {
        uvalue = value;
    }

    do
    {
        *s++ = "0123456789"[uvalue % 10];
        uvalue /= 10;
    } while (uvalue > 0);

    if (is_negative)
        *s++ = '-';

    *s = '\0';
    inverser_chaine(original_s, s - 1);
    return original_s;
}

char *my_itoa_base(int nombre_originel, char *resultat_final,
                   const char *alphabet_base)
{
    int base_numerique = 0;
    while (alphabet_base[base_numerique] != '\0')
        base_numerique++;

    if (base_numerique <= 1)
        return resultat_final;

    int est_negatif = 0;
    unsigned int nombre_absolu;

    if (nombre_originel < 0 && base_numerique == 10)
    {
        est_negatif = 1;
        nombre_absolu = -nombre_originel;
    }
    else
    {
        nombre_absolu = nombre_originel;
    }

    char *position_courante = resultat_final;

    do
    {
        *position_courante++ = alphabet_base[nombre_absolu % base_numerique];
        nombre_absolu /= base_numerique;
    } while (nombre_absolu > 0);

    if (est_negatif)
        *position_courante++ = '-';

    *position_courante = '\0';
    inverser_chaine(resultat_final, position_courante - 1);
    return resultat_final;
}

char *my_utoa_base(unsigned int nombre, char *resultat_final,
                   const char *alphabet_base)
{
    int base_numerique = 0;
    while (alphabet_base[base_numerique] != '\0')
        base_numerique++;

    if (base_numerique <= 1)
        return resultat_final;

    char *position_courante = resultat_final;

    do
    {
        *position_courante++ = alphabet_base[nombre % base_numerique];
        nombre /= base_numerique;
    } while (nombre > 0);

    *position_courante = '\0';
    inverser_chaine(resultat_final, position_courante - 1);
    return resultat_final;
}

static int print_with_base_signed(int value)
{
    char buffer[32];
    my_itoa_base(value, buffer, "0123456789");
    char *str = buffer;
    int len = 0;
    while (*str)
    {
        putchar(*str++);
        len++;
    }
    return len;
}

static int print_with_base_unsigned(unsigned int value, int base)
{
    char buffer[32];
    const char *alphabet = (base == 16) ? "0123456789abcdef"
        : (base == 8)                   ? "01234567"
                                        : "0123456789";
    my_utoa_base(value, buffer, alphabet);
    char *str = buffer;
    int len = 0;
    while (*str)
    {
        putchar(*str++);
        len++;
    }
    return len;
}

static int handle_string(char *str)
{
    int count = 0;
    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        putchar(*str++);
        count++;
    }
    return count;
}

static int handle_char(va_list *args)
{
    int ch = va_arg(*args, int);
    putchar(ch);
    return 1;
}

static int handle_signed_number(va_list *args)
{
    int value = va_arg(*args, int);
    return print_with_base_signed(value);
}

static int handle_unsigned_number(va_list *args, int base)
{
    unsigned int value = va_arg(*args, unsigned int);
    return print_with_base_unsigned(value, base);
}

static int handle_unknown(char format_char)
{
    putchar('%');
    putchar(format_char);
    return 2;
}

static int handle_format(char format_char, va_list *args)
{
    switch (format_char)
    {
    case 'd':
        return handle_signed_number(args);
    case 'u':
        return handle_unsigned_number(args, 10);
    case 's':
        return handle_string(va_arg(*args, char *));
    case 'c':
        return handle_char(args);
    case 'o':
        return handle_unsigned_number(args, 8);
    case 'x':
        return handle_unsigned_number(args, 16);
    case '%':
        putchar('%');
        return 1;
    default:
        return handle_unknown(format_char);
    }
}

int tinyprintf(const char *format, ...)
{
    if (!format)
        return 0;

    va_list args;
    va_start(args, format);
    int count = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += handle_format(*format, &args);
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
