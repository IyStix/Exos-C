#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Déclaration de la fonction replace_line
int replace_line(const char *file_in, const char *file_out, const char *content, int n);

// Fonction helper pour lire le contenu d'un fichier
char* read_file_content(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error reading file");
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = 0;
    return string;
}

void test_replace_second_line(void) {
    // Créer un fichier d'entrée temporaire
    FILE *temp = fopen("temp_input.txt", "w");
    fprintf(temp, "first line\nsecond line\nthird line\n");
    fclose(temp);

    // Appeler replace_line
    int result = replace_line("temp_input.txt", "temp_output.txt", "replacesecond line\n", 2);

    // Vérifier le résultat
    assert(result == 0);

    // Lire le contenu du fichier de sortie
    char *output = read_file_content("temp_output.txt");
    const char *expected = "first line\nreplacesecond line\nthird line\n";
    
    printf("Actual output:\n%s\n", output);
    printf("Expected output:\n%s\n", expected);

    assert(strcmp(output, expected) == 0);

    // Nettoyer
    free(output);
    remove("temp_input.txt");
    remove("temp_output.txt");

    printf("Test replace second line: PASSED\n");
}

int main(void) {
    test_replace_second_line();
    return 0;
}
