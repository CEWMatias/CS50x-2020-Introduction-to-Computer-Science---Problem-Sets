#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int height, row, column, space; //define height, row, column, space...

    do
    {
        height = get_int("Hight: ");
    }
    while (height < 1 || height > 8); // while height < 1 or height > 8 start loop...
    // define the height range..
    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space ++)
        {
            //blankspeace
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            //hashtag #
            printf("#");
        }
        //blankspeace
        printf("  ");
        for (column = 0; column <= row; column++)
        {
            //hashtag #
            printf("#");
        }
        printf("\n");
    }
}
