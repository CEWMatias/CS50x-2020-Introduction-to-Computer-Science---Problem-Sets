#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp[height][width];

    // Transformations to temp
    // 1 2 3 4 -> 4 3 2 1
    // 4 5 6 7

    // Copy to final image
    for (int i = 0; i < height; i++)
    {
        int curPos = 0;
        for (int j = width - 1; j >= 0; j--, curPos++)
        {
            temp[i][curPos] = image[i][j];
        }
    }

    // Copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];


    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0;
            int rowCoords[] = { row - 1, row, row + 1 };
            int colCoords[] =  {col - 1, col, col + 1 };
            float totalR = 0, totalG = 0, totalB = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];
                        totalR += pixel.rgbtRed;
                        totalG += pixel.rgbtGreen;
                        totalB += pixel.rgbtBlue;
                        count++;
                    }
                }
            }

            // Have examined all the neightboring cells
            temp[row][col].rgbtRed = round(totalR / count);
            temp[row][col].rgbtGreen = round(totalG / count);
            temp[row][col].rgbtBlue = round(totalB / count);
        }
    }

    // Copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    //Apply the edge detection algorithm.

    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1},
    };

    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0;
            int rowCoords[] = { row - 1, row, row + 1 };
            int colCoords[] = {col - 1, col, col + 1 };
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        RGBTRIPLE pixel = image[curRow][curCol];

                        Gx_red += Gx[r][c] * pixel.rgbtRed;
                        Gx_green += Gx[r][c] * pixel.rgbtGreen;
                        Gx_blue += Gx[r][c] * pixel.rgbtBlue;

                        Gy_red += Gy[r][c] * pixel.rgbtRed;
                        Gy_green += Gy[r][c] * pixel.rgbtGreen;
                        Gy_blue += Gy[r][c] * pixel.rgbtBlue;

                    }
                }

                // Now apply the sqrt function to the Gx and Gy

                int fianlRed = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
                int fianlGreen = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
                int fianlBlue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

                temp[row][col].rgbtRed = fianlRed > 255 ? 255 : fianlRed;
                temp[row][col].rgbtGreen = fianlGreen > 255 ? 255 : fianlGreen;
                temp[row][col].rgbtBlue = fianlBlue > 255 ? 255 : fianlBlue;

            }
        }
    }
    // Copy to final image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
