#include <stdio.h>
#include <ctype.h>
#include <string.h>

int scorecalc(char *word);
char letters[] = "abcdefghijklmnopqrstuvwxyz";
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    int word1_points = 0;
    int word2_points = 0;
    char word1[100]; // assuming max length of 100 characters
    char word2[100]; // assuming max length of 100 characters

    printf("Player 1, please enter your word: ");
    scanf("%s", word1);
    word1_points = scorecalc(word1);

    printf("Player 2, please enter your word: ");
    scanf("%s", word2);
    word2_points = scorecalc(word2);

    if (word1_points > word2_points)
    {
        printf("Player 1 wins with %i points\n", word1_points);
    }
    else
    {
        if (word1_points == word2_points)
        {
            printf("DRAW: PLAYER 1 points %i and PLAYER 2 points %i\n", word1_points, word2_points);
        }
        else
        {
            printf("Player 2 wins with %i points\n", word2_points);
        }
    }

    return 0;
}

int scorecalc(char *word)
{
    int score = 0;
    int size = strlen(word);
    for (int i = 0; i < size; i++)
    {
        word[i] = tolower(word[i]); // Convert to lowercase
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == letters[j])
            {
                score += POINTS[j];
            }
        }
    }
    return score;
}
