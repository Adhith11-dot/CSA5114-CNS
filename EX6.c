#include <stdio.h>
#include <ctype.h>

// Modular inverse of 7 mod 26 is 15
#define A_INV 15
#define B 25

// Decrypt one character
char decrypt_char(char ch) {
    if (isalpha(ch)) {
        ch = toupper(ch);
        int y = ch - 'A';
        int x = (A_INV * (y - B + 26)) % 26;
        return 'A' + x;
    }
    return ch;
}

// Decrypt the full ciphertext
void decrypt_affine(char *cipher) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        printf("%c", decrypt_char(cipher[i]));
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "BU..."; // Replace with actual ciphertext
    printf("Decrypted text: ");
    decrypt_affine(ciphertext);
    return 0;
}
