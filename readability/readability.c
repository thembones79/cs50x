#include <stdio.h>
#include <cs50.h>
#include <math.h>

void get_grade(string text);

int main(void)
{
    string text = get_string("Text: ");
    get_grade(text);
}

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0; text[i] != 0; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int counter = 1;
    for (int i = 0; text[i] != 0; i++)
    {
        if (text[i] == 32)
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;
    for (int i = 0; text[i] != 0; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            counter++;
        }
    }
    return counter;
}

float coleman_liau_index(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = 100 * (float) letters / (float) words;
    float S = 100 * (float) sentences / (float) words;

    return 0.0588 * L - 0.296 * S - 15.8;
}

void get_grade(string text)
{
    float index = coleman_liau_index(text);
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
        int grade = (int) roundf(index);
        printf("Grade %i\n", grade);
    }
}