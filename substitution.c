#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage: /substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26){
        printf("Key must contain 26 letters\n");
        return 1;
    }
    for (int i = 0; i < 26; i++){
        if (!isalpha(argv[1][i])){
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        for (int j = i + 1; j < 26; j++){
            if (tolower(argv[1][j]) == tolower(argv[1][i])){
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    char str[100];
    printf("plaintext: ");
    fgets(str, sizeof(str), stdin);

    size_t length = strlen(str);
    if (str[length - 1] == '\n'){
        str[length - 1] = '\0';
    }
    
    printf("ciphertext: ");

    for (int i = 0; i < length; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            printf("%c", toupper(argv[1][str[i] - 'A']));
        }
        else if (str[i] >= 'a' && str[i] <= 'z'){
            printf("%c", tolower(argv[1][str[i] - 'a']));
        }
        else if(!isalpha(str[i])){
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;   
}