#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //i declare the variable height to get the height of the pyramid from the user
    int height;

    //keep asking the value of height while the number on the input is less than 1 or higher than 8
    do{
        height = get_int ("Height: ");

    }while (height < 1 || height > 8);

    //while i is less then the value of height, increase i and repeat the for loop from the inside until 'i' cannot increase more
    for(int i = 0; i < height; i++){

        //in each row created by opening a new line, while the value of spaces is less than the height - i -1
        //prints a blank space with: " ", at the beginning, height will be a n number and i is going to be 0
        //so it's going to print height-1 number of spaces and then the respective dash "#"

        for(int spaces = 0; spaces < height - i -1; spaces++){
            printf(" ");
        }

        // the j prints dashes while its value is minor or equal to i, so if height is 1, just prints 1 dash
        //because it won't surpass the value of 1, if its 8, its going to put a dash in every row of hthe pyramid
        //relative to the value of i.
        
        for(int j = 0; j <= i; j++){
            printf("#");
        }

        //this is what creates the rows, by opening a new line
        printf("\n");
    }
}