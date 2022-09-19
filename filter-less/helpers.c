#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j< width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int average = round((red + blue + green)/3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j< width; j++)
        {
            float sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            float sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j< width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy the image to a temporary new image to cahnge the value of each pixel and then bring it back to the original
    //this by looping inside the image for each pixel
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j< width/2; j++)
        {
            temp[i][j] = image [i][j];

        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j< width; j++)
        {
            //defining the variables for the total reds, greens and blues of the pixel sorounding the pixel we are on.
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            //each time theres a neighbour pixel counter will increase to make the average
            float counter = 0.00;

            for(int x = -1; x<2; x++)
            {
                for(int y = -1; y< 2 ; y++)
                {
                    //go around the pixel selected to count how many there are and sum up each of the rgb of them
                    int currentX = i +x;
                    int currentY = j +y;

                    if(currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (height - 1))
                    {
                        continue;
                    }
                    //suming up the totalRed, Green and Blue with each one of the Reds, Greens
                    //and Blues from the neighbouring pixels
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    counter++;
                }
                //makes the average of red, green and blue with their totals divided by
                //the counter wich by know is equals to the size of pixels found near the selected pixel
                temp[i][j].rgbtRed = round(totalRed/counter);
                temp[i][j].rgbtGreen = round(totalGreen/counter);
                temp[i][j].rgbtBlue = round(totalBlue/counter);
            }
        }
    }
    //Copies each of the pixels from the copy image at the start to every pixel of the original image
    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j< width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
