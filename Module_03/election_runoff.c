#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is the jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, and elimination status
typedef struct
{
    char name[100];  // Make sure name can store strings of sufficient length
    int votes;
    int eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Number of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
int vote(int voter, int rank, char *name);
void tabulate(void);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = 0;
    }

    printf("Number of voters: ");
    if (scanf("%d", &voter_count) != 1 || voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[100];
            printf("Rank %i: ", j + 1);
            // Read the string for the vote
            if (fgets(name, sizeof(name), stdin) == NULL)
            {
                printf("Error reading vote input.\n");
                return 4;
            }
            name[strcspn(name, "\n")] = 0;  // Remove trailing newline character

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 5;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until a winner exists
    while (1)
    {
        // Calculate votes for remaining candidates
        tabulate();

        // Check if an election winner exists
        if (print_winner())
        {
            break;
        }

        // Eliminate the candidate with the least votes
        int min = find_min();
        if (is_tie(min))
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate the candidates with the minimum number of votes
        eliminate(min);

        // Reset the vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}
// Helper function to remove leading and trailing spaces
void trim_spaces(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    // Remove leading spaces
    while (str[start] == ' ' && start < end) start++;

    // Remove trailing spaces
    while (str[end] == ' ' && end > start) end--;

    // Set the new string length
    str[end + 1] = '\0';

    // Shift the string to the front
    for (int i = 0; i <= end; i++)
    {
        str[i] = str[start + i];
    }
}



// Record preference if the vote is valid
int vote(int voter, int rank, char *name)
{
       // Trim spaces from the input name
    trim_spaces(name);

    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            preferences[voter][j] = rank;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // For each voter
    for (int i = 0; i < voter_count; i++)
    {
        // Check the preferences of the voter
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j]; // Candidate index in the voter’s preference

            // If the candidate is not eliminated, count a vote for them
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break; // Stop checking further, count only the first valid preference
            }
        }
    }
}

// Print the winner of the election, if there is one
int print_winner(void)
{
    // The number of votes needed to win
    int majority = voter_count / 2;

    // Check if any candidate has more than half of the votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return 1; // Winner found
        }
    }

    return 0; // No winner yet
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = 1000000; // Initialize with a large number (to ensure the first value will be smaller)

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes; // Update the minimum
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min)
{
    // Check if all non-eliminated candidates have the same number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return 0; // If any candidate doesn't have the minimum number of votes, it's not a tie
        }
    }
    return 1;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Eliminate the candidates with the minimum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = 1;
        }
    }
}
