#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, int first, int last)
{
    if (first == last)
    {
    return;
    }
    int middle = (first + last) / 2;

    merge_sort(array, first, middle);
    merge_sort(array, (middle + 1), last);

    int step, i, j;
    int copy[last];

    i = first;
    j = middle + 1;

    for(step = 0; step < (last - first + 1); step++)
    {
        if ((j > last) || ((i <= middle) && (array[i] < array[j])))
        {
            copy[step] = array[i];
            i++;
        }
        else
        {
            copy[step] = array[j];
            j++;
        }
    }

    for(step = 0; step < (last - first + 1); step++)
    {
        array[first + step] = copy[step];
    }
}

int main()
{
    FILE *input, *output;
    int i, size;

    input = fopen("sort.in", "r");
    fscanf(input, "%d", &size);

    int array[size];

    for (i = 0; i < size; i++)
    {
        fscanf(input, "%d", &array[i]);
    }
    fclose(input);

    merge_sort(array, 0, (size - 1));

    output = fopen("sort.out", "w");
    for(i = 0; i < size; i++)
    {
        fprintf(output, "%d ", array[i]);
    }
    fclose(output);

    return 0;
}
