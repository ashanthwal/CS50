#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
bool is_valid_key(string s);
void encrypt(string plaintext, string ciphertext, int k);
int main(int argc, string argv[])
{
    string plaintext;
    int k;
    //check args and validate
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    //convert the string argv to int
    k = atoi(argv[1]);
    plaintext = get_string("plaintext:");
    int n = strlen(plaintext);
    char ciphertext[n + 1];
    encrypt(plaintext, ciphertext, k);
    printf("ciphertext:%s\n", ciphertext);
    return 0;
}
// Function for key validation
bool is_valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        char c = s[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
// function to encrypt plaintext
void encrypt(string plaintext, string ciphertext, int k)
{
    int i;
    for (i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        
        if (isalpha(c))
        {
            char temp = tolower(c);
            int pi = temp - 'a';
            char ci = ((pi + k) % 26) + 'a';
            ciphertext[i] = islower(c) ? ci : toupper(ci);
        }
        else
        {
            ciphertext[i] = c;
        }
    }
    ciphertext[i] = '\0';
}
