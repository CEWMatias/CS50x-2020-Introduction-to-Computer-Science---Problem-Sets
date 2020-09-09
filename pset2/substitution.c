#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
bool is_validkey(string s);

int main(int argc, string argv[])
{
    if (argc != 2)  // if argc != 2 then retrun 1 for loop;
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!is_validkey(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
// define string s = get_string("plaintext: ");

    string s = get_string("plaintext: ");
    string difference = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
    {
        difference[i - 'A'] = toupper(difference[i - 'A']) - i; //'J' - 'A';
    }
    printf("ciphertext: ");

    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            s[i] = s[i] + difference[s[i] - (isupper(s[i]) ? 'A' : 'a')]; // s[i] -> 'J' + difference
        }
        printf("%c", s[i]);
    }
    printf("\n");
}

bool is_validkey(string s)
{
    int len = strlen(s);
    if (len != 26)
    {
        return false;
    }

    int freq[26] = { 0 };
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
        int index = toupper(s[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }

    return true;
}
