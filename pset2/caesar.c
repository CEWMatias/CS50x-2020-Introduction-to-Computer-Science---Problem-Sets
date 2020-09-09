#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

bool check_validkey(string s);

// define int argc, string argv[]
int main(int argc, string argv[])
{
    if (argc != 2 || !check_validkey(argv[1])) // if argc !=2 || !(argv[i]);
    {
        printf("Usage: ./caesar key"); // printf Usage : ./caesar key then return 1;
        return 1;
    }
    int key = atoi(argv[1]); //the program might work if the user provides a key of "13" -> 13

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool check_validkey(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))
        {
            return false;
        }
    return true;
}
