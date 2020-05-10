#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = (int)roundf(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = (int)roundf(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3.0);
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = (int)roundf(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = (int)roundf(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = (int)roundf(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}

// helper for Reflect function
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

// helpers for Blur function

void subcolor_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_offset)
{
    float count = 0;
    float sum = 0;

    for (int m = -1; m <= 1; m++)
    {
        for (int n = -1; n <= 1; n++)
        {
            if (i + m >= 0 && i + m < height && j + n >= 0 && j + n < width)
            {
                sum = sum + *(&(image[i + m][j + n].rgbtBlue) + color_offset);
                count++;
            }
        }
    }
    float avg = sum / count;
    *(&(image[i][j].rgbtBlue) + color_offset) = (int)roundf(avg);
}

void box_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    subcolor_blur(i, j, height, width, image, 0); // blue blur (color_offset=0)
    subcolor_blur(i, j, height, width, image, 1); // green blur (color_offset=1)
    subcolor_blur(i, j, height, width, image, 2); // red blur  (color_offset=2)
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            box_blur(i, j, height, width, image);
        }
    }
}
