#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //asking for name
    string name = get_string("what is your name?\n");
    printf("Hello, %s\n", name);
}