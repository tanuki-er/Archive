#include <stdio.h>
#include <stdlib.h>

struct people
{
    double salary;
    int amount;
};

int main()
{
    FILE *input, *output;
    int n, i, j;
    struct people copy;

    input = fopen("sortland.in", "r");

    fscanf(input, "%d", &n);

    struct people man[n];

    for(i = 0; i < n; i++)
    {
        fscanf(input, "%lf", &man[i].salary);
        man[i].amount = i + 1;
    }

    fclose(input);

    for(i = 0; i < (n - 1); i++)
    {
        for(j = (i + 1); j < n; j++)
        {
            if (man[i].salary > man[j].salary)
            {
                copy = man[i];
                man[i] = man[j];
                man[j] = copy;
            }
        }
    }

    output = fopen("sortland.out", "w");

    fprintf(output, "%d %d %d", man[0].amount, man[n / 2].amount, man[n - 1].amount);

    fclose(output);

    return 0;
}
