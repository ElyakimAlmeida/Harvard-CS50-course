#include <stdio.h>

// Function declaration
void userInput();
int totalCoins;         // Variable to store the total number of coins used
int valueInCents;       // Value in cents (integer)

// Main function
int main()
{
    totalCoins = 0;       // Initialize the total coins counter to 0
    userInput();          // Get user input for the cash value

    // Define the value of each coin in cents
    int quarter = 25;     // 25 cents
    int dime = 10;        // 10 cents
    int nickel = 5;       // 5 cents
    int penny = 1;        // 1 cent

    // While there is still some value left to be converted to coins
    while (valueInCents > 0)
    {
        if (valueInCents >= quarter)  // If the value is greater than or equal to a quarter (25 cents)
        {
            valueInCents -= quarter;  // Subtract the quarter's value from the remaining value
            totalCoins++;             // Increase the coin count
        }
        else if (valueInCents >= dime)  // If the value is greater than or equal to a dime (10 cents)
        {
            valueInCents -= dime;     // Subtract the dime's value
            totalCoins++;             // Increase the coin count
        }
        else if (valueInCents >= nickel)  // If the value is greater than or equal to a nickel (5 cents)
        {
            valueInCents -= nickel;    // Subtract the nickel's value
            totalCoins++;              // Increase the coin count
        }
        else if (valueInCents >= penny)  // If the value is greater than or equal to a penny (1 cent)
        {
            valueInCents -= penny;     // Subtract the penny's value
            totalCoins++;              // Increase the coin count
        }
    }

    // Output the total number of coins used
    printf("Total coins used for the change: %i\n", totalCoins);
}

// Function to handle user input
void userInput()
{
    // Repeat until a valid positive value is entered
    do
    {
        // Ask the user for the cash value they want to calculate
        float value =scanf("Enter your cash value to be calculated: \n");
        
        // Convert the float value into cents and store it in the integer variable (valueInCents)
        valueInCents = (int)(value * 100);  // Multiply by 100 to convert dollars to cents
    }
    // Ensure the value entered is positive
    while (valueInCents <= 0);  
}
