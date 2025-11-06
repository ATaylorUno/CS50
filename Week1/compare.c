#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int y = get_int("What's y? ");
    int x = get_int("What's x? ");

    if(x < y)
    {
        printf("x is less than y\n");
    }
    else if(x > y)
    {
        printf("y is less than x\n");
    }
    else
    {
        printf("y is equal to x\n");
    }
}
