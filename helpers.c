#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width; c++)
        {
            float average = (image[r][c].rgbtRed + image[r][c].rgbtBlue + image[r][c].rgbtGreen)/3.00;
            int avg = round(average);

            image[r][c].rgbtRed = avg;
            image[r][c].rgbtBlue = avg;
            image[r][c].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width; c++)
        {
            int sepiaRed = round(.393 * image[r][c].rgbtRed + .769 * image[r][c].rgbtGreen + .189 * image[r][c].rgbtBlue);
            int sepiaGreen = round(.349 * image[r][c].rgbtRed + .686 * image[r][c].rgbtGreen + .168 * image[r][c].rgbtBlue);
            int sepiaBlue = round(.272 * image[r][c].rgbtRed + .534 * image[r][c].rgbtGreen + .131 * image[r][c].rgbtBlue);

            image[r][c].rgbtRed = (sepiaRed > 255) ? 255: sepiaRed;
            image[r][c].rgbtBlue = (sepiaRed > 255) ? 255: sepiaBlue;
            image[r][c].rgbtGreen = (sepiaRed > 255) ? 255: sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width/2; c++)
        {
            int red = image[r][c].rgbtRed;
            int blue = image[r][c].rgbtBlue;
            int green = image[r][c].rgbtGreen;

            image[r][c].rgbtRed = image[r][width - c -1].rgbtRed;
            image[r][c].rgbtBlue = image[r][width - c -1].rgbtBlue;
            image[r][c].rgbtGreen = image[r][width - c -1].rgbtGreen;

            image[r][width - c -1].rgbtRed = red;
            image[r][width - c -1].rgbtBlue = blue;
            image[r][width - c -1].rgbtGreen = green;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width; c++)
        {
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            float counter = 0;

            for( int i = - 1; i < 2; i++)
            {
                for( int h = - 1; h < 2; h++)
                {
                    if( r + i < 0 || r + i > height - 1 ||r + c < 0 || r + c > width - 1)
                    {
                        continue;
                    }
                    sumRed += image[r+i][c+h].rgbtRed;
                    sumBlue += image[r+i][c+h].rgbtBlue;
                    sumGreen += image[r+i][c+h].rgbtGreen;

                    counter++;
                }
            }
            temp[r][c].rgbtRed = round(sumRed/counter);
            temp[r][c].rgbtBlue = round(sumBlue/counter);
            temp[r][c].rgbtGreen = round(sumGreen/counter);
        }
    }
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width; c++)
        {
            image[r][c].rgbtRed = temp[r][c].rgbtRed;
            image[r][c].rgbtBlue = temp[r][c].rgbtBlue;
            image[r][c].rgbtGreen = temp[r][c].rgbtGreen;
        }
    }
    return;
}
