#ifndef TINYPRINTF_H
#define TINYPRINTF_H

int tinyprintf(const char *format, ...);
char *my_itoa(int value, char *s);
char *my_itoa_base(int nombre_originel, char *resultat_final,
                   const char *alphabet_base);
char *my_utoa_base(unsigned int nombre, char *resultat_final,
                   const char *alphabet_base);

#endif // TINYPRINTF_H
