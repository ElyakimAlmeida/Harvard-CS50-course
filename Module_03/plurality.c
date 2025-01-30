#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[100]; // Using fixed-size char array instead of string (char pointer)
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        // Copy candidate names into the candidates array
        strncpy(candidates[i].name, argv[i + 1], sizeof(candidates[i].name) - 1);
        candidates[i].name[sizeof(candidates[i].name) - 1] = '\0'; // Ensure null termination
        candidates[i].votes = 0;
    }

    // Get the number of voters
    int voter_count;
    printf("Number of voters: ");
    if (scanf("%d", &voter_count) != 1)
    {
        printf("Invalid input for number of voters.\n");
        return 3;
    }

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        printf("Candidates Available are: ");
        for (int j = 0; j < candidate_count; j++)
        {
            printf("  %s", candidates[j].name);
            if (j < candidate_count - 1)
            {
                printf(", ");
            }
        }
        printf("\n");

        // Get the name of the voted candidate
        char name[100];  // Temporary buffer for storing the vote
        printf("\nType in the name of your candidate to vote: ");
        scanf(" %[^\n]%*c", name);  // Read input with spaces

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
    // Compare the vote to the candidate names
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("The Elections winner is ||%s|| \n", candidates[i].name);
        }
    }
}
