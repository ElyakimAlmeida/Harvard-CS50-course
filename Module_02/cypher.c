#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *cypher(char *text, int shift);

int main(void)
{
    // Ask the user to input the cipher key (shift number)
    int shift;
    printf("Enter the cipher key : ");
    
    // Read the user's input for the shift value
    if (scanf("%d", &shift) != 1)  // Check if the input is a valid integer
    {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }
  // Consume the newline character left by scanf
    getchar();

    // Get the text to cipher
    char text[100]; // Buffer size for input text
    printf("Type in your message to be cyphered: \n");
    
    // Use fgets to avoid buffer overflow, and read the message
    fgets(text, sizeof(text), stdin);

    // Remove the newline character left by fgets
    text[strcspn(text, "\n")] = '\0';

    // Cipher the text
    char *cypheredText = cypher(text, shift);
    printf("Cyphered text: %s \n", cypheredText);

    return 0;
  
}

char *cypher(char *text, int shift)
{
    static char cypheredText[100]; // Static buffer to hold the cyphered text
    int length = strlen(text);

    // Apply Caesar cipher with the given shift
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i])) // Only cipher alphabetic characters
        {
            char base = (isupper(text[i])) ? 'A' : 'a'; // Determine if letter is uppercase or lowercase
            cypheredText[i] = (text[i] - base + shift) % 26 + base; // Apply the shift
        }
        else
        {
            cypheredText[i] = text[i]; // Non-alphabetic characters remain the same
        }
    }

    cypheredText[length] = '\0'; // Null-terminate the string
    return cypheredText;
}
