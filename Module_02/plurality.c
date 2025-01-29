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
    

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
  
}

// Print the winner (or winners) of the election
void print_winner(void)
{
   
}
