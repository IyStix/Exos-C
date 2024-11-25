#include <stddef.h>
#include <stdio.h>

static void inverser_chaine(char *depart, char *fin)
{
    while (depart < fin)
    {
        char temp = *depart;
        *depart++ = *fin;
        *fin-- = temp;
    }
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
        nombre_absolu = nombre_originel;
        nombre_absolu =
            ~nombre_absolu + 1; // Équivalent à -nombre_originel pour les
                                // positifs, et correct pour INT_MIN
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
