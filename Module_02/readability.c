#include <stdio.h>
#include <ctype.h>
#include <string.h>

int coleman_calc(int l, int s, int w);

int main(void)
{
    int w = 0;  // Number of words
    int l = 0;  // Number of letters
    int s = 0;  // Number of sentences
    int length = 0;
    char text[1000];  // Buffer to store the text (adjust size as needed)

    printf("Please type in your text:\n");
    // Read a line of input from the user (including spaces)
    fgets(text, sizeof(text), stdin);

    // Remove newline character if fgets captures it
    text[strcspn(text, "\n")] = '\0';  // strcspn returns the index of the first occurrence of '\n'

    length = strlen(text);

    // Loop through each character in the string
    for (int i = 0; i < length; i++) {
        if (text[i] == ' ') {
            w++;  // Count spaces to determine word boundaries
        } else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            s++;  // Count sentence-ending punctuation
        } else if (isalpha(text[i])) {
            l++;  // Count letters (only alphabetic characters)
        }
    }

    // After the loop, the word count needs to account for the last word
    w++;

    // Output the counts
    printf("You typed %i words, %i sentences, and %i letters.\n", w, s, l);

    // Calculate the Coleman-Liau index (grade level)
    int index = coleman_calc(l, s, w);
    printf("Your grade is %i.\n", index);

    return 0;
}

// Function to calculate Coleman-Liau index
int coleman_calc(int l, int s, int w)
{
    float L = (float)l / w * 100;  // Average number of letters per 100 words
    float S = (float)s / w * 100;  // Average number of sentences per 100 words

    // Optionally print L and S values for debugging
    printf("L: %.4f and S: %.4f\n", L, S);

    // Calculate the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Return the grade level as an integer (rounded down)
    return (int)index;
}
