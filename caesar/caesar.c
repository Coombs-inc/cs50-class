#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    //arguement
    if (argc == 2)
    {
        int k = atoi(argv[1]);
        bool valid_key = false;

        for (int i = 0; i <strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
                valid_key = true;

                else
                {
                    printf("usage: ./caesar key\n");
                    return 1;
                }
           }

    }

    //define key
    int key = atoi(argv[1]);

    string plaintext = get_string ("plaintext: ");
    printf("ciphertext: ");

    for ( int i = 0; i <strlen(plaintext); i++)
    {
        if(isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65 ) + key ) % 26 ) + 65);
        }

        else if(islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97 ) + key ) % 26 ) + 97);
        }

        else
        {
            printf("usage: ./caesar key\n");
            return 1;
        }

    }
    printf("\n");
}