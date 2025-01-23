#include <stdio.h>

// Declare global variables
int years, popinit, popend;

// Function prototype for calculation
int calculation();

int main(void)
{
    // Prompt user for initial and end population sizes, ensure valid input
    do
    {
        printf("Enter population start size: ");
        if (scanf("%d", &popinit) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            return 1; // Exit if input is invalid
        }

        printf("Enter population end size: ");
        if (scanf("%d", &popend) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            return 1; // Exit if input is invalid
        }

    }
    while (popinit < 1 || popend < 1 || popinit >= popend); // Ensure valid population sizes

    // Call the calculation function to get the number of years
    years = calculation();

    // Output the result
    printf("It will take %i years to reach the desired population size\n", years);

    return 0;
}

// Function to calculate the number of years for population growth
int calculation()
{
    years = 0;

    // Loop until the population reaches or exceeds the desired population size
    while (popinit < popend)
    {
        // Calculate population gain and loss
        int gain = popinit / 3;
        int loss = popinit / 4;

        // Update the population
        popinit = popinit + gain - loss;

        // Increment the year count
        years++;
    }

    return years; // Return the calculated number of years
}
