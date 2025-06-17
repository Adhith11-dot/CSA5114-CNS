#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000], cipher[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = toupper(text[i]) - 'A';
            char sub = cipher[index];
            text[i] = isupper(text[i]) ? sub : tolower(sub);
        }
    }

    printf("Ciphertext: %s", text);
    return 0;
}
