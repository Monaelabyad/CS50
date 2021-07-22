#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

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
bool vote(string name)
{
    // TODO
    for (int v = 0; v < candidate_count ; v++)
    {
        if (strcmp(candidates[v].name, name) == 0)
        {
            candidates[v].votes += 1;
            return true;
        }
    }
    return false;
}
//MERGE SORT
void merge(int arr[], int l, int m, int r)
{
    //merge two subarrayes of arr[]
    //first subarray is arr[l..m]
    //second subarray is arr[m+1...r]
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    //creat temp arrays
    int L[n1], R[n2];
    
    //copy datato temp arrayes L[] and R[]
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    //merge the temp arrays back into arr[l..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //if there are remaining numbers at R[] put them an the array
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    //if there are remaining numbers at l[] put them an the array
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //substract array of votes from struct
    int candidates_votes[candidate_count];
    for (int x = 0; x < candidate_count; x++)
    {
        candidates_votes[x] = candidates[x].votes;
    }
    //sorting
    mergeSort(candidates_votes, 0, candidate_count - 1);
    //search for the name who has max votes
    
    for (int y = 0; y < candidate_count; y++)
    {
        if (candidates[y].votes == candidates_votes[candidate_count - 1])
        {
            printf("%s\n", candidates[y].name);
        }
    }
    return;
}
