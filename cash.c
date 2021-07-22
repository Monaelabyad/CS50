#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompting for input
    float dollars;
    do
    {
        dollars = get_float("Change owed? ");

    }
    while (dollars < 0);
    //convert dollars into cents
    int cents = round(dollars * 100);
    int coins = 0;
    //check numbers of quarter
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    //check numbers of dimes
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    //check numbers of nickels
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    //check numbers of pennies
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    //print number of coins
    printf("%i \n", coins);
}
