#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        // define dollars = get_float();
        dollars = get_float("change owed: ");
    }
    while (dollars < 0);
    // define cents, coins, denmination, size
    int cents = round(dollars * 100);
    int coins = 0;
    int denomination[] = {25, 10, 5, 1};
    int size = sizeof(denomination) / sizeof(int);
    for (int i = 0; i < size; i++) // for loop ( int i = 0; i < size; i++)
    {
        coins += cents / denomination[i];
        cents %= denomination[i];
    }

    printf("%i\n", coins); // print %i, coins;
}
