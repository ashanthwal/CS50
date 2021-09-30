#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    int words = 1;
    int sentences = 0;
    //Prompt for text input
    string text = get_string("Text: ");
    // caclculate and print text length
    for (int i = 0, len = strlen(text); i <= len; i++)
    {
        char c = text[i];
        //check for letters
        if (isalpha(c))
        {
            count++;
        }
        //check for words
        if (isspace(c))
        {
            words++;
        }
        //check for sentences
        if (c == '.' || c == '?' || c == '!')
        {
            sentences++;
        }
    }

    //Calculating Coleman-Liau index

    float L = (count * 100.0f) / words;
    float S = (sentences * 100.0f) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //scoring based on the index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    //Test cases
    // printf("Letters: %i \n", count);
    // printf("Words: %i \n", words);
    // printf("Sentences: %i \n", sentences);
    // printf("Index: %i \n", index);

    return 0;
}