#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startPopulation;
    do
    {
        startPopulation = get_int("Enter starting llama population: ");
    } while (startPopulation < 9);

    // TODO: Prompt for end size
    int endPopulation;
    do
    {
        endPopulation = get_int("Enter ending llama population: ");
    } while (endPopulation < startPopulation);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (startPopulation < endPopulation)
    {
        startPopulation = startPopulation + (startPopulation / 3) - (startPopulation / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}