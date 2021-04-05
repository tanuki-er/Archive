#include <stdio.h>
#include <stdlib.h>
int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

 
int main()
{
    FILE *input, *output;
    int w, h, i, j;
    input = fopen("turtle.in", "r");
    fscanf(input, "%d %d", &h, &w);
    int array1[h][w], array2[h][w];
    for(i = (h - 1); i >= 0; i--)
    {
        for(j = 0; j < w; j++)
        {
            fscanf(input, "%d", &array1[i][j]);
        }
    }
    fclose(input);
    array2[0][0] = array1[0][0];
    for(i = 1; i < h; i++)
    {
        array2[i][0] = array1[i][0] + array2[i - 1][0];
    }
    for(j = 1; j < w; j++)
    {
        array2[0][j] = array1[0][j] + array2[0][j - 1];
    }
    for(i = 1; i < h; i++)
    {
        for (j = 1; j < w; j++)
        {
            array2[i][j] = max(array2[i - 1][j], array2[i][j - 1]) + array1[i][j];
        }
    }
    output = fopen("turtle.out", "w");
    fprintf(output, "%d", array2[h - 1][w - 1]);
    fclose(output);
    return 0;
}
