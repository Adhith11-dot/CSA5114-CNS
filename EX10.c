#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

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

// Encrypt pair of characters
void encryptPair(char a, char b) {
    int r1, c1, r2, c2;
    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    if (r1 == r2) {
        // Same row
        printf("%c%c", matrix[r1][(c1 + 1) % SIZE], matrix[r2][(c2 + 1) % SIZE]);
    } else if (c1 == c2) {
        // Same column
        printf("%c%c", matrix[(r1 + 1) % SIZE][c1], matrix[(r2 + 1) % SIZE][c2]);
    } else {
        // Rectangle swap
        printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }
}

// Prepare plaintext for encryption
void prepareAndEncrypt(char *message) {
    char clean[512], pairs[256][2];
    int len = 0, i, j;

    // Clean message: remove non-letters, convert to uppercase
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char ch = toupper(message[i]);
            clean[len++] = (ch == 'J') ? 'I' : ch;
        }
    }

    clean[len] = '\0';

    // Make pairs with Playfair rules
    int k = 0;
    for (i = 0; i < len; i++) {
        char first = clean[i];
        char second = (i + 1 < len) ? clean[i + 1] : 'X';

        if (first == second) {
            second = 'X';
        } else {
            i++; // move to next pair
        }

        pairs[k][0] = first;
        pairs[k][1] = second;
        k++;
    }

    printf("Encrypted Message:\n");
    for (i = 0; i < k; i++) {
        encryptPair(pairs[i][0], pairs[i][1]);
    }
    printf("\n");
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";

    printf("Original Message:\n%s\n\n", message);
    prepareAndEncrypt(message);

    return 0;
}
