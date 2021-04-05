#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input, *output;
    int a, b;

    input = fopen("aplusb.in", "r");
    output = fopen("aplusb.out", "w");

    fscanf(input, "%d %d", &a, &b);

    fprintf(output, "%d", (a + b));

    fclose(input);
    fclose(output);

    return 0;
}
