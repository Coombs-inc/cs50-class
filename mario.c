#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Main Key
    int n, i, b, s;
    do
    {
        n = get_int("positive number: ");
    }
    while (n < 1 || n > 8);

    //pyramid row
    for (i = 0; i < n; i++)
    {
        //spacebar to change alignment
        for (s = 0; s < n - i - 1; s++)
        {
            printf(" ");
        }

        //pyramid column
        for (b = 0; b <= i; b++)
        {
            //print brick
            printf("#");
        }
        //move to next row
        printf("\n");
    }
}