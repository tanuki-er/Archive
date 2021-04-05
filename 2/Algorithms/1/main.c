#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input, *output;
    int n, i, j;
    long long int copy;

    input = fopen("smallsort.in", "r");
    output = fopen("smallsort.out", "w");
    fscanf(input, "%d\n", &n);

    long long int a[n];

    for(i = 0; i < n; i++)
    {
        fscanf(input, "%lld ", &a[i]);
    }
    for(i = 0; i < (n - 1); i++)
    {
        for(j = (i + 1); j < n; j++)
        {
            if (a[j] < a[i])
            {
                copy = a[j];
                a[j] = a[i];
                a[i] = copy;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        fprintf(output, "%lld ", a[i]);
    }

    fclose(input);
    fclose(output);
    return 0;
}
