#include <cs50.h>
#include <stdio.h>

int main(void)
{

  // Prompt user for number of blocks

    int blocks = get_int("Input number of blocks (between 1 - 8)");

    // Validate blocks

    while (blocks > 8 || blocks < 1)
    {

        blocks = get_int("Please select a number between 1 + 8");
    }

    // printf("You choose, %d\n", blocks);

    // Print the blocks

    for (int i = 0; i < blocks; i++)
    {

        for (int j = 0; j < blocks; j++)
        {

            if (i < j)
            {
                printf(" ");
            }
        }

        for (int l = 0; l < blocks; l++)
        {

            if (l <= i)
            {
                printf("#");
            }
        }

        printf("  ");

        for (int r = 0; r <= i; r++)
        {
            printf("#");
        }

        printf("\n");
    }
}
