#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //i declare the variable height to get the height of the pyramid from the user
    int height;
    int dashes;
    int spaces;

    //keep asking the value of height while the number on the input is less than 1 or higher than 8
    do{
        height = get_int ("Height: ");

    }while (height < 1 || height > 8);

    for(int i = 0; i<= height; i++)
    {
        printf("#");
    }
    }