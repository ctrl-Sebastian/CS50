#include <cs50.h> //include the cs50 library to use get_
#include <stdio.h>

int main(void)
{
    // get the name as an answer and assign it to the variable name
    string name = get_string("What's your name? ");

    //print hello, leave a space for the string variable name and print the answer
    printf("hello, %s\n", name);
}