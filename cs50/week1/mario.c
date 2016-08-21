#include <cs50.h>
#include <stdio.h>

int getHeight()
{
    int height = 25;
    while (height < 0 || height > 23)
    {
        printf("Height: ");
        height = GetInt();
    }
    return height;
}

void mPrint(int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}

void printPyramids(int height)
{
    for (int i = 1; i <= height; i++)
    {
        mPrint(height-i, ' ');
        mPrint(i, '#');
        printf("  ");
        mPrint(i, '#');
        printf("\n");
    }
}

int main(void)
{
    int height = getHeight();
    printPyramids(height);
}