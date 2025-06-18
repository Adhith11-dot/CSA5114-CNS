#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0}, x = 0, y = 0;
    used['J' - 'A'] = 1;  // I/J treated as same
    for (int i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (isalpha(ch) && !used[ch - 'A']) {
            matrix[y][x++] = ch;
            used[ch - 'A'] = 1;
            if (x == SIZE) x = 0, y++;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[y][x++] = ch;
            if (x == SIZE) x = 0, y++;
        }
    }
}

void findPos(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] == ch) { *row = i; *col = j; return; }
}

void playfairEncrypt(char text[], char matrix[SIZE][SIZE]) {
    char prepared[100]; int len = 0;

    for (int i = 0; text[i]; i++) {
        char ch = toupper(text[i]);
        if (isalpha(ch)) {
            if (ch == 'J') ch = 'I';
            if (len > 0 && prepared[len - 1] == ch) prepared[len++] = 'X';
            prepared[len++] = ch;
        }
    }
    if (len % 2) prepared[len++] = 'X';
    prepared[len] = '\0';

    printf("Encrypted: ");
    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        findPos(matrix, prepared[i], &r1, &c1);
        findPos(matrix, prepared[i + 1], &r2, &c2);
        if (r1 == r2)
            printf("%c%c", matrix[r1][(c1 + 1) % SIZE], matrix[r2][(c2 + 1) % SIZE]);
        else if (c1 == c2)
            printf("%c%c", matrix[(r1 + 1) % SIZE][c1], matrix[(r2 + 1) % SIZE][c2]);
        else
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }
    printf("\n");
}

int main() {
    char key[100], text[100], matrix[SIZE][SIZE];
    printf("Enter keyword: ");
    scanf("%s", key);
    printf("Enter plaintext: ");
    scanf("%s", text);
    generateMatrix(key, matrix);
    playfairEncrypt(text, matrix);
    return 0;
}
