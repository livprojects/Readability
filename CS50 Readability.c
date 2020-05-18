#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main (void)
{

    string text = get_string("Text: ");

    // Declaring my variables//

    float letters = 0;
    float words = 1;
    float sentences = 0;

    //Let's see what's inside this text//
    for (int i = 0; i < strlen(text); i++)
    {
        //Count the letters//
        if (isalpha(text[i]) != 0)
            {
            letters++;
            }
        //Count the words//
        else if (isgraph(text[i]) == 0)
            {
            words++;
            }
        //Count the sentences//
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
            sentences++;
            }

    }
       //Checking what's going on here//
        printf("Letters: %.0f\nWords: %.0f\nSentences: %.0f\n", letters, words, sentences);

        //Finding what reading level is appropriate - formula//


    float L = letters * 100 / words;
    float s = sentences *100 / words;
    
    float grade = 0.0588 * L - 0.296 * s - 15.8;


    //Gives grade level//

    if (grade < 16 && grade >= 1)

    {
        printf("Grade %i\n", (int) round(grade));
    }

  
    else if (grade >= 16)
    {
        printf("Grade: 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");

    }
}
