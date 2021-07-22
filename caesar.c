#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check arguments number
    if (argc == 2)
    {
        //check if all characters is digits
        for (int i = 0, n = strlen(argv[1]) ; i < n ; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("usage: %s key\n", argv[0]);
                return 1;
            }
        }
        // convert key from string to number
        int key = atoi(argv[1]);
        //check if the number is positive
        if (key > 0)
        {
            //prompt plaintext from the user
            string plain = get_string("plaintext: ");
            int n = strlen(plain);
            printf("ciphertext: ");
            for (int j = 0; j < n ; j++)
            {
                //check if char is alpha
                if (isalpha(plain[j]))
                {
                    //check if char is upper
                    if (isupper(plain[j]))
                    {
                        char c = ((plain[j] - 'A') + key) % 26 + 'A';
                        printf("%c", c);
                    }
                    //check if char is lower
                    else if (islower(plain[j]))
                    {
                        char c = ((plain[j] - 'a') + key) % 26 + 'a';
                        printf("%c", c);
                    }
                }
                else
                {
                    printf("%c", plain[j]);
                }

            }
            printf("\n");
        }
        else
        {
            printf("usage: %s key\n", argv[0]);
            return 1;
        }
    }
    else
    {
        printf("usage: %s key\n", argv[0]);
        return 1;
    }
}
