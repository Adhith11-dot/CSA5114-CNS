#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_LEN 26

// Generate cipher alphabet using keyword
void generate_cipher_alphabet(char cipher[], const char *keyword) {
    int used[26] = {0};
    int i, j = 0;

    // Add keyword (unique letters only)
    for (i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining letters of alphabet
    for (i = 0; i < ALPHABET_LEN; i++) {
        if (!used[i]) {
            cipher[j++] = 'A' + i;
        }
    }
}

// Encrypt plaintext using cipher alphabet
void encrypt(const char *plaintext, const char *cipher) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char is_lower = islower(plaintext[i]);
            int index = tolower(plaintext[i]) - 'a';
            char enc = cipher[index];
            printf("%c", is_lower ? tolower(enc) : enc);
        } else {
            printf("%c", plaintext[i]);
        }
    }
}

// Decrypt ciphertext using cipher alphabet
void decrypt(const char *ciphertext, const char *cipher) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char is_lower = islower(ciphertext[i]);
            char ch = toupper(ciphertext[i]);
            int index = -1;

            // Find letter in cipher array
            for (int j = 0; j < ALPHABET_LEN; j++) {
                if (cipher[j] == ch) {
                    index = j;
                    break;
                }
            }
            printf("%c", is_lower ? 'a' + index : 'A' + index);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
}

int main() {
    const char keyword[] = "CIPHER";
    char cipher[ALPHABET_LEN];
    const char plaintext[] = "meet me at the park at eleven am";

    generate_cipher_alphabet(cipher, keyword);

    printf("Keyword: %s\n", keyword);
    printf("Cipher Alphabet: ");
    for (int i = 0; i < ALPHABET_LEN; i++) {
        printf("%c ", cipher[i]);
    }
    printf("\n");

    printf("\nPlaintext:\n%s\n", plaintext);

    printf("\nEncrypted:\n");
    encrypt(plaintext, cipher);

    printf("\n\nDecrypted:\n");
    encrypt(plaintext, cipher);  // just for reference

    return 0;
}
