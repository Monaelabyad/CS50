#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    char words[25];
    int n = strlen(word);
    int j = 0;
    //assign alphabets to an array
    for (int i = 0 ; i < 26 ; i++)
    {
        words[i] = (int) 'A' + j;
        j++;
    }
    // convert all letters to upper case
    for (int x = 0 ; x < n; x++)
    {
        word[x] = toupper(word[x]);
    }
    int s = 0;
    //check every char and compute points
    for (int k = 0 ; k < n ; k++)
    {
        for (int y = 0 ; y < 26 ; y++)
        {
            if (word[k] == words[y])
            {
                s = s + POINTS[y];
            }
            else
            {
                s = s + 0;
            }
        }
    }
    return s;

}
