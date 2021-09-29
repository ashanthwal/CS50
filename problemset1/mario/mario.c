#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get user input
    string name = get_string("What is your name?\n");
    //print with user input
    printf("Hello, %s\n", name);
}