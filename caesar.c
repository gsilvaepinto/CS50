#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int is_number(char str[]) {
    if (str[0] == '\0') return 0;  // Reject empty strings

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Return 0 if not a digit
        }
    }
    return 1; // Return 1 if all are digits
}

int main(int argc, char *argv[]) {
    if (argc != 2 || !is_number(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char str[100];
    int k = atoi(argv[1]); // Convert key to an integer

    printf("plaintext: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from input
    size_t length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }

    printf("ciphertext: ");

    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            printf("%c", (((str[i] - 'a') + k) % 26) + 'a');
        } else if (isupper(str[i])) {
            printf("%c", (((str[i] - 'A') + k) % 26) + 'A');
        } else {
            printf("%c", str[i]); // Print unchanged for non-letters
        }
    }
    printf("\n");
    return 0;
}
