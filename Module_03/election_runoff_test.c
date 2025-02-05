#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Declare the functions and the candidate struct from election_runoff.c
extern bool vote(int voter, int rank, char *name);
extern void tabulate(void);
extern bool print_winner(void);
extern int find_min(void);
extern bool is_tie(int min);
extern void eliminate(int min);

// Define the candidate struct
typedef struct
{
    char *name;
    int votes;
    bool eliminated;
} candidate;

// Number of voters and candidates
extern int voter_count;
extern int candidate_count;

// Test function to generate all permutations of the votes
void generate_permutations(void)
{
    // Example: 3 candidates and 4 voters
    candidate_count = 4;
    voter_count = 3;

    // Sample candidates
    candidate candidates[] = {
        {"Trump", 0, false},
        {"Obama", 0, false},
        {"Dilma", 0, false},
        {"Lula", 0, false}
    };

    // Example preferences (votes)
    int preferences[3][4] = {
        {0, 1, 2, 3}, // Voter 1's preferences
        {1, 0, 2, 3}, // Voter 2's preferences
        {3, 1, 0, 2}  // Voter 3's preferences
    };

    // Now simulate calling the election functions
    // Call your election logic here
    tabulate();
    bool won = print_winner();
    if (!won)
    {
        int min = find_min();
        bool tie = is_tie(min);
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
        }
        else
        {
            eliminate(min);
        }
    }
}

int main(int argc, char *argv[])
{
    // Example: Call the test function with the candidates' names from argv
    generate_permutations();

    return 0;
}
