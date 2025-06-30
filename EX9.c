#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

// Remove duplicates and fill the matrix
void generateMatrix(const char *key) {
    int seen[26] = {0};
    int x = 0, y = 0;

    for (int i = 0; i < strlen(key); i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!isalpha(ch) || seen[ch - 'A']) continue;

        matrix[y][x++] = ch;
        seen[ch - 'A'] = 1;
        if (x == SIZE) {
            x = 0;
            y++;
        }
    }

    // Fill remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!seen[ch - 'A']) {
            matrix[y][x++] = ch;
            seen[ch - 'A'] = 1;
            if (x == SIZE) {
                x = 0;
                y++;
            }
        }
    }
}

// Find position of character in matrix
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

// Decrypt a pair of characters
void decryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    if (r1 == r2) {
        // Same row
        c1 = (c1 + SIZE - 1) % SIZE;
        c2 = (c2 + SIZE - 1) % SIZE;
    } else if (c1 == c2) {
        // Same column
        r1 = (r1 + SIZE - 1) % SIZE;
        r2 = (r2 + SIZE - 1) % SIZE;
    } else {
        // Rectangle swap
        int temp = c1;
        c1 = c2;
        c2 = temp;
    }

    printf("%c%c", matrix[r1][c1], matrix[r2][c2]);
}

void decryptMessage(const char *ciphertext) {
    for (int i = 0; i < strlen(ciphertext); i += 2) {
        if (isalpha(ciphertext[i]) && isalpha(ciphertext[i + 1])) {
            decryptPair(toupper(ciphertext[i]), toupper(ciphertext[i + 1]));
        }
    }
}

int main() {
    const char *key = "MONARCHY"; // Change this to try different keywords

    // Ciphertext given
    const char *ciphertext =
        "KXJEYUREBEZWEHEWRYTUHEYFS"
        "KREHEGOYFIWTTTUOLKSYCAJPO"
        "BOTEIZONTXBYBNTGONEYCUZWR"
        "GDSONSXBOUYWRHEBAAHYUSEDQ";

    // Generate matrix
    generateMatrix(key);

    // Show matrix
    printf("Playfair Matrix (Keyword: %s):\n", key);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDecrypted Message:\n");
    decryptMessage(ciphertext);

    printf("\n");
    return 0;
}
