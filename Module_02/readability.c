#include <stdio.h>
#include <ctype.h>
#include <string.h>

int coleman_calc(int l, int s);

int main(void)
{
    int w = 0;  // number of words
    int l = 0;  // number of letters
    int s = 0;  // number of sentences
    int length = 0;
    char text[1000];  // Buffer to store the text 

    printf("Please type in your text: \n");
    fgets(text, sizeof(text), stdin);  // Read a line of input from the user

    length = strlen(text);
    
    // Loop through each character in the string
    for (int i = 0; i < length; i++) {
        if (text[i] == ' ') {
            w++;  // Count spaces to determine word boundaries
        } else if (text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?') {
            s++;  // Count sentence-ending punctuation
        } else if (isalpha(text[i])) {
            l++;  // Count letters (only alphabetic characters)
        }
    }

    // Output the counts
    printf("You typed %i words, %i sentences, and %i letters.\n", w + 1, s, l);

    // Calculate the Coleman-Liau index (grade level)
    int index = coleman_calc(l, s);
    printf("Your grade is %i.\n", index);

    return 0;
    
}

// Function to calculate Coleman-Liau index
int coleman_calc(int l, int s)
{
    float index = 0.0588 * l - 0.296 * s - 15.8;
    return (int)(index);  // Cast the result to an integer (rounding down)
}
