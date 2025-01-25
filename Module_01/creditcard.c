#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for isdigit() function
#include <stdlib.h> // for malloc() if needed

// Function declarations
int validation(const char* creditcard, int length);
const char* brandcheck(const char* creditcard);

// Main function
int main(void)
{
    // Prompt for the user's credit card number
    char creditcard[20];  // Buffer to store the credit card number (ensure sufficient space)
    printf("Please, type in your credit card number: \n");
    if (scanf("%19s", creditcard) != 1) {
        printf("Invalid input\n");
        return 1; // Exit on invalid input
    }
    
    int length = strlen(creditcard); // Get the length of the credit card number

    // Validate the credit card number
    if (validation(creditcard, length) != 1) {
        printf("Your credit card is invalid\n"); // Invalid card
    }
    else {
        // Determine the brand of the credit card
        const char* brand = brandcheck(creditcard);
        printf("Your credit card is valid and its brand is %s\n", brand); // Print the brand
    }

    return 0;
}

// Function to validate the credit card number
int validation(const char* creditcard, int length)
{
    // Check if the length of the card is between 13 and 16 digits
    if (length < 13 || length > 16) {
        return 0; // Invalid length
    }

    // Check if all characters are digits
    for (int i = 0; i < length; i++) {
        if (!isdigit(creditcard[i])) {
            printf("Please, type in only numbers\n");
            return 0; // Invalid character
        }
    }

    return 1; // Valid length and all digits are valid
}

// Function to check the credit card brand
const char* brandcheck(const char* creditcard)
{
    // Get the first two digits of the credit card
    int first_two_digits = (creditcard[0] - '0') * 10 + (creditcard[1] - '0');
    
    // Check if it's American Express (starts with 34 or 37)
    if (first_two_digits == 34 || first_two_digits == 37) {
        return "American Express";
    }
    // Check if it's MasterCard (starts with 51-55)
    else if (first_two_digits >= 51 && first_two_digits <= 55) {
        return "MasterCard";
    }
    // Check if it's Visa (starts with 4)
    else if (creditcard[0] == '4') {
        return "Visa";
    }
    
    // If not recognized, return a default message
    return "a not recognized one (we apologize but your credit card brand isn't in our databases)";
}
