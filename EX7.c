#include <stdio.h>
#include <string.h>

// Define max unique symbols
#define MAX_SYMBOLS 128

// Function to decrypt using the given substitution map
void decrypt(const char *ciphertext, char *substitution_map) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (substitution_map[(unsigned char)ch]) {
            putchar(substitution_map[(unsigned char)ch]);
        } else {
            putchar(ch); // unknown symbol
        }
    }
    putchar('\n');
}

int main() {
    // Ciphertext
    const char *ciphertext =
        "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 "
        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* "
        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 "
        "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    // Substitution map: index = symbol ASCII, value = actual char
    // Fill in the substitution as per your analysis
    char substitution_map[MAX_SYMBOLS] = {0};

    // Example substitutions based on guesses (adjust based on actual analysis)
    substitution_map['‡'] = 'T';
    substitution_map['†'] = 'H';
    substitution_map['3'] = 'E';
    substitution_map['0'] = 'O';
    substitution_map['5'] = 'F';
    substitution_map['4'] = 'R';
    substitution_map['8'] = 'A';
    substitution_map['6'] = 'N';
    substitution_map[';'] = ' ';
    substitution_map[')'] = 'D';
    substitution_map['*'] = 'S';
    substitution_map['.'] = 'L';
    substitution_map[':'] = 'U';
    substitution_map['('] = 'C';
    substitution_map['9'] = 'M';
    substitution_map['2'] = 'I';
    substitution_map['1'] = 'Y';
    substitution_map[']'] = 'B';
    substitution_map['?'] = 'P';
    substitution_map['—'] = 'X';
    substitution_map['¶'] = 'W';

    // Print decrypted message
    printf("Decrypted message:\n");
    decrypt(ciphertext, substitution_map);

    return 0;
}
