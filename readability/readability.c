#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int num_letters(string);
int num_words(string);
int num_sentences(string);

float L;
float S;


int main(void)
{
    string text = get_string("text: ");
    float sentences = 0, letters = 0, words = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        if (isalpha(text[i]))
        {
            letters++;

            if (isspace(text[i + 1]) || ispunct(text[i + 1]) || text[i + 1] == '\0')
            {
                if (text[i + 1] != '\'' && text[i + 1] != '-')
                {
                    words++;
                }
            }
        }
        i++;
    }
    //Coleman-Liau index formula
    sentences *= 100 / words;
    letters *= 100 / words;
    float index = 0.0588 * letters - 0.296 * sentences - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}