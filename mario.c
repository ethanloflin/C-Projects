#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get positive integer from user
    int width;
    do
    {
        width = get_int("Width: ");
    }
    while (width < 1 || width > 20);
    
    //Print out this many hashes
    for (int row = 0; row < width; row++)
    //Nested loop, 
    {
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
    

}
