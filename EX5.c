#include <stdio.h>
#include <ctype.h>

int modInverse(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;
    return -1; // No inverse
}

int isCoprime(int a) {
    int m = 26;
    while (m) {
        int temp = m;
        m = a % m;
        a = temp;
    }
    return a == 1;
}

char encryptChar(char ch, int a, int b) {
    if (isalpha(ch)) {
        int p = toupper(ch) - 'A';
        return ((a * p + b) % 26) + 'A';
    }
    return ch;
}

char decryptChar(char ch, int a, int b) {
    int a_inv = modInverse(a);
    if (a_inv == -1) return '?'; // invalid a
    int C = toupper(ch) - 'A';
    return ((a_inv * (C - b + 26)) % 26) + 'A';
}

int main() {
    int a = 5, b = 8;
    if (!isCoprime(a)) {
        printf("Invalid 'a'. Must be coprime with 26.\n");
        return 1;
    }

    char plaintext[] = "HELLO";
    char encrypted[100], decrypted[100];
    
    // Encrypt
    for (int i = 0; plaintext[i]; i++)
        encrypted[i] = encryptChar(plaintext[i], a, b);
    encrypted[5] = '\0';

    // Decrypt
    for (int i = 0; encrypted[i]; i++)
        decrypted[i] = decryptChar(encrypted[i], a, b);
    decrypted[5] = '\0';

    printf("Plaintext:  %s\n", plaintext);
    printf("Encrypted:  %s\n", encrypted);
    printf("Decrypted:  %s\n", decrypted);
    return 0;
}
