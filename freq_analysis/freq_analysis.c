#include <stdio.h>

void freq_analysis(const char enigma[], const char rosetta[])
{
    int letter_count[26] = { 0 };
    int frequency_ranking[26] = { 0 };
    char decryption_key[26];
    int unique_symbols = 0;

    for (int i = 0; enigma[i]; i++)
    {
        letter_count[enigma[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letter_count[i] > 0)
        {
            frequency_ranking[unique_symbols] = letter_count[i];
            decryption_key[unique_symbols] = i + 'A';
            unique_symbols++;
        }
    }

    for (int outer = 0; outer < unique_symbols - 1; outer++)
    {
        for (int inner = 0; inner < unique_symbols - outer - 1; inner++)
        {
            if (frequency_ranking[inner] < frequency_ranking[inner + 1])
            {
                int temp_freq = frequency_ranking[inner];
                frequency_ranking[inner] = frequency_ranking[inner + 1];
                frequency_ranking[inner + 1] = temp_freq;

                char temp_char = decryption_key[inner];
                decryption_key[inner] = decryption_key[inner + 1];
                decryption_key[inner + 1] = temp_char;
            }
        }
    }

    for (int cipher = 0; cipher < 26; cipher++)
    {
        if (letter_count[cipher] > 0)
        {
            for (int plain = 0; plain < unique_symbols; plain++)
            {
                if (decryption_key[plain] == cipher + 'A')
                {
                    printf("%c %c\n", cipher + 'A', rosetta[plain]);
                    break; // One secret at a time
                }
            }
        }
    }
}
