#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calc_words(char *text);
int calc_letter(char *text);
int calc_sentence(char *text);

int main(){
    char text[200];

    printf("Insert text: ");
    fgets(text, sizeof(text), stdin);

    int words = calc_words(text);
    int letters = calc_letter(text);
    int sentences = calc_sentence(text);

    float L = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    float index = round(0.0588 * L - 0.296 * s - 15.8);
    

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }

}

int calc_words(char *text){
    int counter = 0, in_word = 0;

    for (int i = 0; text[i] != '\0'; i++){
        if (isalpha(text[i])){
            if (!in_word){
                counter++;
                in_word = 1;
            }
        }
        else if (isspace(text[i])){
            in_word = 0;
        }
    }
    return counter;
}


int calc_letter(char *text){
    int counter = 0;

    for (int i = 0; text[i] != '\0'; i++){
        if (isalpha(text[i])){
            counter++;
        }
    }
    return counter;
}

int calc_sentence(char *text){
    int counter = 0;

    for (int i = 0; text[i] != '\0'; i++){
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') &&
            (i == 0 || isalpha(text[i - 1]))){ // Ensure sentence-ending punctuation follows a letter
            counter++;
        }
    }
    return counter;
}
