#include <stdio.h>
#include <string.h>
#include <ctype.h>

void polyEncrypt(char *text, char *key) {
    int len = strlen(key);
    for (int i = 0, j = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % len]) - 'A';
            text[i] = ((text[i] - base + shift) % 26) + base;
            j++;
        }
    }
}

int main() {
    char text[1000], key[100];
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    scanf("%s", key);
    polyEncrypt(text, key);
    printf("Encrypted text: %s", text);
    return 0;
}
