#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

int compute_score(char *word);

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(){
    char player1[MAX_LENGTH + 1];
    char player2[MAX_LENGTH + 1];

    printf("Player 1: ");
    if (fgets(player1, sizeof(player1), stdin)){
        player1[strcspn(player1, "\n")] = '\0';
        if (strlen(player1) == MAX_LENGTH && player1[MAX_LENGTH - 1] != '\0'){
            while((getchar()) != '\n');
        }
    }
    
    printf("Player 2: ");
    if (fgets(player2, sizeof(player2), stdin)){
        player2[strcspn(player2, "\n")] = '\0';
        if (strlen(player2) == MAX_LENGTH && player2[MAX_LENGTH - 1] != '\0'){
            while((getchar()) != '\n');
        }
    }
    
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    if (score1 > score2){
        printf("Player 1 Wins (%dpts) - (%dpts)\n", score1, score2);
    }
    else if (score1 < score2){
        printf("Player 2 Wins (%dpts) - (%dpts)\n", score2, score1);
    }
    else {
        printf("Tie (%dpts) - (%dpts)\n", score2, score1);
    }
}

int compute_score(char *word){
    int score = 0;

    for (int i = 0; i < strlen(word); i++){
        if (isalpha(word[i])){
            score += POINTS[toupper(word[i]) - 'A'];
        }
    }
    return score;
}
